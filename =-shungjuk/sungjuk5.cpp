/**************************************************/
/*             HW#5 : 개선된 함수 기능                                                  */
/*  작성자 : 정재민                                날짜 : 2021년 4월 9일  */
/*                                                                                                     */
/* 문제 정의 : 다음의 기능을 수행하는 성적처리 프로그램 작성 (프로그램 명 : sungjuk5.cpp)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/


#include <iostream>
#include<string> 
#include <stdlib.h>
using namespace std;

inline void PrintMenu();

struct Subject {// 과목 정보 
    string SubName;        // 과목이름 
    int Hakjum;                   // 과목학점 
    string Grade;             // 과목등급 
    float GPA;                    // 과목 평점 
};

struct Student {// 학생 정보 
    string StdName; // 학생이름 
    int Hakbun; // 학번 
    Subject* Sub; // 과목 
    float AveGPA;   // 교과목 평균 평점 
    int Subnumber;//학생별 선택 과목수
};

void PrintMenu(); //menu출력함수
void CalcGPA(Subject& sub);// GPA를 계산해주는 함수
float CalcAveGPA(Subject* Sub, int Subnumber); //평균 GPA를 계산해주는 함수
void PrintAllData(const Student* rst, int StdNum); // 모든 데이터를 출력하는 함수
void PrintOneData(const Student& rst); // 하나의 데이터를 출력하는 함수
void PrintAllStdList(Student* pSt, int StudnetNum);
inline void InputValue(string &str);
inline void InputValue(int& i);
void ModifyStdInfo(Student* pSt);
Student* StdSearch(Student* rst, int Stdnum); //Stdsearch 구조체 선언
void InputData(Student* stu, int StudentNum);// 학생 정보를 입력해주는 함수

void line();//선 긋는 함수 선언
float number_grade(char grade); //각 grade를 점수로 바꿔 주는 함수








int main()
{
    PrintMenu();//인라인 함수 호출
    int number;
    int StdNum = 0;
    cout << "학생수를 입력하세요: ";  //학생수를 입력한다
    InputValue(StdNum);
    Student* st = new Student[StdNum]; //입력받은 학생 수 만큼 동적할당으로 구조체 배열을 만들어준다
    while (1) {

        cout << "\n원하는 기능을 입력하세요: ";
        InputValue(number);
        switch (number)// switch문을 통하여 메뉴 출력 경우의 수 나누기
        {

        case 1: //학생의 정보를 입력 받는 메뉴
        {

            InputData(st, StdNum); //학생 정보를 입력하는 함수 호출

            break;
        }
        case 2:// 전체 학생의 성적을 보는 메뉴
        {

            cout << "\n\n\n전체 학생 성적보기\n\n\n ";

            PrintAllData(st, StdNum); //모든 학생의 정보 출력하기

            break;

        }
        case 3: //특정 학생을 찾는 메뉴 출력
        {
            Student* SearchStd; // SearchStd 구조체 포인터 변수 
            SearchStd = StdSearch(st, StdNum);//특정학생을 찾는 함수 호출
            if (SearchStd != NULL)
                PrintOneData(*SearchStd);//무언가 정보가 있으면 학생정보 출력
            else
                cout << "\n에러입니다. 다시입력해주세요.\n";//정보 없으면 NULL 값을 반환 받고 오류 메시지 출력
            break;

        }
        case 4:
        {
            PrintAllStdList(st, StdNum);//전체 학생 목록보기 출력
            break;
        }
        case 5:
        {
            Student* SearchStd2; // SearchStd 구조체 포인터 변수 
            SearchStd2 = StdSearch(st, StdNum);//특정학생을 찾는 함수 호출을 하여 SearchStd2에 해당하는 학생 정보 주소 저장
            if (SearchStd2 != NULL)
            {
                ModifyStdInfo(SearchStd2); //학생정보를 수정하는 함수 호출
            }
            else //NULL값 반환시 오류 메시지 출력
            {
                cout << "\n에러입니다. 다시입력해주세요.\n";
            }
            break;
        }


        case 6: //강제 종료하기, 동적할당된 메모리 해제하기         
        {   cout << "메모리할당을 해제합니다";
        for (int i = 0; i < StdNum; i++) //학생 구조체 안에 있는 과목 구조체 메모리부터 해제
        {
            delete[](st + i)->Sub;
        }
        delete[] st; //학생 수만큼 받은 동적할당된 메모리 해제
        exit(0);
        break;

        }
        }

    }
}

void InputData(Student* stu, int StudentNum) //학생의 정보를 입력 받는함수
{
    for (int i = 0; i < StudentNum; i++) //학생수를 전달 받아 학생수 만큼 반복한다.
    {
        cout << "*" << i + 1 << " 번째 학생 이름과 학번을 입력하세요.\n";
        cout << "이름 : ";
        InputValue(stu[i].StdName); //동적할당으로 받은 구조체 배열에 학생이름 넣기
        cout << "학번: ";
        InputValue(stu[i].Hakbun);//동적할당으로 받은 구조체 배열에 학생 학번 넣기
        int Subnum = 0;
        cout << "수강한 과목 수를 입력 : "; //수강한 과목 수 입력
        InputValue(Subnum);
        (stu + i)->Sub = new Subject[Subnum]; // 각 학생별 구조체 배열 안에 과목 구조체배열을 입력받은 과목수로 동적배열을 통해 생성한다.
        (stu + i)->Subnumber = Subnum; // 전체 함수에 사용하기 위해 입력 받은 과목 수를 학생 구조체 Subnumber에 넣어준다
        cout << "*" << "수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
        for (int k = 0; k < Subnum; k++) //입력 받은 과목수 마다 반복하면서 정보를 입력 받는다
        {
            cout << "교과목명: ";
            InputValue(stu[i].Sub[k].SubName);
            cout << "과목학점: ";
            InputValue(stu[i].Sub[k].Hakjum);
            cout << "과목등급<A+ ~F>: ";
            InputValue(stu[i].Sub[k].Grade);
            cout << "\n\n";

        }
        for (int k = 0; k < Subnum; k++)//CalcGPA를 호출하여 각 학생의 각 과목별 GPA 계산하기
        {
            CalcGPA(stu[i].Sub[k]);
        }
    }

    for (int j = 0; j < StudentNum; j++) // 평균 학점 계산하기
    {
        stu[j].AveGPA = CalcAveGPA(stu[j].Sub, (stu + j)->Subnumber);

    }

}




inline void InputValue(string &str)//데이터를 입력 받는 함수 ,인라인함수 오버로딩
{
  
    getline(cin, str);
    
}

inline void InputValue(int& i)//데이터를 입력 받는 함수 ,인라인함수 오버로딩
{  
    cin >> i;
    cin.ignore();
}

void line()
{
    cout << "\n============================================\n";
}



inline void PrintMenu() //메뉴 출력함수 인라인 함수 
{
    cout << "-----------메뉴-------------\n" << "1. 학생 성적 입력\n" << "2. 전체 학생 성적 보기\n" << "3. 학생 이름 검색\n" << "4. 전체 학생 목록 보기\n" << "5. 학생 정버 수정\n" << "6. 프로그램 종료\n\n";


}

void PrintAllData(const Student* pst, int StudentNum)// 모든 학생 데이터를 출력하기, 매개변수 포인터 변수
{
    for (int i = 0; i < StudentNum; i++)
    {
        PrintOneData(pst[i]);//각 학생의 정보를 과목수 만큼 출력하기
    }

}

void PrintAllStdList(Student* pSt, int StudentNum)// 전체 학생이름과 학번을 출력하는 함수 
{
    line();
    cout.width(10);
    cout << "이름";
    cout.width(10);
    cout << "학번\n";
    line();
    for (int i = 0; i < StudentNum; i++) //학생수 만큼 학생이름, 학번 출력하기
    {
        cout.width(10);
        cout << pSt[i].StdName; // 이름 출력하기
        cout.width(10);
        cout << pSt[i].Hakbun;//학번 출력하기
        cout << "\n\n";
    }
    line();
}

float number_grade(string grade) //등급을 점수로 변환시켜 주는 함수
{

    if (grade== "A+" )
        return 4.50;

    else if (grade == "A0") 
        return 4.00;

    else if (grade == "B+")
        return 3.50;

    else if (grade == "B0")
        return 3.00;

    else if (grade == "C+")
        return 2.50;

    else if (grade == "C0")
        return 2.00;

    else if (grade == "D+")
        return 1.50;

    else if (grade == "D0")
        return 1.00;

    else if (grade == "F")
        return 0.00;


}





void CalcGPA(Subject& Sub) //GPA성적 계산하는 함수, &Sub는 레퍼런스 함수 이므로 값으로 전달 받는다. 
{

    float score = 0;
    score = number_grade(Sub.Grade); //등급을 점수화 시켜 score 변수에 저장한다.

    Sub.GPA = score * Sub.Hakjum; // Score*학점을 통해 GPA를 계산한다.
}

float CalcAveGPA(Subject* Sub, int Subnumber) /* 평균 GPA 계산하기,이때 매개변수 *Sub이므로 주소값으로 호출한다.
                                                    전체 학생 토탈 학점을 구하기 위해 Subnumber 값을 전달 받는다 */
{


    float AveGPA;
    float tGPA = 0;
    int tHakjum = 0;
    for (int j = 0; j < Subnumber; j++)// 과목 전체 수 만큼 반복
    {
        tGPA += Sub[j].GPA; // 각 과목 GPA 총 합 구하기 
    }
    for (int i = 0; i < Subnumber; i++) // 해당 학생 전체 학점 수 구하기
    {
        tHakjum += Sub[i].Hakjum;
    }
    return AveGPA = (float)tGPA / tHakjum; // 전체 GPA를 전체 학점수로 나누어 평균 GPA 구하기 
}


