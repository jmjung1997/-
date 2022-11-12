/**************************************************/
/*             HW#8 : Ŭ���� ����                                                */
/*  �ۼ��� : �����                                ��¥ : 2021�� 5�� 7��  */
/*                                                                                                     */
/* ���� ���� : ������ ����� �����ϴ� ����ó�� ���α׷� �ۼ� (���α׷� �� : Subject.cpp)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include"Subject.h"

#include <iostream>
#include<string> 
#include <stdlib.h>

#include"InputUtil.h"

using namespace std;

void line();
float number_grade(string grade);

Subject::Subject()//�������� Ŭ���� �ȿ� �ִ� �ʱ�ȭ �Լ�
{
    m_name = " ";       // �����̸� 
    m_Hakjum = 0;       // �������� 
    m_Grade = " ";      // ������ 
    m_GPA = 0.0f;       // ��������

}

Subject::Subject(string name, int Hakjum, string Grade)//���� Ŭ���� �ȿ� �Ű������� �ִ� �Լ� 
{
    m_name = name;        // �����̸� 
    m_Hakjum = Hakjum;    // �������� 
    m_Grade = Grade;      // ������ 
    CalcGPA();            // �����������ϱ� �Լ�
}

Subject::Subject(const Subject& sub)
{
    this->m_name = sub.m_name;        // �����̸� 
    this->m_Hakjum = sub.m_Hakjum;    // �������� 
    this->m_Grade = sub.m_Grade;      // ������ 
    CalcGPA();            // �����������ϱ� �Լ�
}


Subject::~Subject()
{
    cout << m_name << "�� �Ҹ�Ǿ����ϴ�" << "\n";
}



void Subject::InputData() //���� Ŭ���� �� ������ ������ �Է� �޴��Լ�
{

    cout << "*" << "������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";
    cout << "�������: ";
    InputUtil::InputValue(m_name);
    cout << "��������: ";
    InputUtil::InputValue(m_Hakjum);
    cout << "������<A+ ~F>: ";
    InputUtil::InputValue(m_Grade);
    cout << "\n\n";
    CalcGPA();

}

void Subject::Modify()
{
    cout << "<" << m_name << " ," << m_Hakjum << " ," << m_Grade << ">" << "�� ������ �����ϼ��� \n"; //�����ϰ� ���� �л������� ����Ѵ�.
    cout << "�������: ";
    InputUtil::InputValue(m_name); //�����ϰ� ���� ����������� �ٲپ��ش� 
    cout << "��������: ";
    InputUtil::InputValue(m_Hakjum); //�����ϰ� ���� ������������ �ٲپ��ش�. 
    cout << "������: ";
    InputUtil::InputValue(m_Grade);//�����ϰ� ���� ���������� �ٲپ��ش�.
    CalcGPA();//���� ������ ������ִ��Լ�

}




void Subject::CalcGPA() //GPA���� ����ϴ� �Լ� 
{

    float score = 0;
    score = number_grade(m_Grade);  //����� ����ȭ ���� score ������ �����Ѵ�.
    m_GPA = score * m_Hakjum; // Score*������ ��������� m_Hakjum�� ���ؼ� GPA�� ����Ѵ�.
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


string Subject::GetName()const//�����̸��� ������ �� �ִ� ������ �Լ�
{
    return m_name;
}


int Subject::GetHakjum()const //���� ������ ������ �� �ִ� ������ �Լ�
{
    return m_Hakjum;
}

string Subject::GetGrade()const//�������� ������ �� �ִ� ������ �Լ�

{
    return m_Grade;
}


float Subject::GetGPA()const //���������� ������ �� �ִ� ������ �Լ�
{
    return m_GPA;
}


