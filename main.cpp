#include <iostream> 
#include "Convert.h"
#include <fstream> //Для работы с файлами
#define MAX_LINE 20 //Размер строки под ввод пользователя
using namespace std;
int main()
{
	int ERR;
	Convert a;
	setlocale(LC_ALL, "rus");//Подключение кодировки с русскими буквами
	int  choise = 1;
	char str[MAX_LINE];//Служебная строка для ввода данных в консол
	while (choise==1)
	{
		cout << "1 - Преобразование латинского текста в код Морзе\n2 - Преобразование кода Морзе в латинский текст\n3 - Выход\n\n";//Информация для пользователя
		cout << "Выбирете команду: ";
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
			cout << "Ошибка ввода\n";
		}
		cout << "\nОстаться в программе? (1 - ДА): ";
		gets_s(str);
		choise = atoi(str);
		system("cls");
	}
}