void PrintOneData(const Student& rst) // 한명의 학생 정보를 출력하는 함수, 매개변수를 레퍼런스 변수로 받으므로 값의 형태로 전달 받아야한다.
{


    line();

    cout.width(10);
    cout << rst.StdName; //해당 rst에 해당하는 이름 출력
    cout.width(10);
    cout << rst.Hakbun; //해당 rst에 해당하는 학번 출력
    line();
    cout.width(10);
    cout << "과목명";
    cout.width(10);
    cout << "과목학점";
    cout.width(10);
    cout << "과목등급";
    cout.width(10);
    cout << " 과목평점\n";
    for (int j = 0; j < rst.Subnumber; j++) // 학생이 들은 과목 정보 출력
    {
        cout.width(10);
        cout << rst.Sub[j].SubName;
        cout.width(10);
        cout << rst.Sub[j].Hakjum;
        cout.width(10);
        cout << rst.Sub[j].Grade;
        cout.width(10);
        cout << rst.Sub[j].GPA;
        cout << "\n";
    }

    line();

    cout << "\n";
    cout.width(30);
    cout << "평균평점";
    cout.width(10);
    cout.precision(2);
    cout << fixed;
    cout << rst.AveGPA; //rst에 해당하는 학생 평균 학점 출력하기
    cout << "\n\n\n\n";
}



