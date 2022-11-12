/**************************************************/
/*             HW#8 : 클래스 기초                                                */
/*  작성자 : 정재민                                날짜 : 2021년 5월 7일  */
/*                                                                                                     */
/* 문제 정의 : 다음의 기능을 수행하는 성적처리 프로그램 작성 (프로그램 명 : Student.h)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include<string> 
using namespace  std;
#ifndef Student_H
#define Student_H
class Student {// 학생 정보 클래스 
public://함수가 있는 곳으로 모든 클래스와 밖에서 접근을 허용한다.
    Student();//디폴트 생성자
    Student(string name, int hakbun,int subnum, Subject* sub);//매개변수가 있는 생성자
    Student(const Student& std);//const 멤버변수나 레퍼런스 멤버변수로 초기화
    ~Student();//소멸자 
   
    void InputData(); // 멤버변수 값 입력
    void printData(); // 멤버변수 값 출력
    void CalcAveGPA(); // 평균 평점 계산
    
    string GetName()const; // 학생이름 정보를 접근할 수 있는 접근자 함수
    int GetHakbun()const;//학번 정보를 접근할 수 있는 접근자 함수
    int GetSubNum()const;//과목수 정보를 접근할 수 있는 접근자 함수
    float GetAveGPA()const;//평균 평점을 접근할 수 있는 접근자 함수
    void Modify();//학생정보를 수정하는 함수
    Subject* SubSearch(string subname);//특정과목을 찾는함수
protected://멤버 변수로 클래스 자신과 상속받은 자식 클래스에만 허용
    string m_StdName; // 학생이름 
    int m_Hakbun; // 학번 
    Subject* m_Sub; // 과목 
    float m_AveGPA;   // 교과목 평균 평점 
    int m_Subnumber;//학생별 선택 과목수
};
#endif