/**************************************************/
/*             HW#8 : 생성자와 소멸자                                               */
/*  작성자 : 정재민                                날짜 : 2021년 5월 14일  */
/*                                                                                                     */
/* 문제 정의 : 다음의 기능을 수행하는 성적처리 프로그램 작성 (프로그램 명 : main.cpp)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include"Subject.h"
#include"Student.h"

#include <iostream>
#include<string> 
#include <stdlib.h>
#include<cstring>
using namespace std;

void line();
float number_grade(string grade);
void ShowData(const Student&);

/*
int main() {
    Subject sub1("컴퓨터", 3, "C0");//매개변수 있는 형태로 과목정보 초기화
    Subject sub2(sub1); //const 변수 형태로 과목정보를 sub1의 정보를 복사한다.
    cout << "\n" << "sub1 정보" << "\n";
    line();
    sub1.Subject::printData();//sub1 과목정보에 대하여 출력
    cout << "\n" << "sub2 정보" << "\n";
    line();
    sub2.Subject::printData();//sub2 과목정보에 대하여 출력
    sub2.Subject::Modify();
    Student st2("홍길동", 2013909845, 1, &sub1);
    Student st3("김성령", 2015909845, 1, &sub2);
    Student st1(st2);//깊은복사자를 위해 st1각체를 다음과 같이 생성하였습니다.
    cout << "\n" << "st1 정보" << "\n";
    line();
    st1.Student::printData();//st1 정보 출력
    cout << "\n" << "st2 정보" << "\n";
    line();
    st2.Student::printData(); //st2 정보 출력
    st2.Student::Modify();//st2 정보 수정
    cout << "\n" << "수정된 st2 정보" << "\n";
    line();
    st2.Student::printData(); //수정된 st2 학생정보 출력 
    st1.Student::printData();//st1정보 출력해서 깊은 복사자가 제대로 됐는지 확인하기
    cout << "\n" << "st3 정보" << "\n";
    line();
    st3.Student::printData();
    return 0;
}*/
/*
int main()
{
    Student std;
    std.InputData();
    std.printData();
    Subject* sub = std.SubSearch("사진학");
    // 과목명이 성공적으로 탐색된 경우
    // 해당 과목정보가 있는 메모리 주소를 리턴
    if (sub != NULL)
    {
        sub->printTitle();
        sub->printData();
    }
    return 0;
}
*/
void Data(const Student& s) { // 응용프로그램에 있는 전역함수
    cout << s.GetName() << "이 수강한 과목은 총" << s.GetSubNum() << "개로";
    cout << "수강한 과목의 평균평점은" << s.GetAveGPA() << "입니다.\n";
}

int main() 
{
    Subject sub1("컴퓨터", 3, "C0");
    Subject sub2("계산기", 2, "A0");
    Subject::printTitle();
    sub1.printData();
    sub2.printData();
    Student st1("홍길동", 2013909845, 1, &sub1);
    st1.printData();
    Data(st1);
}

float number_grade(string grade) //등급을 점수로 변환시켜 주는 함수
{

    if (grade == "A+")
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



void line()
{
    cout << "\n============================================\n";
}