Student* StdSearch(Student* rst, int StdNum) /*특정 학생을 찾는 함수, 매개변수가 구조체 포인터변수이므로 주소값으로 호출 받아야한다.
                                              학생수를 int StdNum으로 받는다*/
{
    string name;
    cout << "검색 할 학생 이름: ";
    InputValue(name);
    for (int i = 0; i < StdNum; i++)
    {
        if (name==rst[i].StdName) // 입력한 이름과 학생 이름이 같다면 해당 학생 구조체 주소 반환
            return &rst[i];
    }
    cout << "\n해당 학생이 없습니다.";//해당 이름이 없으면 오류 메시지를 출력하고 NULL값을 반환

    return NULL;

}







void ModifyStdInfo(Student* pSt)/*학생의 정보를 수정하는 함수,
원하는 학생정보를 Student* StdSearch(Student* rst)를 통해 찾아 포인터 변수 pst에 전달한다.*/
{

    cout << "<" << pSt->StdName << "," << pSt->Hakbun << ">" << "의 정보를 수정하세요 \n"; //수정하고 싶은 학생정보를 출력한다.
    cout << "이름: ";
    InputValue(pSt->StdName); //수정하고 싶은 학생의 이름으로 기존 이름 구조체 값을 새롭게 바꿔준다. 
    cout << "학번: ";
    InputValue(pSt->Hakbun); //수정하고 싶은 학생의 학번으로 기존 학번 구조체 값을 새롭게 바꿔준다. 
}
