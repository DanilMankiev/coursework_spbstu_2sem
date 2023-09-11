#include"../logics/Player.h"
#include"DataBase.h"
#include<iostream>

MyString& Pair::GetName() {
	return _name;
}
Pair::Pair(const char* name, Player newData) {
	_name = name;
	_data = newData;
}
bool Pair::operator==(const char* name) {
	return _name == name;
}

Player& DataBase::operator[](const char* name) {

	for (int i = 0; i < size; i++) {
		if (**(records + i) == name)    // ¬озвращ€ет данне об игроке
			return records[i]->_data;
	}

	if (size >= capacity) {
		Pair** tmp = new Pair * [capacity + 10];
		capacity += 10;							// —оздает элемент массива с таким именем
		for (int i = 0; i < size; i++)
		{
			tmp[i] = records[i];
		}
		delete[] records;
		records = tmp;
	}
	Player* exm = new Player;
	records[size] = new Pair(name, *exm);
	delete exm;
	return records[size++]->_data;
}