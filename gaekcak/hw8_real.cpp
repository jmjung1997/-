#include <iostream>
#include<string> 
#include <stdlib.h>
using namespace std;

void line();
float number_grade(string grade);





class Subject
{
public:
    void Initialize();
    void Initialize(string, int, string);
    void InputValue(int&);
    void InputValue(string&);
    void InputData();

    void printTitle();
    void printData();
    void CalcGPA();

protected:
    string m_name;        // 과목이름 
    int m_Hakjum;                   // 과목학점 
    string m_Grade;             // 과목등급 
    float m_GPA;                    // 과목 평점 
};

int main()
{
    Subject sub1, sub2, sub3[2], *sub4;
    int i;

    sub1.Initialize();
    sub2.Initialize("사진학", 3, "A+");
    for (i = 0; i < 2; i++)
    {
        sub3[i].Initialize("컴퓨터", 3, "A0");
        
    }
    
    sub4 = new Subject[2];

    sub1.InputData(); // 화면에서 입력
    cout << "\n" << "sub1 정보" << "\n";
    sub1.printTitle(); sub1.printData();
    cout << "\n" << "sub2 정보" << "\n";
    sub2.printTitle(); sub2.printData();
    cout << "\n" << "sub3 정보" << "\n";
    sub3[0].printTitle();
    for (i = 0; i < 2; i++) sub3[i].printData();
    for (i = 0; i < 2; i++) (sub4 + i)->InputData();
    cout << "\n" << "sub4 정보" << "\n";
    sub4->printTitle();
    for (i = 0; i < 2; i++) (sub4 + i)->printData();
    delete[] sub4;


}

void Subject::Initialize()
{
     m_name=" ";        // 과목이름 
     m_Hakjum=0;                   // 과목학점 
     m_Grade=" ";             // 과목등급 
     m_GPA = 0.0f;
    
}

void Subject::Initialize(string name, int Hakjum, string Grade)
{
    m_name = name;        // 과목이름 
    m_Hakjum = Hakjum;                   // 과목학점 
    m_Grade = Grade;             // 과목등급 
    CalcGPA();
}

void Subject::InputData() //학생의 정보를 입력 받는함수
{
        
        cout << "*" << "수강한 과목의 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
    
            cout << "교과목명: ";
            InputValue(m_name);
            cout << "과목학점: ";
            InputValue(m_Hakjum);
            cout << "과목등급<A+ ~F>: ";
            InputValue(m_Grade);
            cout << "\n\n";
            CalcGPA();
     
}

void Subject::InputValue(string& str)//데이터를 입력 받는 함수 ,인라인함수 오버로딩
{

    getline(cin, str);

}

void Subject::InputValue(int& i)//데이터를 입력 받는 함수 ,인라인함수 오버로딩
{
    cin >> i;
    cin.ignore();
}


void Subject::CalcGPA() //GPA성적 계산하는 함수, &Sub는 레퍼런스 함수 이므로 값으로 전달 받는다. 
{

    float score = 0;
    score = number_grade(m_Grade);  //등급을 점수화 시켜 score 변수에 저장한다.
    m_GPA = score * m_Hakjum; // Score*학점을 통해 GPA를 계산한다.
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

void Subject::printTitle()
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

void Subject::printData()
{
    cout.width(10);
    cout <<m_name;
    cout.width(10);
    cout << m_Hakjum;
    cout.width(10);
    cout <<m_Grade;
    cout.width(10);
    cout <<m_GPA;
    cout << "\n";
}



void line()
{
    cout << "\n============================================\n";
}
