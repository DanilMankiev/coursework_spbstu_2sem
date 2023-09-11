#pragma once
#include"../logics/MyString.h"
#include"../logics/Player.h"

class Pair
{
	MyString _name;  // ������ ��� ������
	Player _data;    // ������ ������ ������
public:
	// ���������� ��� ������
	MyString& GetName();
	bool operator==(const char* name);
	Pair();
	Pair(const char* name, Player newData);
	friend class DataBase;
};
class DataBase {
	Pair** records;  // ������ ������ � ���� ��� - ������ (���� - �������)
	int size;        // ������ ������ �������
	int capacity;	 // ������ ���������� ���������� �����
public:
/* ���������� �������������� ������� ������� ������� � ������ ������,
 � ���� �� ��� ����, �� �������������� ������
*/
	Player& operator[](const char* name);
	DataBase() : size(0), records(nullptr), capacity(0) {};

};