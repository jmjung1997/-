/**************************************************/
/*             HW#8 : 클래스 기초                                                */
/*  작성자 : 정재민                                날짜 : 2021년 5월 7일  */
/*                                                                                                     */
/* 문제 정의 : 다음의 기능을 수행하는 성적처리 프로그램 작성 (프로그램 명 : Student.cpp)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include"Subject.h"
#include"Student.h"

#include <iostream>
#include<string> 
#include <stdlib.h>

#include"InputUtil.h"
using namespace std;

void line();
Student::Student()//학생 클래스 안에 있는 초기화 함수
{
    m_StdName = " "; // 학생이름 
    m_Hakbun = 0; // 학번 
    m_Subnumber = 0;//학생별 선택 과목수
    m_Sub = NULL; // 과목 
    m_AveGPA = 0.0f;//평균 평점 초기화
}

Student::Student(string name, int Hakbun, int Subnum, Subject* sub)//학생 클래스 안에 매개변수가 있는 함수 
{
    m_StdName = name; // 학생이름 
    m_Hakbun = Hakbun; // 학번 
    m_Subnumber = Subnum;//학생별 선택 과목수
    m_Sub = new Subject[m_Subnumber];
    for (int i = 0; i < m_Subnumber; i++)
    {
        m_Sub[i] = sub[i];   //과목 옮김
    }
    CalcAveGPA(); //평균평점 구하는 함수
}

Student::Student(const Student& std)
{
    m_StdName = std.m_StdName; // 학생이름 
    m_Hakbun = std.m_Hakbun; // 학번 
    m_Subnumber =std.m_Subnumber;//학생별 선택 과목수
   
    m_Sub = new Subject[std.m_Subnumber];
    for (int i = 0; i < m_Subnumber; i++)
    {
        m_Sub[i] = std.m_Sub[i];   //과목 옮김
    }
    
    m_AveGPA = std.m_AveGPA;//평균 평점 초기화

}

Student::~Student()//소멸자 함수
{
    cout << m_StdName << "이 소멸되었습니다" << "\n";
    if (m_Sub)//동적할당된 과목정보 메모리 할당해제 하기
    {
        delete[] m_Sub;
        m_Sub = NULL;
    }
}



void Student::InputData() //학생 클래스 안 학생 정보를 입력 받는함수
{
    cout << "이름 : ";
    InputUtil::InputValue(m_StdName);//이름 넣기 
    cout << "학번: ";
    InputUtil::InputValue(m_Hakbun);//학번 넣기
    cout << "수강한 과목 수를 입력 : "; //수강한 과목 수 입력
    InputUtil::InputValue(m_Subnumber);
    m_Sub = new Subject[m_Subnumber]; // 각 학생별 객체 안에 과목 객체배열을 입력받은 과목수로 동적배열을 통해 생성한다.
    for (int i = 0; i < m_Subnumber; i++) //과목수 만큼 반복하면서 데이터 입력 받기
    {
        (m_Sub + i)->Subject::InputData();
    }
    CalcAveGPA(); //과목 평균 평점 계산하는 함수
}



void Student::CalcAveGPA() /* Student 클래스 안 평균 GPA 계산하는 함수 */
{
    float tGPA = 0;
    int tHakjum = 0;
    for (int j = 0; j < m_Subnumber; j++)// 과목 전체 수 만큼 반복
    {
        tGPA += (m_Sub + j)->GetGPA(); // 각 과목 GPA 총 합 구하기      
    }
    for (int i = 0; i < m_Subnumber; i++) // 해당 학생 전체 학점 수 구하기
    {
        tHakjum += (m_Sub + i)->GetHakjum();
    }
    m_AveGPA = (float)tGPA / tHakjum; // 전체 GPA를 전체 학점수로 나누어 평균 GPA 구하기 
}
void Student::printData()//Student 클래스 안에 학생정보 데이터를 출력하는 함수
{
    cout << "\n\n";
    cout.width(10);
    cout << m_StdName; //학생이름 출력
    cout.width(10);
    cout << m_Hakbun; //학번 출력

    m_Sub->Subject::printTitle(); //과목 타이틀 출력
    for (int i = 0; i < m_Subnumber; i++)//과목 정보 출력하기
    {
        (m_Sub + i)->Subject::printData();
    }
    line();
    cout << "\n";
    cout.width(30);
    cout << "평균평점";
    cout.width(10);
    cout.precision(2);
    cout << fixed;
    cout << m_AveGPA; //rst에 해당하는 학생 평균 학점 출력하기
    cout << "\n\n\n\n";
}

