#include <iostream>
#include<string> 
#include <stdlib.h>
using namespace std;

void line();
float number_grade(string grade);



class Subject //�������� Ŭ����
{
public://�Լ��� �ִ� ������ ��� Ŭ������ �ۿ��� ������ ����Ѵ�.
    void Initialize();//�ʱ�ȭ�Լ�
    void Initialize(string, int, string);//�Լ������ε� �Ű������� �ִ� �ʱ�ȭ �Լ�
    void InputValue(int&);//int������ �޴� �Լ�
    void InputValue(string&);//string���� �޴� �Լ�
    void InputData();// ���� ������ ���� �ִ� �Լ�

    void printTitle();//�����, ��������, ������, ���������� Ÿ��Ʋ�� ����ϴ� �Լ�
    void printData();//�����, ��������, ������, ���������� �����͸� ����ϴ� �Լ�
    void CalcGPA();//���� ���� ����ϴ� �Լ�

    string GetName();//�����̸��� ������ �� �ִ� ������ �Լ�
    int GetHakjum();//���� ������ ������ �� �ִ� ������ �Լ�
    string GetGrade();//�������� ������ �� �ִ� ������ �Լ�
    float GetGPA();//���������� ������ �� �ִ� ������ �Լ�
protected://��� ������ Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
    string m_name;        // �����̸� 
    int m_Hakjum;         // �������� 
    string m_Grade;       // ������ 
    float m_GPA;          // ���� ���� 
};

class Student {// �л� ���� Ŭ���� 
public://�Լ��� �ִ� ������ ��� Ŭ������ �ۿ��� ������ ����Ѵ�.
    void Initialize(); // ������� �ʱ�ȭ
    void Initialize(string, int, int, Subject*); // ���ڰ����� ������� �ʱ�ȭ
    void Remove(); // �����޸� ���� (m_sub)
    void InputValue(int&); // int������ �޴� �Լ�
    void InputValue(string&);//string���� �޴� �Լ�
    void InputData(); // ������� �� �Է�
    void printData(); // ������� �� ���
    void CalcAveGPA(); // ��� ���� ���

    string GetName(); // �л��̸� ������ ������ �� �ִ� ������ �Լ�
    int GetHakbun(); //�й� ������ ������ �� �ִ� ������ �Լ�
    int GetSubNum(); //����� ������ ������ �� �ִ� ������ �Լ�
    float GetAveGPA();//��� ������ ������ �� �ִ� ������ �Լ�

protected://��� ������ Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
    string m_StdName; // �л��̸� 
    int m_Hakbun; // �й� 
    Subject* m_Sub; // ���� 
    float m_AveGPA;   // ������ ��� ���� 
    int m_Subnumber;//�л��� ���� �����
};

int main()
{
    Subject sub[2];//���� ���� 2���� �Է� ���� �� �ְ� Ŭ���� �迭�� �����Ѵ�
    sub[0].Initialize("��ǻ��", 3, "C0");
    sub[1].Initialize("���빫��", 2, "A0");
    Student st1, st2;//�л� ��ü st1, st2�� �����Ѵ�.
    st1.Initialize(); //st1 �ʱ�ȭ
    st2.Initialize("ȫ�浿", 2013909845, 2, sub);//st2 �ʱ�ȭ
    st1.InputData();//st1 ��ü�� ������ �Է�
    cout << "\n" << "st1 ����" << "\n";
    st1.printData();//st1��ü ���� ���
    cout << "\n" << "st2 ����" << "\n";
    st2.printData();//st2��ü ���� ���
    st1.Remove();//st1�� �Ҵ� ���� �����Ҵ� ����

}

void Student::Initialize()//�л� Ŭ���� �ȿ� �ִ� �ʱ�ȭ �Լ�
{
    m_StdName = " "; // �л��̸� 
    m_Hakbun = 0; // �й� 
    m_Subnumber = 0;//�л��� ���� �����
    m_Sub = NULL; // ���� 
    m_AveGPA=0.0f;//��� ���� �ʱ�ȭ

}

void Student::Initialize(string name, int Hakbun, int Subnum, Subject* sub)//�л� Ŭ���� �ȿ� �Ű������� �ִ� �Լ� 
{
    m_StdName = name; // �л��̸� 
    m_Hakbun = Hakbun; // �й� 
    m_Subnumber = Subnum;//�л��� ���� �����
    m_Sub = sub; // ���� 
    CalcAveGPA(); //������� ���ϴ� �Լ�
}

