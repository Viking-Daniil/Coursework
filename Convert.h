#ifndef CONVERT_H
#define CONVERT_H
#include <iostream>
#include <fstream>
#define MAX_LINE 20       //������ ������ ��� ���� ������������
using namespace std;
class Convert
{
private:
	ifstream in;
	ofstream out; //���� ��� ������
	char str[MAX_LINE];//��������� ������ ��� ����� ������ � ������
	string text;
public:
	int  openfile();//����
 void ConvertToMorze();
 void ConvertFromMorze();
	~Convert();
};
#endif 
