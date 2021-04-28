#include<iostream>
#include<vector>
#include<string>
using namespace std;
void CountWords(string buffer);
void PrintWords();
void RemoveAll();

struct WORD {
	string str; // 각 단어의 내용
	int count; // 각 단어의 사용 빈도
};

vector<WORD*> words;

int main(void)
{
	cout << "문자열 입력. (종료: Ctrl+Z)\n";

	string buffer;
	while (cin >> buffer)
	{
		CountWords(buffer); // 단어 세기, vector 안에 해당 단어가 있는지 검색 후
		// 해당 단어가 발견되면 해당 단어의 빈도수를 1씩 증가시킴
		// 단어가 발견되지 않으면 vector에 단어 추가 후 빈도수 1로 설정
	}
	PrintWords(); // 단어출력
	RemoveAll();
	cout << "종료 되었습니다.\n";
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