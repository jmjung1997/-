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

vector<WORD*> words; //����ü WORD�� ������ �����ν� words�ν� ���� Ŭ������ �����Ѵ�. 

int main(void)
{
	cout << "���ڿ� �Է�. (����: Ctrl+Z)\n";

	string buffer; //string ��ü�� buffer ���� ����
	while (cin >> buffer)//buffer�� Ctrl+Z�� ���ö����� �Է� �޴´�
	{
		CountWords(buffer); // �ܾ� ����, vector �ȿ� �ش� �ܾ �ִ��� �˻� ��
		// �ش� �ܾ �߰ߵǸ� �ش� �ܾ��� �󵵼��� 1�� ������Ŵ
		// �ܾ �߰ߵ��� ������ vector�� �ܾ� �߰� �� �󵵼� 1�� ����
	}
	PrintWords(); // �ܾ����
	RemoveAll(); //�����Ҵ� ���� ���� ���ͷ� �Ҵ� ���� ������ �ʱ�ȭ ��Ų��.
	cout << "���� �Ǿ����ϴ�.\n";
	return 0;
}
void CountWords(string buffer) //�Է¹��� ���ڸ� vectorŬ������ ����ϰų� count�� ���� �Լ��̴�
{
	int i = 0;
	while (i < words.size())//words Ŭ������ �ִ� ������ ��ŭ �ݺ�
	{
		if (buffer == words.at(i)->str)//�Է¹��� buffer�� words.at(i)->str�� �ܾ ���ٸ�
		{
			words.at(i)->count = words.at(i)->count + 1;//words.at(i)->count�� ������ �Ѱ� �÷��ش�
			return;
		}
		i++;
	}//���� Ŭ������ ���� �ܾ���
	WORD* newdata = new WORD[sizeof(WORD)];//����ü ������ �����Ҵ� �޴´�
	newdata->str = buffer;//�Է¹��� ���� newdata->str�� �ִ´�
	newdata->count = 1;//������ �Ѱ��� �Ѵ�.
	words.push_back(newdata); //�����Ҵ� ���� �ּ� newdata�� words Ŭ������ �ִ´�
}
void PrintWords() // �ܾ ����ϴ� �Լ�
{
	int i = 0;
	while (i < words.size())//words ���� Ŭ���� �ȿ� �ִ� ����Ŀ ���� ��ŭ �ݺ��Ѵ�.
	{
		cout << "------------------------------------------\n";
		cout << words.at(i)->str << ": " << words.at(i)->count << "\n";//�ܾ�� �ݺ��� ������ ����Ѵ�
		cout << "------------------------------------------\n";
		i++;
	}
	return;
}

void RemoveAll()//��� �����͸� �����ϴ� �Լ�
{
	for (int i = 0; i < words.size(); i++)//�Է¹��� �����ͼ���ŭ �ݺ��ϸ鼭 words�ȿ� �ִ� �����Ҵ� ���� �ּҸ� �޸� ������Ų��
	{
		delete[] words[i];
	}

	vector<WORD*>().swap(words); //swap�� �̿��Ͽ� ����ִ� ����Ŭ������ �ٲ������ν� vectorŬ�������� �����Ҵ� ���� ���� ���� 0���� ������ش�.
	return;
}

