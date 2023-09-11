#include "OutIn.h"
#include<iostream>
#include<fstream>
#define sto 100
void WriteIn::Out(int a, int b)
{
	std::cout << "Enter Output File Name  - ";
	char ar[80];
	std::cin >> ar;  // Принимает имя файла введенное пользоваетелем
	std::ofstream fout(ar);
	fout << "First:" << a << "  Second:" << b << " Draw: " << sto - a - b << std::endl;  // Выводит данные в файл
	fout.close();
}
