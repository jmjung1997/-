/**************************************************/
/*             HW#8 : Ŭ���� ����                                                */
/*  �ۼ��� : �����                                ��¥ : 2021�� 5�� 7��  */
/*                                                                                                     */
/* ���� ���� : ������ ����� �����ϴ� ����ó�� ���α׷� �ۼ� (���α׷� �� : Student.cpp)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include"Subject.h"
#include"Student.h"

#include <iostream>
#include<string> 
#include <stdlib.h>

#include"InputUtil.h"
using namespace std;

void line();
Student::Student()//�л� Ŭ���� �ȿ� �ִ� �ʱ�ȭ �Լ�
{
    m_StdName = " "; // �л��̸� 
    m_Hakbun = 0; // �й� 
    m_Subnumber = 0;//�л��� ���� �����
    m_Sub = NULL; // ���� 
    m_AveGPA = 0.0f;//��� ���� �ʱ�ȭ
}

Student::Student(string name, int Hakbun, int Subnum, Subject* sub)//�л� Ŭ���� �ȿ� �Ű������� �ִ� �Լ� 
{
    m_StdName = name; // �л��̸� 
    m_Hakbun = Hakbun; // �й� 
    m_Subnumber = Subnum;//�л��� ���� �����
    m_Sub = new Subject[m_Subnumber];
    for (int i = 0; i < m_Subnumber; i++)
    {
        m_Sub[i] = sub[i];   //���� �ű�
    }
    CalcAveGPA(); //������� ���ϴ� �Լ�
}

Student::Student(const Student& std)
{
    m_StdName = std.m_StdName; // �л��̸� 
    m_Hakbun = std.m_Hakbun; // �й� 
    m_Subnumber =std.m_Subnumber;//�л��� ���� �����
   
    m_Sub = new Subject[std.m_Subnumber];
    for (int i = 0; i < m_Subnumber; i++)
    {
        m_Sub[i] = std.m_Sub[i];   //���� �ű�
    }
    
    m_AveGPA = std.m_AveGPA;//��� ���� �ʱ�ȭ

}

Student::~Student()//�Ҹ��� �Լ�
{
    cout << m_StdName << "�� �Ҹ�Ǿ����ϴ�" << "\n";
    if (m_Sub)//�����Ҵ�� �������� �޸� �Ҵ����� �ϱ�
    {
        delete[] m_Sub;
        m_Sub = NULL;
    }
}



void Student::InputData() //�л� Ŭ���� �� �л� ������ �Է� �޴��Լ�
{
    cout << "�̸� : ";
    InputUtil::InputValue(m_StdName);//�̸� �ֱ� 
    cout << "�й�: ";
    InputUtil::InputValue(m_Hakbun);//�й� �ֱ�
    cout << "������ ���� ���� �Է� : "; //������ ���� �� �Է�
    InputUtil::InputValue(m_Subnumber);
    m_Sub = new Subject[m_Subnumber]; // �� �л��� ��ü �ȿ� ���� ��ü�迭�� �Է¹��� ������� �����迭�� ���� �����Ѵ�.
    for (int i = 0; i < m_Subnumber; i++) //����� ��ŭ �ݺ��ϸ鼭 ������ �Է� �ޱ�
    {
        (m_Sub + i)->Subject::InputData();
    }
    CalcAveGPA(); //���� ��� ���� ����ϴ� �Լ�
}



void Student::CalcAveGPA() /* Student Ŭ���� �� ��� GPA ����ϴ� �Լ� */
{
    float tGPA = 0;
    int tHakjum = 0;
    for (int j = 0; j < m_Subnumber; j++)// ���� ��ü �� ��ŭ �ݺ�
    {
        tGPA += (m_Sub + j)->GetGPA(); // �� ���� GPA �� �� ���ϱ�      
    }
    for (int i = 0; i < m_Subnumber; i++) // �ش� �л� ��ü ���� �� ���ϱ�
    {
        tHakjum += (m_Sub + i)->GetHakjum();
    }
    m_AveGPA = (float)tGPA / tHakjum; // ��ü GPA�� ��ü �������� ������ ��� GPA ���ϱ� 
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

void Student::Modify()
{
    cout << "������ ������ �Է��ϼ���: ";
    string menu;
    cin >> menu;
    cin.ignore();
    if (menu == "�л�����")//�л�������� �Ҷ�
    {
        cout << "<" << m_StdName << " ," << m_Hakbun << ">" << "�� ������ �����ϼ��� \n"; //�����ϰ� ���� �л������� ����Ѵ�.
        cout << "�̸�: ";
        InputUtil::InputValue(m_StdName); //�����ϰ� ���� �л��� �̸����� ���� �̸����� ���Ӱ� �ٲ��ش�. 
        cout << "�й�: ";
        InputUtil::InputValue(m_Hakbun); //�����ϰ� ���� �л��� �й����� ���� �й����� ���Ӱ� �ٲ��ش�. 
        CalcAveGPA();//���� ��� ������ ������ִ� �Լ�
    }
    else if (menu == "��������")
    {
        Subject* SearchSub; // SearchSub�� ������ ����
        string subname;
        InputUtil::InputValue(subname);
        SearchSub = SubSearch(subname);// Ư�� ������ ã�� �Լ� ȣ���� �Ͽ� SearchSub�� �־��ش�.
        if (SearchSub != NULL)
        {
            SearchSub->Subject::Modify(); //���������� �����ϴ� �Լ� ȣ��
            CalcAveGPA();
        }
        else //������������ NULL���� ��ȯ �޾��� ��
        {
            cout << " �ٽ� �Է����ּ���.\n";
            Student::Modify();
        }

    }
    else if (menu == "���")//��ζ�� �Է� �޾��� ��
    {
        cout << "<" << m_StdName << " ," << m_Hakbun << ">" << "�� ������ �����ϼ��� \n"; //�����ϰ� ���� �л������� ����Ѵ�.
        cout << "�̸�: ";
        InputUtil::InputValue(m_StdName); //�����ϰ� ���� �л��� �̸����� ���� �̸����� ���Ӱ� �ٲ��ش�. 
        cout << "�й�: ";
        InputUtil::InputValue(m_Hakbun); //�����ϰ� ���� �л��� �й����� ���� �й����� ���Ӱ� �ٲ��ش�. 
        CalcAveGPA();//���� ��� ������ ������ִ� �Լ�
        Subject* SearchSub; // SearchSub�� ������ ����
        string subname;
        InputUtil::InputValue(subname);
        SearchSub = SubSearch(subname);// Ư�� ������ ã�� �Լ� ȣ���� �Ͽ� SearchSub�� �־��ش�.
        if (SearchSub != NULL)
        {
            SearchSub->Subject::Modify(); //���������� �����ϴ� �Լ� ȣ��
            CalcAveGPA();
        }
        else //������������ NULL���� ��ȯ �޾��� ��
        {
            cout << " �ٽ� �Է����ּ���.\n";
            Student::Modify();
        }
    }
    else
    {
        cout << " �ٽ� �Է����ּ���.\n";
        Student::Modify();
    }
    
}



string Student::GetName()const// �л��̸� ������ ������ �� �ִ� ������ �Լ�
{
    return m_StdName;
}

int Student::GetHakbun()const//�й� ������ ������ �� �ִ� ������ �Լ�
{
    return m_Hakbun;
}

int Student::GetSubNum()const//����� ������ ������ �� �ִ� ������ �Լ�

{
    return  m_Subnumber;
}

float Student::GetAveGPA()const//��� ������ ������ �� �ִ� ������ �Լ�
{
    return m_AveGPA;
}

Subject *Student::SubSearch(string subname)//�����̸��� �˻��Ͽ� ������ ������ ã�´�
{
    
    for (int i = 0; i < m_Subnumber; i++)
    {
        if (subname == (m_Sub + i)->Subject::GetName()) // �Է��� �̸��� �ش� ������ ���ٸ� �ش� ���� Ŭ���� �ּ� ��ȯ

            return &m_Sub[i];

    }
    cout << "\n�ش� ������ �����ϴ�.";//�ش� ������ ������ ���� �޽����� ����ϰ� NULL���� ��ȯ

    return NULL;

}

