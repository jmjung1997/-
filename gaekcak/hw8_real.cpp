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
    string m_name;        // �����̸� 
    int m_Hakjum;                   // �������� 
    string m_Grade;             // ������ 
    float m_GPA;                    // ���� ���� 
};

class Student {// �л� ���� 
public:
    void Initialize(); // ������� �ʱ�ȭ
    void Initialize(string, int, int, Subject*); // ���ڰ����� ������� �ʱ�ȭ
    void Remove(); // �����޸� ���� (m_sub)
    void InputValue(int&);
    void InputValue(string&);
    void InputData(); // ������� �� �Է�
    void printData(); // ������� �� ���
    void CalcAveGPA(); // ��� ���� ���

    string GetName(); 
    int GetHakbun(); 
    int GetSubNum(); 
    float GetAveGPA();

protected:
    string m_StdName; // �л��̸� 
    int m_Hakbun; // �й� 
    Subject* m_Sub; // ���� 
    float m_AveGPA;   // ������ ��� ���� 
    int m_Subnumber;//�л��� ���� �����
};

int main()
{
    Subject sub[2];
    sub[0].Initialize("��ǻ��", 3, "C0");
    sub[1].Initialize("���빫��", 2, "A0");
    Student st1, st2;
    st1.Initialize();
    st2.Initialize("ȫ�浿", 2013909845, 2, sub);
    st1.InputData();
    cout << "\n" << "st1 ����" << "\n";
    st1.printData();
    cout << "\n" << "st2 ����" << "\n";
    st2.printData();
    st1.Remove();

}

void Student::Initialize()
{
    m_StdName = " "; // �л��̸� 
    m_Hakbun = 0; // �й� 
    m_Subnumber = 0;//�л��� ���� �����
    m_Sub = NULL; // ���� 
    m_AveGPA=0.0f;//��� ���� �ʱ�ȭ

}

void Student::Initialize(string name, int Hakbun, int Subnum, Subject* sub)
{
    m_StdName = name; // �л��̸� 
    m_Hakbun = Hakbun; // �й� 
    m_Subnumber = Subnum;//�л��� ���� �����
    m_Sub = sub; // ���� 
    CalcAveGPA(); //������� �Լ�
}

void Subject::Initialize()
{
    m_name = " ";        // �����̸� 
    m_Hakjum = 0;                   // �������� 
    m_Grade = " ";             // ������ 
    m_GPA = 0.0f;

}

void Subject::Initialize(string name, int Hakjum, string Grade)
{
    m_name = name;        // �����̸� 
    m_Hakjum = Hakjum;                   // �������� 
    m_Grade = Grade;             // ������ 
    CalcGPA();
}



void Subject::InputData() //������ ������ �Է� �޴��Լ�
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

void Student::InputData()
{
    cout << "�̸� : ";
    InputValue(m_StdName);//�̸� �ֱ� 
    cout << "�й�: ";
    InputValue(m_Hakbun);//�й� �ֱ�
    cout << "������ ���� ���� �Է� : "; //������ ���� �� �Է�
    InputValue(m_Subnumber);
    m_Sub = new Subject[m_Subnumber]; // �� �л��� ��ü �ȿ� ���� ��ü�迭�� �Է¹��� ������� �����迭�� ���� �����Ѵ�.
    for (int i = 0; i < m_Subnumber; i++)
    {
        (m_Sub+i)->Subject::InputData();
    }
    CalcAveGPA();
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
void Student::InputValue(string& str)//�����͸� �Է� �޴� �Լ� ,�ζ����Լ� �����ε�
{

    getline(cin, str);

}

void Student::InputValue(int& i)//�����͸� �Է� �޴� �Լ� ,�ζ����Լ� �����ε�
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


void Student::CalcAveGPA() /* ��� GPA ����ϱ�,�̶� �Ű����� *Sub�̹Ƿ� �ּҰ����� ȣ���Ѵ�.
                                                   ��ü �л� ��Ż ������ ���ϱ� ���� Subnumber ���� ���� �޴´� */
{
    float tGPA = 0;
    int tHakjum = 0;
    for (int j = 0; j < m_Subnumber; j++)// ���� ��ü �� ��ŭ �ݺ�
    {
        tGPA += (m_Sub+j)->GetGPA(); // �� ���� GPA �� �� ���ϱ�      
    }   
    for (int i = 0; i < m_Subnumber; i++) // �ش� �л� ��ü ���� �� ���ϱ�
    {
        tHakjum += (m_Sub + i)->GetHakjum();
    }
    m_AveGPA = (float)tGPA / tHakjum; // ��ü GPA�� ��ü �������� ������ ��� GPA ���ϱ� 
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
    cout << "�������";
    cout.width(10);
    cout.precision(2);
    cout << fixed;
    cout << m_AveGPA; //rst�� �ش��ϴ� �л� ��� ���� ����ϱ�
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