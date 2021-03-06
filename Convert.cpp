#include "Convert.h"
#include <iostream>
#include <string>
#include <map> // ��� ������ � ������������� map
#include <fstream>//��� ������ � �������
using namespace std;
map <char, string> MapToMorze = {
		{ 'a',     ".-"},
		{ 'b',   "-..."},
		{ 'w',    ".--"},
		{ 'g',    "--."},
		{ 'd',    "-.."},
		{ 'e',      "."},
		{ 'v',   "...-"},
		{ 'z',   "--.."},
		{ 'i',     ".."},
		{ 'j',   ".---"},
		{ 'k',    "-.-"},
		{ 'l',   ".-.."},
		{ 'm',     "--"},
		{ 'n',     "-."},
		{ 'o',    "---"},
		{ 'p',   ".--."},
		{ 'r',    ".-."},
		{ 's',    "..."},
		{ 't',      "-"},
		{ 'u',    "..-"},
		{ 'f',   "..-."},
		{ 'h',   "...."},
		{ 'c',   "-.-."},
		{ 'q',   "--.-"},
		{ 'y',   "-.--"},
		{ 'x',   "-..-"},
		{ '1',  ".----"},
		{ '2',  "..---"},
		{ '3',  "...--"},
		{ '4',  "....-"},
		{ '5',  "....."},
		{ '6',  "-...."},
		{ '7',  "--..."},
		{ '8',  "---.."},
		{ '9',  "----."},
		{ '0',  "-----"},
		{ '.', "......"},
		{ ',', ".-.-.-"},
		{ ':', "---..."},
		{ ';', "-.-.-."},
		{ '(', "-.--.-"},
		{ ')', "-.--.-"},
		{ '"', ".-..-."},
		{ '-', "-....-"},
		{ '/',  "-..-."},
		{ '?', "..--.."},
		{ '!', "--..--"},
		{' ',       " "},
		{ '@', ".--.-."},
		{ '$',"...-..-"},

};
map <string, string> MapFromMorze = {
		{ ".-",      "a"},
		{ "-...",    "b"},
		{ ".--",     "w"},
		{ "--.",     "g"},
		{ "-..",     "d"},
		{ ".",       "e"},
		{ "...-",    "v"},
		{ "--..",    "z"},
		{ "..",      "i"},
		{".---",     "j"},
		{"-.-",      "k"},
		{".-..",     "l"},
		{"--",       "m"},
		{"-.",       "n"},
		{"---",      "o"},
		{".--.",     "p"},
		{".-.",      "r"},
		{ "...",     "s"},
		{"-",        "t"},
		{"..-",      "u"},
		{"..-.",     "f"},
		{"....",     "h"},
		{"-.-.",     "c"},
		{"--.-",     "q"},
		{"-.--",     "y"},
		{"-..-",     "x"},
		{".----",    "1"},
		{"..---",    "2"},
		{"...--",    "3"},
		{"....-",    "4"},
		{".....",    "5"},
		{"-....",    "6"},
		{"--...",    "7"},
		{"---..",    "8"},
		{"----.",    "9"},
		{"-----",    "0"},
		{"......",   "."},
		{".-.-.-",   ","},
		{"---...",   ":"},
		{"-.-.-.",  ";",},
		{"-.--.-", "(", },
		{"-.--.-",   ")"},
		{".-..-.",  "\""},
		{"-....-",   "-"},
		{"-..-.",    "/"},
		{"..--..",   "?"},
		{"--..--",   "!"},
		{" ",        " "},
		{".--.-.",   "@"},
		{"...-..-",  "$"},
};

int Convert::openfile()
{
	cout << "������� �������� ����� ��� ������:\n";
	gets_s(str);
	try
	{
		in.open(str);
		if (!in)//������ �������� �����
		{
			exception err("������ �������� �����. �������� ������ ����� �� ����������.\n");
			throw err;
		}
		if (in.peek() == -1)
		{
			exception err("\n����������� ���� ������\n");
			throw err;
		}
	}
	catch (exception& err)
	{
		cout << err.what() << endl << endl;
		in.close();
		return 1;
	}
	return 0;
}
Convert::~Convert()
{
	str[0] = '\0';
	text[0] = '\0';
}
 void Convert::ConvertToMorze()
 {
	 int m = 0;
	 cout << "��������� �������� ����� �������� ��������� ���� 'out1.txt', ������ ������ ����� �������, �������������? (1 - ��):  ";
	 gets_s(str);
	 m = atoi(str);
	 if (m != 1)
	 {
		 in.close();
		 return;
	 }
	else
	{
		out.open("out1.txt");
		cout << "��������� �������� �������� � ��� �����:\n";
		while (getline(in, text))
		{
			for (int i = 0; i < text.length(); i++)
			{
				text[i] = tolower(text[i]);
				cout << MapToMorze.find(text[i])->second << " "; //���� ���� �������������� �����, ������� ���� �������, ������� ������ ��������
				out << MapToMorze.find(text[i])->second << " ";
			}
			cout << "\n";
			out << "\n";
		}
		out.close();
	}
 }
 void Convert::ConvertFromMorze()
 {
	 char s2[50];
	 for (int l = 0; l < 50; l++)
		 s2[l] = 0;
	 int m = 0;
	 cout << "��������� �������� ����� �������� � ��������� ���� 'out2.txt', ������ ������ ����� �������, �������������? (1 - ��):  ";
	 gets_s(str);
	 m = atoi(str);
	 if (m != 1)
	 {
		 in.close();
		 return;
	 }
	 else
	 {
		 out.open("out2.txt");
		 cout << "��������� �������� ���� ����� � ��������:\n";
		 while (getline(in, text))
		 {
			 int c = 0;
			 for (int i = 0; i < text.length(); i++)
			 {
				 if (text[i] != ' ')
				 {
					 s2[c] = text[i];
					 c++;
				 }
				 else
				 {
					 s2[c] = '\0';
					 cout << MapFromMorze[s2];
					 out << MapFromMorze[s2];
					 if (text[i + 1] == ' ')
					 {
						 cout << " ";
						 out << " ";
					 }
					 c = 0;
				 }
			 }
			 cout << " \n";
			 out << "\n";
		 }
		 out.close();
	 }
 }