#include <iostream> 
#include "Convert.h"
#include <fstream> //��� ������ � �������
#define MAX_LINE 20 //������ ������ ��� ���� ������������
using namespace std;
int main()
{
	int ERR;
	Convert a;
	setlocale(LC_ALL, "rus");//����������� ��������� � �������� �������
	int  choise = 1;
	char str[MAX_LINE];//��������� ������ ��� ����� ������ � ������
	while (choise==1)
	{
		cout << "1 - �������������� ���������� ������ � ��� �����\n2 - �������������� ���� ����� � ��������� �����\n3 - �����\n\n";//���������� ��� ������������
		cout << "�������� �������: ";
		gets_s(str);
		system("cls");
		choise = atoi(str);
		switch (choise)
		{
		case 1: system("cls");
			if ((ERR = a.openfile()) == 0)
				a.ConvertToMorze();
			break;
		case 2: system("cls");
			if ((ERR = a.openfile()) == 0)
			a.ConvertFromMorze();
			break;
		case 3: system("cls");
			return 0;
		default:
			cout << "������ �����\n";
		}
		cout << "\n�������� � ���������? (1 - ��): ";
		gets_s(str);
		choise = atoi(str);
		system("cls");
	}
}