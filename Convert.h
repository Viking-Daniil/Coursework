#ifndef CONVERT_H
#define CONVERT_H
#include <iostream>
#include <fstream>
#define MAX_LINE 20       //Размер строки под ввод пользователя
using namespace std;
class Convert
{
private:
	ifstream in;
	ofstream out; //Файл для запсии
	char str[MAX_LINE];//Служебная строка для ввода данных в консол
	string text;
public:
	int  openfile();//Ввод
 void ConvertToMorze();
 void ConvertFromMorze();
	~Convert();
};
#endif 
