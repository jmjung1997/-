#include <iostream>
#include<string> 
#include <stdlib.h>
using namespace std;

void line();
float number_grade(string grade);



class Subject //과목정보 클래스
{
public://함수가 있는 곳으로 모든 클래스와 밖에서 접근을 허용한다.
    void Initialize();//초기화함수
    void Initialize(string, int, string);//함수오버로딩 매개변수가 있는 초기화 함수
    void InputValue(int&);//int형값을 받는 함수
    void InputValue(string&);//string값을 받는 함수
    void InputData();// 과목 정보를 집어 넣는 함수

    void printTitle();//과목명, 과목학점, 과목등금, 과목평점의 타이틀을 출력하는 함수
    void printData();//과목명, 과목학점, 과목등금, 과목평점의 데이터를 출력하는 함수
    void CalcGPA();//과목 평점 계산하는 함수

    string GetName();//과목이름을 접근할 수 있는 접근자 함수
    int GetHakjum();//학점 정보를 접근할 수 있는 접근자 함수
    string GetGrade();//과목등급을 접근할 수 있는 접근자 함수
    float GetGPA();//과목평점을 접근할 수 있는 접근자 함수
protected://멤버 변수로 클래스 자신과 상속받은 자식 클래스에만 허용
    string m_name;        // 과목이름 
    int m_Hakjum;         // 과목학점 
    string m_Grade;       // 과목등급 
    float m_GPA;          // 과목 평점 
};

class Student {// 학생 정보 클래스 
public://함수가 있는 곳으로 모든 클래스와 밖에서 접근을 허용한다.
    void Initialize(); // 멤버변수 초기화
    void Initialize(string, int, int, Subject*); // 인자값으로 멤버변수 초기화
    void Remove(); // 동적메모리 해제 (m_sub)
    void InputValue(int&); // int형값을 받는 함수
    void InputValue(string&);//string값을 받는 함수
    void InputData(); // 멤버변수 값 입력
    void printData(); // 멤버변수 값 출력
    void CalcAveGPA(); // 평균 평점 계산

    string GetName(); // 학생이름 정보를 접근할 수 있는 접근자 함수
    int GetHakbun(); //학번 정보를 접근할 수 있는 접근자 함수
    int GetSubNum(); //과목수 정보를 접근할 수 있는 접근자 함수
    float GetAveGPA();//평균 평점을 접근할 수 있는 접근자 함수

protected://멤버 변수로 클래스 자신과 상속받은 자식 클래스에만 허용
    string m_StdName; // 학생이름 
    int m_Hakbun; // 학번 
    Subject* m_Sub; // 과목 
    float m_AveGPA;   // 교과목 평균 평점 
    int m_Subnumber;//학생별 선택 과목수
};

int main()
{
    Subject sub[2];//과목 정보 2개를 입력 받을 수 있게 클래스 배열을 생성한다
    sub[0].Initialize("컴퓨터", 3, "C0");
    sub[1].Initialize("현대무용", 2, "A0");
    Student st1, st2;//학생 객체 st1, st2를 생성한다.
    st1.Initialize(); //st1 초기화
    st2.Initialize("홍길동", 2013909845, 2, sub);//st2 초기화
    st1.InputData();//st1 객체에 정보를 입력
    cout << "\n" << "st1 정보" << "\n";
    st1.printData();//st1객체 정보 출력
    cout << "\n" << "st2 정보" << "\n";
    st2.printData();//st2객체 정보 출력
    st1.Remove();//st1에 할당 받은 동적할당 해제

}

void Student::Initialize()//학생 클래스 안에 있는 초기화 함수
{
    m_StdName = " "; // 학생이름 
    m_Hakbun = 0; // 학번 
    m_Subnumber = 0;//학생별 선택 과목수
    m_Sub = NULL; // 과목 
    m_AveGPA=0.0f;//평균 평점 초기화

}

void Student::Initialize(string name, int Hakbun, int Subnum, Subject* sub)//학생 클래스 안에 매개변수가 있는 함수 
{
    m_StdName = name; // 학생이름 
    m_Hakbun = Hakbun; // 학번 
    m_Subnumber = Subnum;//학생별 선택 과목수
    m_Sub = sub; // 과목 
    CalcAveGPA(); //평균평점 구하는 함수
}

