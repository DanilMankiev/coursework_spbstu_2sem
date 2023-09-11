#include "app.h"
#include"../Data/DataBase.h"
#include"../logics/GameAlgorithm.h"
#include"../logics/OutIn.h"
#define sto 100
void Program::Exec()
{
	Factory factor;  // �������� �������
	DataBase db;     // �������� ���� ������
	db["First"] = factor.getPlayer(0, 0, male);  // �������� ������� ������
	db["Second"] = factor.getPlayer(0, 0,none);  // �������� ������� ������
	Game game1(&db["First"], &db["Second"]);
	for (int i = 0; i < sto; i++) {
		game1.process().GetNumberA()++;   // ���������� NumberA ����������
		db["First"].GetScore() = 0;
		db["Second"].GetScore() = 0;
	}
	WriteIn o;
	o.Out(db["First"].GetNumberA(), db["Second"].GetNumberA()); // ������ � ���� �����������
}