void Student::Modify()
{
    cout << "수정할 정보를 입력하세요: ";
    string menu;
    cin >> menu;
    cin.ignore();
    if (menu == "학생정보")//학생정보라고 할때
    {
        cout << "<" << m_StdName << " ," << m_Hakbun << ">" << "의 정보를 수정하세요 \n"; //수정하고 싶은 학생정보를 출력한다.
        cout << "이름: ";
        InputUtil::InputValue(m_StdName); //수정하고 싶은 학생의 이름으로 기존 이름값을 새롭게 바꿔준다. 
        cout << "학번: ";
        InputUtil::InputValue(m_Hakbun); //수정하고 싶은 학생의 학번으로 기존 학번값을 새롭게 바꿔준다. 
        CalcAveGPA();//과목 평균 평점을 계산해주는 함수
    }
    else if (menu == "과목정보")
    {
        Subject* SearchSub; // SearchSub의 포인터 변수
        string subname;
        InputUtil::InputValue(subname);
        SearchSub = SubSearch(subname);// 특정 과목을 찾는 함수 호출을 하여 SearchSub에 넣어준다.
        if (SearchSub != NULL)
        {
            SearchSub->Subject::Modify(); //과목정보를 수정하는 함수 호출
            CalcAveGPA();
        }
        else //과목정보에서 NULL값을 반환 받았을 때
        {
            cout << " 다시 입력해주세요.\n";
            Student::Modify();
        }

    }
    else if (menu == "모두")//모두라고 입력 받았을 때
    {
        cout << "<" << m_StdName << " ," << m_Hakbun << ">" << "의 정보를 수정하세요 \n"; //수정하고 싶은 학생정보를 출력한다.
        cout << "이름: ";
        InputUtil::InputValue(m_StdName); //수정하고 싶은 학생의 이름으로 기존 이름값을 새롭게 바꿔준다. 
        cout << "학번: ";
        InputUtil::InputValue(m_Hakbun); //수정하고 싶은 학생의 학번으로 기존 학번값을 새롭게 바꿔준다. 
        CalcAveGPA();//과목 평균 평점을 계산해주는 함수
        Subject* SearchSub; // SearchSub의 포인터 변수
        string subname;
        InputUtil::InputValue(subname);
        SearchSub = SubSearch(subname);// 특정 과목을 찾는 함수 호출을 하여 SearchSub에 넣어준다.
        if (SearchSub != NULL)
        {
            SearchSub->Subject::Modify(); //과목정보를 수정하는 함수 호출
            CalcAveGPA();
        }
        else //과목정보에서 NULL값을 반환 받았을 때
        {
            cout << " 다시 입력해주세요.\n";
            Student::Modify();
        }
    }
    else
    {
        cout << " 다시 입력해주세요.\n";
        Student::Modify();
    }
    
}



string Student::GetName()const// 학생이름 정보를 접근할 수 있는 접근자 함수
{
    return m_StdName;
}

int Student::GetHakbun()const//학번 정보를 접근할 수 있는 접근자 함수
{
    return m_Hakbun;
}

int Student::GetSubNum()const//과목수 정보를 접근할 수 있는 접근자 함수

{
    return  m_Subnumber;
}

float Student::GetAveGPA()const//평균 평점을 접근할 수 있는 접근자 함수
{
    return m_AveGPA;
}

Subject *Student::SubSearch(string subname)//과목이름을 검색하여 수정할 과목을 찾는다
{
    
    for (int i = 0; i < m_Subnumber; i++)
    {
        if (subname == (m_Sub + i)->Subject::GetName()) // 입력한 이름과 해당 과목이 같다면 해당 과목 클래스 주소 반환

            return &m_Sub[i];

    }
    cout << "\n해당 과목이 없습니다.";//해당 과목이 없으면 오류 메시지를 출력하고 NULL값을 반환

    return NULL;

}

