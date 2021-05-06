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

    string GetName();
    int GetHakjum();
    string GetGrade();
    float GetGPA();
protected:
    string m_name;        // 과목이름 
    int m_Hakjum;                   // 과목학점 
    string m_Grade;             // 과목등급 
    float m_GPA;                    // 과목 평점 
};

class Student {// 학생 정보 
public:
    void Initialize(); // 멤버변수 초기화
    void Initialize(string, int, int, Subject*); // 인자값으로 멤버변수 초기화
    void Remove(); // 동적메모리 해제 (m_sub)
    void InputValue(int&);
    void InputValue(string&);
    void InputData(); // 멤버변수 값 입력
    void printData(); // 멤버변수 값 출력
    void CalcAveGPA(); // 평균 평점 계산

    string GetName(); 
    int GetHakbun(); 
    int GetSubNum(); 
    float GetAveGPA();

protected:
    string m_StdName; // 학생이름 
    int m_Hakbun; // 학번 
    Subject* m_Sub; // 과목 
    float m_AveGPA;   // 교과목 평균 평점 
    int m_Subnumber;//학생별 선택 과목수
};

int main()
{
    Subject sub[2];
    sub[0].Initialize("컴퓨터", 3, "C0");
    sub[1].Initialize("현대무용", 2, "A0");
    Student st1, st2;
    st1.Initialize();
    st2.Initialize("홍길동", 2013909845, 2, sub);
    st1.InputData();
    cout << "\n" << "st1 정보" << "\n";
    st1.printData();
    cout << "\n" << "st2 정보" << "\n";
    st2.printData();
    st1.Remove();

}

void Student::Initialize()
{
    m_StdName = " "; // 학생이름 
    m_Hakbun = 0; // 학번 
    m_Subnumber = 0;//학생별 선택 과목수
    m_Sub = NULL; // 과목 
    m_AveGPA=0.0f;//평균 평점 초기화

}

void Student::Initialize(string name, int Hakbun, int Subnum, Subject* sub)
{
    m_StdName = name; // 학생이름 
    m_Hakbun = Hakbun; // 학번 
    m_Subnumber = Subnum;//학생별 선택 과목수
    m_Sub = sub; // 과목 
    CalcAveGPA(); //평균평점 함수
}

void Subject::Initialize()
{
    m_name = " ";        // 과목이름 
    m_Hakjum = 0;                   // 과목학점 
    m_Grade = " ";             // 과목등급 
    m_GPA = 0.0f;

}

void Subject::Initialize(string name, int Hakjum, string Grade)
{
    m_name = name;        // 과목이름 
    m_Hakjum = Hakjum;                   // 과목학점 
    m_Grade = Grade;             // 과목등급 
    CalcGPA();
}



void Subject::InputData() //과목의 정보를 입력 받는함수
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

void Student::InputData()
{
    cout << "이름 : ";
    InputValue(m_StdName);//이름 넣기 
    cout << "학번: ";
    InputValue(m_Hakbun);//학번 넣기
    cout << "수강한 과목 수를 입력 : "; //수강한 과목 수 입력
    InputValue(m_Subnumber);
    m_Sub = new Subject[m_Subnumber]; // 각 학생별 객체 안에 과목 객체배열을 입력받은 과목수로 동적배열을 통해 생성한다.
    for (int i = 0; i < m_Subnumber; i++)
    {
        (m_Sub+i)->Subject::InputData();
    }
    CalcAveGPA();
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
void Student::InputValue(string& str)//데이터를 입력 받는 함수 ,인라인함수 오버로딩
{

    getline(cin, str);

}

void Student::InputValue(int& i)//데이터를 입력 받는 함수 ,인라인함수 오버로딩
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


void Student::CalcAveGPA() /* 평균 GPA 계산하기,이때 매개변수 *Sub이므로 주소값으로 호출한다.
                                                   전체 학생 토탈 학점을 구하기 위해 Subnumber 값을 전달 받는다 */
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
    cout << m_name;
    cout.width(10);
    cout << m_Hakjum;
    cout.width(10);
    cout << m_Grade;
    cout.width(10);
    cout << m_GPA;
    cout << "\n";
}
void Student::printData()
{
    cout << "\n\n";
    cout.width(10);
    cout << m_StdName;
    cout.width(10);
    cout << m_Hakbun; 
    
    m_Sub->Subject::printTitle();
    for (int i = 0; i < m_Subnumber; i++)
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

void Student::Remove()
{
    delete[]m_Sub;
}

void line()
{
    cout << "\n============================================\n";
}

string Subject::GetName()
{
    return m_name;
}


int Subject::GetHakjum()
{
    return m_Hakjum;
}

string Subject::GetGrade()
{
    return m_Grade;
}


float Subject::GetGPA()
{
    return m_GPA;
}

string Student:: GetName()
{
    return m_StdName;
}

int Student::GetHakbun()
{
    return m_Hakbun;
}

int Student::GetSubNum()
{
    return  m_Subnumber;
}

float Student::GetAveGPA()
{    
    return m_AveGPA;
}