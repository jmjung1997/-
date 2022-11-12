/**************************************************/
/*             HW#8 : �����ڿ� �Ҹ���                                               */
/*  �ۼ��� : �����                                ��¥ : 2021�� 5�� 14��  */
/*                                                                                                     */
/* ���� ���� : ������ ����� �����ϴ� ����ó�� ���α׷� �ۼ� (���α׷� �� : main.cpp)                                                                            */
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
    Subject sub1("��ǻ��", 3, "C0");//�Ű����� �ִ� ���·� �������� �ʱ�ȭ
    Subject sub2(sub1); //const ���� ���·� ���������� sub1�� ������ �����Ѵ�.
    cout << "\n" << "sub1 ����" << "\n";
    line();
    sub1.Subject::printData();//sub1 ���������� ���Ͽ� ���
    cout << "\n" << "sub2 ����" << "\n";
    line();
    sub2.Subject::printData();//sub2 ���������� ���Ͽ� ���
    sub2.Subject::Modify();
    Student st2("ȫ�浿", 2013909845, 1, &sub1);
    Student st3("�輺��", 2015909845, 1, &sub2);
    Student st1(st2);//���������ڸ� ���� st1��ü�� ������ ���� �����Ͽ����ϴ�.
    cout << "\n" << "st1 ����" << "\n";
    line();
    st1.Student::printData();//st1 ���� ���
    cout << "\n" << "st2 ����" << "\n";
    line();
    st2.Student::printData(); //st2 ���� ���
    st2.Student::Modify();//st2 ���� ����
    cout << "\n" << "������ st2 ����" << "\n";
    line();
    st2.Student::printData(); //������ st2 �л����� ��� 
    st1.Student::printData();//st1���� ����ؼ� ���� �����ڰ� ����� �ƴ��� Ȯ���ϱ�
    cout << "\n" << "st3 ����" << "\n";
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
    Subject* sub = std.SubSearch("������");
    // ������� ���������� Ž���� ���
    // �ش� ���������� �ִ� �޸� �ּҸ� ����
    if (sub != NULL)
    {
        sub->printTitle();
        sub->printData();
    }
    return 0;
}
*/
void Data(const Student& s) { // �������α׷��� �ִ� �����Լ�
    cout << s.GetName() << "�� ������ ������ ��" << s.GetSubNum() << "����";
    cout << "������ ������ ���������" << s.GetAveGPA() << "�Դϴ�.\n";
}

int main() 
{
    Subject sub1("��ǻ��", 3, "C0");
    Subject sub2("����", 2, "A0");
    Subject::printTitle();
    sub1.printData();
    sub2.printData();
    Student st1("ȫ�浿", 2013909845, 1, &sub1);
    st1.printData();
    Data(st1);
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



void line()
{
    cout << "\n============================================\n";
}



