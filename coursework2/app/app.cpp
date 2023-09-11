#include "app.h"
#include"../Data/DataBase.h"
#include"../logics/GameAlgorithm.h"
#include"../logics/OutIn.h"
#define sto 100
void Program::Exec()
{
	Factory factor;  // Создание фабрики
	DataBase db;     // Создание базы данных
	db["First"] = factor.getPlayer(0, 0, male);  // Создание первого игрока
	db["Second"] = factor.getPlayer(0, 0,none);  // Создание второго игрока
	Game game1(&db["First"], &db["Second"]);
	for (int i = 0; i < sto; i++) {
		game1.process().GetNumberA()++;   // Увеличение NumberA победителя
		db["First"].GetScore() = 0;
		db["Second"].GetScore() = 0;
	}
	WriteIn o;
	o.Out(db["First"].GetNumberA(), db["Second"].GetNumberA()); // Запись в файл результатов
}
