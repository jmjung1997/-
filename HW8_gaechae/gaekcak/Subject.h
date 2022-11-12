/**************************************************/
/*             HW#8 : 클래스 기초                                                */
/*  작성자 : 정재민                                날짜 : 2021년 5월 7일  */
/*                                                                                                     */
/* 문제 정의 : 다음의 기능을 수행하는 성적처리 프로그램 작성 (프로그램 명 : Subject.h)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include<string> 
using namespace  std;
#ifndef Subject_H
#define Subject_H
class Subject //과목정보 클래스
{
public://함수가 있는 곳으로 모든 클래스와 밖에서 접근을 허용한다.
    Subject();//디폴트 생성자
    Subject(string name, int Hakjum,string Grade);//매개 변수가 있는 생성자
    Subject(const Subject& sub);//const 멤버변수나 레퍼런스 멤버변수로 초기화
    ~Subject();//소멸자

    void Initialize(string, int, string);//함수오버로딩 매개변수가 있는 초기화 함수
    
    void InputData();// 과목 정보를 집어 넣는 함수

    static void printTitle();//과목명, 과목학점, 과목등금, 과목평점의 타이틀을 출력하는 함수
    void printData();//과목명, 과목학점, 과목등금, 과목평점의 데이터를 출력하는 함수
    void CalcGPA();//과목 평점 계산하는 함수

    string GetName()const;//과목이름을 접근할 수 있는 접근자 함수
    int GetHakjum() const;//학점 정보를 접근할 수 있는 접근자 함수
    string GetGrade()const;//과목등급을 접근할 수 있는 접근자 함수
    float GetGPA() const;//과목평점을 접근할 수 있는 접근자 함수
    void Modify();//과목정보를 수정하는 함수
    
protected://멤버 변수로 클래스 자신과 상속받은 자식 클래스에만 허용
    string m_name;        // 과목이름 
    int m_Hakjum;         // 과목학점 
    string m_Grade;       // 과목등급 
    float m_GPA;          // 과목 평점 
};

#endif