void Subject::Initialize()//과목정보 클래스 안에 있는 초기화 함수
{
    m_name = " ";       // 과목이름 
    m_Hakjum = 0;       // 과목학점 
    m_Grade = " ";      // 과목등급 
    m_GPA = 0.0f;       // 과목평점

}

void Subject::Initialize(string name, int Hakjum, string Grade)//과목 클래스 안에 매개변수가 있는 함수 
{
    m_name = name;        // 과목이름 
    m_Hakjum = Hakjum;    // 과목학점 
    m_Grade = Grade;      // 과목등급 
    CalcGPA();            // 과목평점구하기 함수
}



void Subject::InputData() //과목 클래스 안 과목의 정보를 입력 받는함수
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

void Student::InputData() //학생 클래스 안 학생 정보를 입력 받는함수
{
    cout << "이름 : ";
    InputValue(m_StdName);//이름 넣기 
    cout << "학번: ";
    InputValue(m_Hakbun);//학번 넣기
    cout << "수강한 과목 수를 입력 : "; //수강한 과목 수 입력
    InputValue(m_Subnumber);
    m_Sub = new Subject[m_Subnumber]; // 각 학생별 객체 안에 과목 객체배열을 입력받은 과목수로 동적배열을 통해 생성한다.
    for (int i = 0; i < m_Subnumber; i++) //과목수 만큼 반복하면서 데이터 입력 받기
    {
        (m_Sub+i)->Subject::InputData();
    }
    CalcAveGPA(); //과목 평균 평점 계산하는 함수
}


void Subject::InputValue(string& str)//string형 데이터를 입력 받는 함수 
{

    getline(cin, str);

}

void Subject::InputValue(int& i)//int형 데이터를 입력 받는 함수 
{
    cin >> i;
    cin.ignore();
}
void Student::InputValue(string& str)//string형 데이터를 입력 받는 함수
{

    getline(cin, str);

}

void Student::InputValue(int& i)//int형 데이터를 입력 받는 함수
{
    cin >> i;
    cin.ignore();
}

void Subject::CalcGPA() //GPA성적 계산하는 함수 
{

    float score = 0;
    score = number_grade(m_Grade);  //등급을 점수화 시켜 score 변수에 저장한다.
    m_GPA = score * m_Hakjum; // Score*학점와 멤버변수인 m_Hakjum을 곱해서 GPA를 계산한다.
}


void Student::CalcAveGPA() /* Student 클래스 안 평균 GPA 계산하는 함수 */
{
    float tGPA = 0;
    int tHakjum = 0;
    for (int j = 0; j < m_Subnumber; j++)// 과목 전체 수 만큼 반복
    {
        tGPA += (m_Sub+j)->GetGPA(); // 각 과목 GPA 총 합 구하기      
    }   
    for (int i = 0; i < m_Subnumber; i++) // 해당 학생 전체 학점 수 구하기
    {
        tHakjum += (m_Sub + i)->GetHakjum();
    }
    m_AveGPA = (float)tGPA / tHakjum; // 전체 GPA를 전체 학점수로 나누어 평균 GPA 구하기 
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

void Student::Remove()//동적 할당 된 메모리 해제
{
    delete[]m_Sub;
}

void line()
{
    cout << "\n============================================\n";
}

string Subject::GetName() //과목이름을 접근할 수 있는 접근자 함수
{
    return m_name;
}


int Subject::GetHakjum() //학점 정보를 접근할 수 있는 접근자 함수
{
    return m_Hakjum;
}

string Subject::GetGrade()//과목등급을 접근할 수 있는 접근자 함수

{
    return m_Grade;
}


float Subject::GetGPA() //과목평점을 접근할 수 있는 접근자 함수
{
    return m_GPA;
}

string Student:: GetName() // 학생이름 정보를 접근할 수 있는 접근자 함수
{
    return m_StdName;
}

int Student::GetHakbun()//학번 정보를 접근할 수 있는 접근자 함수
{
    return m_Hakbun;
}

int Student::GetSubNum()//과목수 정보를 접근할 수 있는 접근자 함수

{
    return  m_Subnumber;
}

float Student::GetAveGPA()//평균 평점을 접근할 수 있는 접근자 함수
{    
    return m_AveGPA;
}