void Subject::Initialize()//�������� Ŭ���� �ȿ� �ִ� �ʱ�ȭ �Լ�
{
    m_name = " ";       // �����̸� 
    m_Hakjum = 0;       // �������� 
    m_Grade = " ";      // ������ 
    m_GPA = 0.0f;       // ��������

}

void Subject::Initialize(string name, int Hakjum, string Grade)//���� Ŭ���� �ȿ� �Ű������� �ִ� �Լ� 
{
    m_name = name;        // �����̸� 
    m_Hakjum = Hakjum;    // �������� 
    m_Grade = Grade;      // ������ 
    CalcGPA();            // �����������ϱ� �Լ�
}



void Subject::InputData() //���� Ŭ���� �� ������ ������ �Է� �޴��Լ�
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

void Student::InputData() //�л� Ŭ���� �� �л� ������ �Է� �޴��Լ�
{
    cout << "�̸� : ";
    InputValue(m_StdName);//�̸� �ֱ� 
    cout << "�й�: ";
    InputValue(m_Hakbun);//�й� �ֱ�
    cout << "������ ���� ���� �Է� : "; //������ ���� �� �Է�
    InputValue(m_Subnumber);
    m_Sub = new Subject[m_Subnumber]; // �� �л��� ��ü �ȿ� ���� ��ü�迭�� �Է¹��� ������� �����迭�� ���� �����Ѵ�.
    for (int i = 0; i < m_Subnumber; i++) //����� ��ŭ �ݺ��ϸ鼭 ������ �Է� �ޱ�
    {
        (m_Sub+i)->Subject::InputData();
    }
    CalcAveGPA(); //���� ��� ���� ����ϴ� �Լ�
}


void Subject::InputValue(string& str)//string�� �����͸� �Է� �޴� �Լ� 
{

    getline(cin, str);

}

void Subject::InputValue(int& i)//int�� �����͸� �Է� �޴� �Լ� 
{
    cin >> i;
    cin.ignore();
}
void Student::InputValue(string& str)//string�� �����͸� �Է� �޴� �Լ�
{

    getline(cin, str);

}

void Student::InputValue(int& i)//int�� �����͸� �Է� �޴� �Լ�
{
    cin >> i;
    cin.ignore();
}

void Subject::CalcGPA() //GPA���� ����ϴ� �Լ� 
{

    float score = 0;
    score = number_grade(m_Grade);  //����� ����ȭ ���� score ������ �����Ѵ�.
    m_GPA = score * m_Hakjum; // Score*������ ��������� m_Hakjum�� ���ؼ� GPA�� ����Ѵ�.
}


void Student::CalcAveGPA() /* Student Ŭ���� �� ��� GPA ����ϴ� �Լ� */
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

void Subject::printTitle()// Subject Ŭ���� �ȿ� �����, ��������, ������, �������� Ÿ��Ʋ�� ����ϴ� �Լ�
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

void Subject::printData()// Subject Ŭ���� �ȿ� �������� �����͸� ����ϴ� �Լ�
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
void Student::printData()//Student Ŭ���� �ȿ� �л����� �����͸� ����ϴ� �Լ�
{
    cout << "\n\n";
    cout.width(10);
    cout << m_StdName; //�л��̸� ���
    cout.width(10);
    cout << m_Hakbun; //�й� ���
    
    m_Sub->Subject::printTitle(); //���� Ÿ��Ʋ ���
    for (int i = 0; i < m_Subnumber; i++)//���� ���� ����ϱ�
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

void Student::Remove()//���� �Ҵ� �� �޸� ����
{
    delete[]m_Sub;
}

void line()
{
    cout << "\n============================================\n";
}

string Subject::GetName() //�����̸��� ������ �� �ִ� ������ �Լ�
{
    return m_name;
}


int Subject::GetHakjum() //���� ������ ������ �� �ִ� ������ �Լ�
{
    return m_Hakjum;
}

string Subject::GetGrade()//�������� ������ �� �ִ� ������ �Լ�

{
    return m_Grade;
}


float Subject::GetGPA() //���������� ������ �� �ִ� ������ �Լ�
{
    return m_GPA;
}

string Student:: GetName() // �л��̸� ������ ������ �� �ִ� ������ �Լ�
{
    return m_StdName;
}

int Student::GetHakbun()//�й� ������ ������ �� �ִ� ������ �Լ�
{
    return m_Hakbun;
}

int Student::GetSubNum()//����� ������ ������ �� �ִ� ������ �Լ�

{
    return  m_Subnumber;
}

float Student::GetAveGPA()//��� ������ ������ �� �ִ� ������ �Լ�
{    
    return m_AveGPA;
}