/**************************************************/
/*             HW#8 : Ŭ���� ����                                                */
/*  �ۼ��� : �����                                ��¥ : 2021�� 5�� 7��  */
/*                                                                                                     */
/* ���� ���� : ������ ����� �����ϴ� ����ó�� ���α׷� �ۼ� (���α׷� �� : Student.h)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include<string> 
using namespace  std;
#ifndef Student_H
#define Student_H
class Student {// �л� ���� Ŭ���� 
public://�Լ��� �ִ� ������ ��� Ŭ������ �ۿ��� ������ ����Ѵ�.
    Student();//����Ʈ ������
    Student(string name, int hakbun,int subnum, Subject* sub);//�Ű������� �ִ� ������
    Student(const Student& std);//const ��������� ���۷��� ��������� �ʱ�ȭ
    ~Student();//�Ҹ��� 
   
    void InputData(); // ������� �� �Է�
    void printData(); // ������� �� ���
    void CalcAveGPA(); // ��� ���� ���
    
    string GetName()const; // �л��̸� ������ ������ �� �ִ� ������ �Լ�
    int GetHakbun()const;//�й� ������ ������ �� �ִ� ������ �Լ�
    int GetSubNum()const;//����� ������ ������ �� �ִ� ������ �Լ�
    float GetAveGPA()const;//��� ������ ������ �� �ִ� ������ �Լ�
    void Modify();//�л������� �����ϴ� �Լ�
    Subject* SubSearch(string subname);//Ư�������� ã���Լ�
protected://��� ������ Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
    string m_StdName; // �л��̸� 
    int m_Hakbun; // �й� 
    Subject* m_Sub; // ���� 
    float m_AveGPA;   // ������ ��� ���� 
    int m_Subnumber;//�л��� ���� �����
};
#endif