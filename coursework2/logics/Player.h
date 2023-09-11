#pragma once
#include"../logics/MyString.h"
enum Sex { male, female, none };

class PlayerAbstract {
protected:
	int _Score;  // количесутво очков игрока
	int _NumberActor;  // количествао выйгранных пратий
	Sex _sex;  // пол игрока
public:
	// Сравнивает два экземпляра класса наследника 
	bool operator==(PlayerAbstract& ComparePlayer);
	// Игрок получает несколько значений от 1 до 6 в зависимости от вероятностей
	void GetAnother(int dice);
	// Возвращяет true, если _Score >21 
	bool IsLoser();
	// Предоставляется доступ к _NumberActor
	int& GetNumberA();
	// Предоставляет доступ к полу игрока (sex)
	int& GetScore();
	
	// Должно возвращять ссылку на себя 
	virtual PlayerAbstract& GetThis() = 0;
	// Предоставялет доступ к sex
	virtual Sex GetSex() = 0;

};

class Player : public PlayerAbstract
{
public:
	// Перегрузка оператора для класса Player
	Player operator=(Player NewPlayer);
	// Предоставялет доступ к sex
	Sex GetSex();
	// Должно возвращять ссылку на себя 
	Player& GetThis();
	Player();
	Player(int Score, int NumberActor, Sex sex);
	
};

class NonbinaryPlayer : public PlayerAbstract
{
public:
	// Перегрузка оператора для класса NonbinaryPlayer
	NonbinaryPlayer operator=(NonbinaryPlayer NewPlayer);
	// Должно возвращять ссылку на себя 
	NonbinaryPlayer& GetThis();
	// Предоставялет доступ к sex
	Sex GetSex();
	NonbinaryPlayer();
	NonbinaryPlayer(int Score, int NumberActor);

};

class Factory {
public:
	// Создает экземпляр типа Player
	Player& getPlayer(int Score, int NumberActor, Sex sex);
	// Создает экземпляр типа NonbinaryPlayer
	NonbinaryPlayer& getPlayerA(int Score, int NumberActor);
};
