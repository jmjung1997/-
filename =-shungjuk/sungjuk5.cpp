/**************************************************/
/*             HW#5 : ������ �Լ� ���                                                  */
/*  �ۼ��� : �����                                ��¥ : 2021�� 4�� 9��  */
/*                                                                                                     */
/* ���� ���� : ������ ����� �����ϴ� ����ó�� ���α׷� �ۼ� (���α׷� �� : sungjuk5.cpp)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/


#include <iostream>
#include<string> 
#include <stdlib.h>
using namespace std;

inline void PrintMenu();

struct Subject {// ���� ���� 
    string SubName;        // �����̸� 
    int Hakjum;                   // �������� 
    string Grade;             // ������ 
    float GPA;                    // ���� ���� 
};

struct Student {// �л� ���� 
    string StdName; // �л��̸� 
    int Hakbun; // �й� 
    Subject* Sub; // ���� 
    float AveGPA;   // ������ ��� ���� 
    int Subnumber;//�л��� ���� �����
};

void PrintMenu(); //menu����Լ�
void CalcGPA(Subject& sub);// GPA�� ������ִ� �Լ�
float CalcAveGPA(Subject* Sub, int Subnumber); //��� GPA�� ������ִ� �Լ�
void PrintAllData(const Student* rst, int StdNum); // ��� �����͸� ����ϴ� �Լ�
void PrintOneData(const Student& rst); // �ϳ��� �����͸� ����ϴ� �Լ�
void PrintAllStdList(Student* pSt, int StudnetNum);
inline void InputValue(string &str);
inline void InputValue(int& i);
void ModifyStdInfo(Student* pSt);
Student* StdSearch(Student* rst, int Stdnum); //Stdsearch ����ü ����
void InputData(Student* stu, int StudentNum);// �л� ������ �Է����ִ� �Լ�

void line();//�� �ߴ� �Լ� ����
float number_grade(char grade); //�� grade�� ������ �ٲ� �ִ� �Լ�








int main()
{
    PrintMenu();//�ζ��� �Լ� ȣ��
    int number;
    int StdNum = 0;
    cout << "�л����� �Է��ϼ���: ";  //�л����� �Է��Ѵ�
    InputValue(StdNum);
    Student* st = new Student[StdNum]; //�Է¹��� �л� �� ��ŭ �����Ҵ����� ����ü �迭�� ������ش�
    while (1) {

        cout << "\n���ϴ� ����� �Է��ϼ���: ";
        InputValue(number);
        switch (number)// switch���� ���Ͽ� �޴� ��� ����� �� ������
        {

        case 1: //�л��� ������ �Է� �޴� �޴�
        {

            InputData(st, StdNum); //�л� ������ �Է��ϴ� �Լ� ȣ��

            break;
        }
        case 2:// ��ü �л��� ������ ���� �޴�
        {

            cout << "\n\n\n��ü �л� ��������\n\n\n ";

            PrintAllData(st, StdNum); //��� �л��� ���� ����ϱ�

            break;

        }
        case 3: //Ư�� �л��� ã�� �޴� ���
        {
            Student* SearchStd; // SearchStd ����ü ������ ���� 
            SearchStd = StdSearch(st, StdNum);//Ư���л��� ã�� �Լ� ȣ��
            if (SearchStd != NULL)
                PrintOneData(*SearchStd);//���� ������ ������ �л����� ���
            else
                cout << "\n�����Դϴ�. �ٽ��Է����ּ���.\n";//���� ������ NULL ���� ��ȯ �ް� ���� �޽��� ���
            break;

        }
        case 4:
        {
            PrintAllStdList(st, StdNum);//��ü �л� ��Ϻ��� ���
            break;
        }
        case 5:
        {
            Student* SearchStd2; // SearchStd ����ü ������ ���� 
            SearchStd2 = StdSearch(st, StdNum);//Ư���л��� ã�� �Լ� ȣ���� �Ͽ� SearchStd2�� �ش��ϴ� �л� ���� �ּ� ����
            if (SearchStd2 != NULL)
            {
                ModifyStdInfo(SearchStd2); //�л������� �����ϴ� �Լ� ȣ��
            }
            else //NULL�� ��ȯ�� ���� �޽��� ���
            {
                cout << "\n�����Դϴ�. �ٽ��Է����ּ���.\n";
            }
            break;
        }


        case 6: //���� �����ϱ�, �����Ҵ�� �޸� �����ϱ�         
        {   cout << "�޸��Ҵ��� �����մϴ�";
        for (int i = 0; i < StdNum; i++) //�л� ����ü �ȿ� �ִ� ���� ����ü �޸𸮺��� ����
        {
            delete[](st + i)->Sub;
        }
        delete[] st; //�л� ����ŭ ���� �����Ҵ�� �޸� ����
        exit(0);
        break;

        }
        }

    }
}

void InputData(Student* stu, int StudentNum) //�л��� ������ �Է� �޴��Լ�
{
    for (int i = 0; i < StudentNum; i++) //�л����� ���� �޾� �л��� ��ŭ �ݺ��Ѵ�.
    {
        cout << "*" << i + 1 << " ��° �л� �̸��� �й��� �Է��ϼ���.\n";
        cout << "�̸� : ";
        InputValue(stu[i].StdName); //�����Ҵ����� ���� ����ü �迭�� �л��̸� �ֱ�
        cout << "�й�: ";
        InputValue(stu[i].Hakbun);//�����Ҵ����� ���� ����ü �迭�� �л� �й� �ֱ�
        int Subnum = 0;
        cout << "������ ���� ���� �Է� : "; //������ ���� �� �Է�
        InputValue(Subnum);
        (stu + i)->Sub = new Subject[Subnum]; // �� �л��� ����ü �迭 �ȿ� ���� ����ü�迭�� �Է¹��� ������� �����迭�� ���� �����Ѵ�.
        (stu + i)->Subnumber = Subnum; // ��ü �Լ��� ����ϱ� ���� �Է� ���� ���� ���� �л� ����ü Subnumber�� �־��ش�
        cout << "*" << "������ ������ �� �������, ��������, �������� �Է��ϼ���.\n";
        for (int k = 0; k < Subnum; k++) //�Է� ���� ����� ���� �ݺ��ϸ鼭 ������ �Է� �޴´�
        {
            cout << "�������: ";
            InputValue(stu[i].Sub[k].SubName);
            cout << "��������: ";
            InputValue(stu[i].Sub[k].Hakjum);
            cout << "������<A+ ~F>: ";
            InputValue(stu[i].Sub[k].Grade);
            cout << "\n\n";

        }
        for (int k = 0; k < Subnum; k++)//CalcGPA�� ȣ���Ͽ� �� �л��� �� ���� GPA ����ϱ�
        {
            CalcGPA(stu[i].Sub[k]);
        }
    }

    for (int j = 0; j < StudentNum; j++) // ��� ���� ����ϱ�
    {
        stu[j].AveGPA = CalcAveGPA(stu[j].Sub, (stu + j)->Subnumber);

    }

}




inline void InputValue(string &str)//�����͸� �Է� �޴� �Լ� ,�ζ����Լ� �����ε�
{
  
    getline(cin, str);
    
}

inline void InputValue(int& i)//�����͸� �Է� �޴� �Լ� ,�ζ����Լ� �����ε�
{  
    cin >> i;
    cin.ignore();
}

void line()
{
    cout << "\n============================================\n";
}



inline void PrintMenu() //�޴� ����Լ� �ζ��� �Լ� 
{
    cout << "-----------�޴�-------------\n" << "1. �л� ���� �Է�\n" << "2. ��ü �л� ���� ����\n" << "3. �л� �̸� �˻�\n" << "4. ��ü �л� ��� ����\n" << "5. �л� ���� ����\n" << "6. ���α׷� ����\n\n";


}

void PrintAllData(const Student* pst, int StudentNum)// ��� �л� �����͸� ����ϱ�, �Ű����� ������ ����
{
    for (int i = 0; i < StudentNum; i++)
    {
        PrintOneData(pst[i]);//�� �л��� ������ ����� ��ŭ ����ϱ�
    }

}

void PrintAllStdList(Student* pSt, int StudentNum)// ��ü �л��̸��� �й��� ����ϴ� �Լ� 
{
    line();
    cout.width(10);
    cout << "�̸�";
    cout.width(10);
    cout << "�й�\n";
    line();
    for (int i = 0; i < StudentNum; i++) //�л��� ��ŭ �л��̸�, �й� ����ϱ�
    {
        cout.width(10);
        cout << pSt[i].StdName; // �̸� ����ϱ�
        cout.width(10);
        cout << pSt[i].Hakbun;//�й� ����ϱ�
        cout << "\n\n";
    }
    line();
}

float number_grade(string grade) //����� ������ ��ȯ���� �ִ� �Լ�
{

    if (grade== "A+" )
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





void CalcGPA(Subject& Sub) //GPA���� ����ϴ� �Լ�, &Sub�� ���۷��� �Լ� �̹Ƿ� ������ ���� �޴´�. 
{

    float score = 0;
    score = number_grade(Sub.Grade); //����� ����ȭ ���� score ������ �����Ѵ�.

    Sub.GPA = score * Sub.Hakjum; // Score*������ ���� GPA�� ����Ѵ�.
}

float CalcAveGPA(Subject* Sub, int Subnumber) /* ��� GPA ����ϱ�,�̶� �Ű����� *Sub�̹Ƿ� �ּҰ����� ȣ���Ѵ�.
                                                    ��ü �л� ��Ż ������ ���ϱ� ���� Subnumber ���� ���� �޴´� */
{


    float AveGPA;
    float tGPA = 0;
    int tHakjum = 0;
    for (int j = 0; j < Subnumber; j++)// ���� ��ü �� ��ŭ �ݺ�
    {
        tGPA += Sub[j].GPA; // �� ���� GPA �� �� ���ϱ� 
    }
    for (int i = 0; i < Subnumber; i++) // �ش� �л� ��ü ���� �� ���ϱ�
    {
        tHakjum += Sub[i].Hakjum;
    }
    return AveGPA = (float)tGPA / tHakjum; // ��ü GPA�� ��ü �������� ������ ��� GPA ���ϱ� 
}


