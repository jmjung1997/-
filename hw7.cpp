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

vector<WORD*> words; //구조체 WORD의 포인터 변수로써 words로써 백터 클래스를 생성한다. 

int main(void)
{
	cout << "문자열 입력. (종료: Ctrl+Z)\n";

	string buffer; //string 객체로 buffer 변수 생성
	while (cin >> buffer)//buffer에 Ctrl+Z가 나올때까지 입력 받는다
	{
		CountWords(buffer); // 단어 세기, vector 안에 해당 단어가 있는지 검색 후
		// 해당 단어가 발견되면 해당 단어의 빈도수를 1씩 증가시킴
		// 단어가 발견되지 않으면 vector에 단어 추가 후 빈도수 1로 설정
	}
	PrintWords(); // 단어출력
	RemoveAll(); //동적할당 받은 값과 벡터로 할당 받은 공간을 초기화 시킨다.
	cout << "종료 되었습니다.\n";
	return 0;
}
void CountWords(string buffer) //입력받은 문자를 vector클래스에 등록하거나 count를 세는 함수이다
{
	int i = 0;
	while (i < words.size())//words 클래스에 있는 데이터 만큼 반복
	{
		if (buffer == words.at(i)->str)//입력받은 buffer와 words.at(i)->str의 단어가 같다면
		{
			words.at(i)->count = words.at(i)->count + 1;//words.at(i)->count의 갯수를 한개 올려준다
			return;
		}
		i++;
	}//벡터 클래스에 없는 단어라면
	WORD* newdata = new WORD[sizeof(WORD)];//구조체 공간을 동적할당 받는다
	newdata->str = buffer;//입력받은 값을 newdata->str에 넣는다
	newdata->count = 1;//갯수를 한개로 한다.
	words.push_back(newdata); //동적할당 받은 주소 newdata를 words 클래스에 넣는다
}
void PrintWords() // 단어를 출력하는 함수
{
	int i = 0;
	while (i < words.size())//words 벡터 클래스 안에 있는 데이커 갯수 만큼 반복한다.
	{
		cout << "------------------------------------------\n";
		cout << words.at(i)->str << ": " << words.at(i)->count << "\n";//단어와 반복된 갯수를 출력한다
		cout << "------------------------------------------\n";
		i++;
	}
	return;
}

void RemoveAll()//모든 데이터를 제거하는 함수
{
	for (int i = 0; i < words.size(); i++)//입력받은 데이터수만큼 반복하면서 words안에 있는 동적할당 받은 주소를 메모리 해제시킨다
	{
		delete[] words[i];
	}

	vector<WORD*>().swap(words); //swap를 이용하여 비워있는 벡터클래스로 바꿔줌으로써 vector클래스에서 동적할당 받은 공간 또한 0으로 만들어준다.
	return;
}

