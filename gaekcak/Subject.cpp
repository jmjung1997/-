/**************************************************/
/*             HW#8 : 클래스 기초                                                */
/*  작성자 : 정재민                                날짜 : 2021년 5월 7일  */
/*                                                                                                     */
/* 문제 정의 : 다음의 기능을 수행하는 성적처리 프로그램 작성 (프로그램 명 : Subject.cpp)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include"Subject.h"

#include <iostream>
#include<string> 
#include <stdlib.h>

#include"InputUtil.h"

using namespace std;

void line();
float number_grade(string grade);

Subject::Subject()//과목정보 클래스 안에 있는 초기화 함수
{
    m_name = " ";       // 과목이름 
    m_Hakjum = 0;       // 과목학점 
    m_Grade = " ";      // 과목등급 
    m_GPA = 0.0f;       // 과목평점

}

Subject::Subject(string name, int Hakjum, string Grade)//과목 클래스 안에 매개변수가 있는 함수 
{
    m_name = name;        // 과목이름 
    m_Hakjum = Hakjum;    // 과목학점 
    m_Grade = Grade;      // 과목등급 
    CalcGPA();            // 과목평점구하기 함수
}

Subject::Subject(const Subject& sub)
{
    this->m_name = sub.m_name;        // 과목이름 
    this->m_Hakjum = sub.m_Hakjum;    // 과목학점 
    this->m_Grade = sub.m_Grade;      // 과목등급 
    CalcGPA();            // 과목평점구하기 함수
}


Subject::~Subject()
{
    cout << m_name << "이 소멸되었습니다" << "\n";
}



void Subject::InputData() //과목 클래스 안 과목의 정보를 입력 받는함수
{

    cout << "*" << "수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
    cout << "교과목명: ";
    InputUtil::InputValue(m_name);
    cout << "과목학점: ";
    InputUtil::InputValue(m_Hakjum);
    cout << "과목등급<A+ ~F>: ";
    InputUtil::InputValue(m_Grade);
    cout << "\n\n";
    CalcGPA();

}

void Subject::Modify()
{
    cout << "<" << m_name << " ," << m_Hakjum << " ," << m_Grade << ">" << "의 정보를 수정하세요 \n"; //수정하고 싶은 학생정보를 출력한다.
    cout << "교과목명: ";
    InputUtil::InputValue(m_name); //수정하고 싶은 교과목명으로 바꾸어준다 
    cout << "과목학점: ";
    InputUtil::InputValue(m_Hakjum); //수정하고 싶은 과목학점으로 바꾸어준다. 
    cout << "과목등급: ";
    InputUtil::InputValue(m_Grade);//수정하고 싶은 과목등급으로 바꾸어준다.
    CalcGPA();//과목 평점을 계산해주는함수

}




void Subject::CalcGPA() //GPA성적 계산하는 함수 
{

    float score = 0;
    score = number_grade(m_Grade);  //등급을 점수화 시켜 score 변수에 저장한다.
    m_GPA = score * m_Hakjum; // Score*학점와 멤버변수인 m_Hakjum을 곱해서 GPA를 계산한다.
}

void Subject::printTitle()// Subject 클래스 안에 과목명, 과목학점, 과목등급, 과목평점 타이틀을 출력하는 함수
{
    line();
    cout.width(10);
    cout << "과목명";
    cout.width(10);
    cout << "과목학점";
    cout.width(10);
    cout << "과목등급";
    cout.width(10);
    cout << " 과목평점\n";
    line();
}

void Subject::printData()// Subject 클래스 안에 과목정보 데이터를 출력하는 함수
{
    cout.width(10);
    cout << m_name;
    cout.width(10);
    cout << m_Hakjum;
    cout.width(10);
    cout << m_Grade;
    cout.width(10);
    cout << m_GPA;
    cout << "\n";
}


string Subject::GetName()const//과목이름을 접근할 수 있는 접근자 함수
{
    return m_name;
}


int Subject::GetHakjum()const //학점 정보를 접근할 수 있는 접근자 함수
{
    return m_Hakjum;
}

string Subject::GetGrade()const//과목등급을 접근할 수 있는 접근자 함수

{
    return m_Grade;
}


float Subject::GetGPA()const //과목평점을 접근할 수 있는 접근자 함수
{
    return m_GPA;
}