void PrintOneData(const Student& rst) // �Ѹ��� �л� ������ ����ϴ� �Լ�, �Ű������� ���۷��� ������ �����Ƿ� ���� ���·� ���� �޾ƾ��Ѵ�.
{


    line();

    cout.width(10);
    cout << rst.StdName; //�ش� rst�� �ش��ϴ� �̸� ���
    cout.width(10);
    cout << rst.Hakbun; //�ش� rst�� �ش��ϴ� �й� ���
    line();
    cout.width(10);
    cout << "�����";
    cout.width(10);
    cout << "��������";
    cout.width(10);
    cout << "������";
    cout.width(10);
    cout << " ��������\n";
    for (int j = 0; j < rst.Subnumber; j++) // �л��� ���� ���� ���� ���
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
    cout << "�������";
    cout.width(10);
    cout.precision(2);
    cout << fixed;
    cout << rst.AveGPA; //rst�� �ش��ϴ� �л� ��� ���� ����ϱ�
    cout << "\n\n\n\n";
}



Student* StdSearch(Student* rst, int StdNum) /*Ư�� �л��� ã�� �Լ�, �Ű������� ����ü �����ͺ����̹Ƿ� �ּҰ����� ȣ�� �޾ƾ��Ѵ�.
                                              �л����� int StdNum���� �޴´�*/
{
    string name;
    cout << "�˻� �� �л� �̸�: ";
    InputValue(name);
    for (int i = 0; i < StdNum; i++)
    {
        if (name==rst[i].StdName) // �Է��� �̸��� �л� �̸��� ���ٸ� �ش� �л� ����ü �ּ� ��ȯ
            return &rst[i];
    }
    cout << "\n�ش� �л��� �����ϴ�.";//�ش� �̸��� ������ ���� �޽����� ����ϰ� NULL���� ��ȯ

    return NULL;

}







void ModifyStdInfo(Student* pSt)/*�л��� ������ �����ϴ� �Լ�,
���ϴ� �л������� Student* StdSearch(Student* rst)�� ���� ã�� ������ ���� pst�� �����Ѵ�.*/
{

    cout << "<" << pSt->StdName << "," << pSt->Hakbun << ">" << "�� ������ �����ϼ��� \n"; //�����ϰ� ���� �л������� ����Ѵ�.
    cout << "�̸�: ";
    InputValue(pSt->StdName); //�����ϰ� ���� �л��� �̸����� ���� �̸� ����ü ���� ���Ӱ� �ٲ��ش�. 
    cout << "�й�: ";
    InputValue(pSt->Hakbun); //�����ϰ� ���� �л��� �й����� ���� �й� ����ü ���� ���Ӱ� �ٲ��ش�. 
}
