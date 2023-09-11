#pragma once
#include"../logics/MyString.h"
#include"../logics/Player.h"

class Pair
{
	MyString _name;  // Хранит имя игрока
	Player _data;    // Хранит данные игрока
public:
	// Возвращяет имя игрока
	MyString& GetName();
	bool operator==(const char* name);
	Pair();
	Pair(const char* name, Player newData);
	friend class DataBase;
};
class DataBase {
	Pair** records;  // Хранит данные в виде имя - данные (ключ - значние)
	int size;        // Хранит размер массива
	int capacity;	 // Хранит количество своюодного места
public:
/* Перегрузка автоматический создает элемент массива с данным именем,
 а если он уже есть, то перезаписывает данные
*/
	Player& operator[](const char* name);
	DataBase() : size(0), records(nullptr), capacity(0) {};

};