#include<iostream>
#include<vector>
#include<string>
using namespace std;
void CountWords(string buffer);
void PrintWords();
void RemoveAll();

struct WORD {
	string str; // �� �ܾ��� ����
	int count; // �� �ܾ��� ��� ��
};

vector<WORD*> words;

int main(void)
{
	cout << "���ڿ� �Է�. (����: Ctrl+Z)\n";

	string buffer;
	while (cin >> buffer)
	{
		CountWords(buffer); // �ܾ� ����, vector �ȿ� �ش� �ܾ �ִ��� �˻� ��
		// �ش� �ܾ �߰ߵǸ� �ش� �ܾ��� �󵵼��� 1�� ������Ŵ
		// �ܾ �߰ߵ��� ������ vector�� �ܾ� �߰� �� �󵵼� 1�� ����
	}
	PrintWords(); // �ܾ����
	RemoveAll();
	cout << "���� �Ǿ����ϴ�.\n";
	return 0;
}
void CountWords(string buffer)
{
	int i = 0;
	while (i < words.size())
	{
		if (buffer == words.at(i)->str)
		{
			words.at(i)->count = words.at(i)->count + 1;
			return;
		}
		i++;
	}
	WORD* newdata = new WORD[sizeof(WORD)];
	newdata->str = buffer;
	newdata->count = 1;
	words.push_back(newdata);
}
void PrintWords()
{
	int i = 0;
	while (i < words.size())
	{
		cout << "------------------------------------------\n";
		cout << words.at(i)->str << ": " << words.at(i)->count << "\n";
		cout << "------------------------------------------\n";
		i++;
	}
	return;
}

void RemoveAll()
{
	int i = 0;
	while (i < words.size())
	{
		delete words.at(i);
		i++;
	}
	return;
}