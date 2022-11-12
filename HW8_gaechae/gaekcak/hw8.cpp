/*************************************************/


#include <iostream>
#include<string> 
#include <stdlib.h>
using namespace std;

inline void PrintMenu();

struct Student {// 학생 정보 
    string StdName; // 학생이름 
    int Hakbun; // 학번 
    Subject* Sub; // 과목 
    float AveGPA;   // 교과목 평균 평점 
    int Subnumber;//학생별 선택 과목수
};

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



void PrintMenu(); //menu출력함수
void CalcGPA(Subject& sub);// GPA를 계산해주는 함수
float CalcAveGPA(Subject* Sub, int Subnumber); //평균 GPA를 계산해주는 함수
void PrintAllData(const Student* rst, int StdNum); // 모든 데이터를 출력하는 함수
void PrintOneData(const Student& rst); // 하나의 데이터를 출력하는 함수
void PrintAllStdList(Student* pSt, int StudnetNum);
inline void InputValue(string& str);
inline void InputValue(int& i);
void ModifyStdInfo(Student* pSt);
void ModifySubInfo(Subject* Sub);
Student* StdSearch(Student* rst, int Stdnum); //Stdsearch 구조체 선언
void InputData(Student* stu, int StudentNum);// 학생 정보를 입력해주는 함수
Subject* SubjectSearch(const Student* pSt);
void line();//선 긋는 함수 선언
float number_grade(char grade); //각 grade를 점수로 바꿔 주는 함수



int main()
{
    Subject sub1, sub2, sub3[2], *sub4;
    int i;

    sub1.Initialize();
    sub2.Initialize("사진학", 3, "A+");
    for (i = 0; i < 2; i++)
    {
        sub3[i].Initialize("컴퓨터", 3, "C");
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

    
    string m_SubName = NULL;
    int m_Hakjum = 0;
    string m_Grade = NULL;
    float m_GPA = 0.0f;
    return;
}

void Subject::Initialize(string SubName = NULL, int Hakjum = 0, string Grade = NULL)
{

    return;

}

void Subject::InputData(Student* stu, int StudentNum) //학생의 정보를 입력 받는함수
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




inline void InputValue(string& str)//데이터를 입력 받는 함수 ,인라인함수 오버로딩
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
        if (name == rst[i].StdName) // 입력한 이름과 학생 이름이 같다면 해당 학생 구조체 주소 반환
            return &rst[i];
    }
    cout << "\n해당 학생이 없습니다.";//해당 이름이 없으면 오류 메시지를 출력하고 NULL값을 반환

    return NULL;

}

Subject* SubjectSearch(const Student* pSt)
{
    string sub;
    cout << "검색 할 과목이름: ";
    InputValue(sub);
    for (int i = 0; i < pSt->Subnumber; i++)
    {
        if (sub == pSt->Sub[i].SubName) // 입력한 이름과 해당 과목이 같다면 해당 과목 구조체 주소 반환

            return &pSt->Sub[i];

    }
    cout << "\n해당 과목이 없습니다.";//해당 과목이 없으면 오류 메시지를 출력하고 NULL값을 반환

    return NULL;

}





void ModifyStdInfo(Student* pSt)/*학생의 정보를 수정하는 함수,
원하는 학생정보를 Student* StdSearch(Student* rst)를 통해 찾아 포인터 변수 pst에 전달한다.*/
{

    cout << "<" << pSt->StdName << " ," << pSt->Hakbun << ">" << "의 정보를 수정하세요 \n"; //수정하고 싶은 학생정보를 출력한다.
    cout << "이름: ";
    InputValue(pSt->StdName); //수정하고 싶은 학생의 이름으로 기존 이름 구조체 값을 새롭게 바꿔준다. 
    cout << "학번: ";
    InputValue(pSt->Hakbun); //수정하고 싶은 학생의 학번으로 기존 학번 구조체 값을 새롭게 바꿔준다. 

}

void ModifySubInfo(Subject* Sub)/*과목의 정보를 수정하는 함수,
수정하고 싶은 과목정보를 Subject* SubjectSearch(const Student* pSt)를 통해 찾아 포인터 변수 Sub에 전달한다.*/
{

    cout << "<" << Sub->SubName << " ," << Sub->Hakjum << " ," << Sub->Grade << ">" << "의 정보를 수정하세요 \n"; //수정하고 싶은 학생정보를 출력한다.
    cout << "교과목명: ";
    InputValue(Sub->SubName); //수정하고 싶은 교과목명으로 바꾸어준다 
    cout << "과목학점: ";
    InputValue(Sub->Hakjum); //수정하고 싶은 과목학점으로 바꾸어준다. 
    cout << "과목등급: ";
    InputValue(Sub->Grade);//수정하고 싶은 과목등급으로 바꾸어준다.



}

