/*************************************************/


#include <iostream>
#include<string> 
#include <stdlib.h>
using namespace std;

inline void PrintMenu();

struct Student {// �л� ���� 
    string StdName; // �л��̸� 
    int Hakbun; // �й� 
    Subject* Sub; // ���� 
    float AveGPA;   // ������ ��� ���� 
    int Subnumber;//�л��� ���� �����
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
    string m_name;        // �����̸� 
    int m_Hakjum;                   // �������� 
    string m_Grade;             // ������ 
    float m_GPA;                    // ���� ���� 
};



void PrintMenu(); //menu����Լ�
void CalcGPA(Subject& sub);// GPA�� ������ִ� �Լ�
float CalcAveGPA(Subject* Sub, int Subnumber); //��� GPA�� ������ִ� �Լ�
void PrintAllData(const Student* rst, int StdNum); // ��� �����͸� ����ϴ� �Լ�
void PrintOneData(const Student& rst); // �ϳ��� �����͸� ����ϴ� �Լ�
void PrintAllStdList(Student* pSt, int StudnetNum);
inline void InputValue(string& str);
inline void InputValue(int& i);
void ModifyStdInfo(Student* pSt);
void ModifySubInfo(Subject* Sub);
Student* StdSearch(Student* rst, int Stdnum); //Stdsearch ����ü ����
void InputData(Student* stu, int StudentNum);// �л� ������ �Է����ִ� �Լ�
Subject* SubjectSearch(const Student* pSt);
void line();//�� �ߴ� �Լ� ����
float number_grade(char grade); //�� grade�� ������ �ٲ� �ִ� �Լ�



int main()
{
    Subject sub1, sub2, sub3[2], *sub4;
    int i;

    sub1.Initialize();
    sub2.Initialize("������", 3, "A+");
    for (i = 0; i < 2; i++)
    {
        sub3[i].Initialize("��ǻ��", 3, "C");
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

void Subject::InputData(Student* stu, int StudentNum) //�л��� ������ �Է� �޴��Լ�
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




inline void InputValue(string& str)//�����͸� �Է� �޴� �Լ� ,�ζ����Լ� �����ε�
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
        if (name == rst[i].StdName) // �Է��� �̸��� �л� �̸��� ���ٸ� �ش� �л� ����ü �ּ� ��ȯ
            return &rst[i];
    }
    cout << "\n�ش� �л��� �����ϴ�.";//�ش� �̸��� ������ ���� �޽����� ����ϰ� NULL���� ��ȯ

    return NULL;

}

Subject* SubjectSearch(const Student* pSt)
{
    string sub;
    cout << "�˻� �� �����̸�: ";
    InputValue(sub);
    for (int i = 0; i < pSt->Subnumber; i++)
    {
        if (sub == pSt->Sub[i].SubName) // �Է��� �̸��� �ش� ������ ���ٸ� �ش� ���� ����ü �ּ� ��ȯ

            return &pSt->Sub[i];

    }
    cout << "\n�ش� ������ �����ϴ�.";//�ش� ������ ������ ���� �޽����� ����ϰ� NULL���� ��ȯ

    return NULL;

}





void ModifyStdInfo(Student* pSt)/*�л��� ������ �����ϴ� �Լ�,
���ϴ� �л������� Student* StdSearch(Student* rst)�� ���� ã�� ������ ���� pst�� �����Ѵ�.*/
{

    cout << "<" << pSt->StdName << " ," << pSt->Hakbun << ">" << "�� ������ �����ϼ��� \n"; //�����ϰ� ���� �л������� ����Ѵ�.
    cout << "�̸�: ";
    InputValue(pSt->StdName); //�����ϰ� ���� �л��� �̸����� ���� �̸� ����ü ���� ���Ӱ� �ٲ��ش�. 
    cout << "�й�: ";
    InputValue(pSt->Hakbun); //�����ϰ� ���� �л��� �й����� ���� �й� ����ü ���� ���Ӱ� �ٲ��ش�. 

}

void ModifySubInfo(Subject* Sub)/*������ ������ �����ϴ� �Լ�,
�����ϰ� ���� ���������� Subject* SubjectSearch(const Student* pSt)�� ���� ã�� ������ ���� Sub�� �����Ѵ�.*/
{

    cout << "<" << Sub->SubName << " ," << Sub->Hakjum << " ," << Sub->Grade << ">" << "�� ������ �����ϼ��� \n"; //�����ϰ� ���� �л������� ����Ѵ�.
    cout << "�������: ";
    InputValue(Sub->SubName); //�����ϰ� ���� ����������� �ٲپ��ش� 
    cout << "��������: ";
    InputValue(Sub->Hakjum); //�����ϰ� ���� ������������ �ٲپ��ش�. 
    cout << "������: ";
    InputValue(Sub->Grade);//�����ϰ� ���� ���������� �ٲپ��ش�.



}

