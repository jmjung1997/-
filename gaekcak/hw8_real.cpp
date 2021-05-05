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
    string m_name;        // �����̸� 
    int m_Hakjum;                   // �������� 
    string m_Grade;             // ������ 
    float m_GPA;                    // ���� ���� 
};

int main()
{
    Subject sub1, sub2, sub3[2], *sub4;
    int i;

    sub1.Initialize();
    sub2.Initialize("������", 3, "A+");
    for (i = 0; i < 2; i++)
    {
        sub3[i].Initialize("��ǻ��", 3, "A0");
        
    }
    
    sub4 = new Subject[2];

    sub1.InputData(); // ȭ�鿡�� �Է�
    cout << "\n" << "sub1 ����" << "\n";
    sub1.printTitle(); sub1.printData();
    cout << "\n" << "sub2 ����" << "\n";
    sub2.printTitle(); sub2.printData();
    cout << "\n" << "sub3 ����" << "\n";
    sub3[0].printTitle();
    for (i = 0; i < 2; i++) sub3[i].printData();
    for (i = 0; i < 2; i++) (sub4 + i)->InputData();
    cout << "\n" << "sub4 ����" << "\n";
    sub4->printTitle();
    for (i = 0; i < 2; i++) (sub4 + i)->printData();
    delete[] sub4;


}

void Subject::Initialize()
{
     m_name=" ";        // �����̸� 
     m_Hakjum=0;                   // �������� 
     m_Grade=" ";             // ������ 
     m_GPA = 0.0f;
    
}

void Subject::Initialize(string name, int Hakjum, string Grade)
{
    m_name = name;        // �����̸� 
    m_Hakjum = Hakjum;                   // �������� 
    m_Grade = Grade;             // ������ 
    CalcGPA();
}

void Subject::InputData() //�л��� ������ �Է� �޴��Լ�
{
        
        cout << "*" << "������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";
    
            cout << "�������: ";
            InputValue(m_name);
            cout << "��������: ";
            InputValue(m_Hakjum);
            cout << "������<A+ ~F>: ";
            InputValue(m_Grade);
            cout << "\n\n";
            CalcGPA();
     
}

void Subject::InputValue(string& str)//�����͸� �Է� �޴� �Լ� ,�ζ����Լ� �����ε�
{

    getline(cin, str);

}

void Subject::InputValue(int& i)//�����͸� �Է� �޴� �Լ� ,�ζ����Լ� �����ε�
{
    cin >> i;
    cin.ignore();
}


void Subject::CalcGPA() //GPA���� ����ϴ� �Լ�, &Sub�� ���۷��� �Լ� �̹Ƿ� ������ ���� �޴´�. 
{

    float score = 0;
    score = number_grade(m_Grade);  //����� ����ȭ ���� score ������ �����Ѵ�.
    m_GPA = score * m_Hakjum; // Score*������ ���� GPA�� ����Ѵ�.
}


float number_grade(string grade) //����� ������ ��ȯ���� �ִ� �Լ�
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
    cout << "�����";
    cout.width(10);
    cout << "��������";
    cout.width(10);
    cout << "������";
    cout.width(10);
    cout << " ��������\n";
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
