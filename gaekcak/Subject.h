/**************************************************/
/*             HW#8 : Ŭ���� ����                                                */
/*  �ۼ��� : �����                                ��¥ : 2021�� 5�� 7��  */
/*                                                                                                     */
/* ���� ���� : ������ ����� �����ϴ� ����ó�� ���α׷� �ۼ� (���α׷� �� : Subject.h)                                                                            */
/*                - - - - - - -                                                                      */
/*************************************************/
#include<string> 
using namespace  std;
#ifndef Subject_H
#define Subject_H
class Subject //�������� Ŭ����
{
public://�Լ��� �ִ� ������ ��� Ŭ������ �ۿ��� ������ ����Ѵ�.
    Subject();//����Ʈ ������
    Subject(string name, int Hakjum,string Grade);//�Ű� ������ �ִ� ������
    Subject(const Subject& sub);//const ��������� ���۷��� ��������� �ʱ�ȭ
    ~Subject();//�Ҹ���

    void Initialize(string, int, string);//�Լ������ε� �Ű������� �ִ� �ʱ�ȭ �Լ�
    
    void InputData();// ���� ������ ���� �ִ� �Լ�

    static void printTitle();//�����, ��������, ������, ���������� Ÿ��Ʋ�� ����ϴ� �Լ�
    void printData();//�����, ��������, ������, ���������� �����͸� ����ϴ� �Լ�
    void CalcGPA();//���� ���� ����ϴ� �Լ�

    string GetName()const;//�����̸��� ������ �� �ִ� ������ �Լ�
    int GetHakjum() const;//���� ������ ������ �� �ִ� ������ �Լ�
    string GetGrade()const;//�������� ������ �� �ִ� ������ �Լ�
    float GetGPA() const;//���������� ������ �� �ִ� ������ �Լ�
    void Modify();//���������� �����ϴ� �Լ�
    
protected://��� ������ Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
    string m_name;        // �����̸� 
    int m_Hakjum;         // �������� 
    string m_Grade;       // ������ 
    float m_GPA;          // ���� ���� 
};

#endif