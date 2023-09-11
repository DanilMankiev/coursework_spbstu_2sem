#pragma once
#include"../logics/MyString.h"
enum Sex { male, female, none };

class PlayerAbstract {
protected:
	int _Score;  // ����������� ����� ������
	int _NumberActor;  // ����������� ���������� ������
	Sex _sex;  // ��� ������
public:
	// ���������� ��� ���������� ������ ���������� 
	bool operator==(PlayerAbstract& ComparePlayer);
	// ����� �������� ��������� �������� �� 1 �� 6 � ����������� �� ������������
	void GetAnother(int dice);
	// ���������� true, ���� _Score >21 
	bool IsLoser();
	// ��������������� ������ � _NumberActor
	int& GetNumberA();
	// ������������� ������ � ���� ������ (sex)
	int& GetScore();
	
	// ������ ���������� ������ �� ���� 
	virtual PlayerAbstract& GetThis() = 0;
	// ������������� ������ � sex
	virtual Sex GetSex() = 0;

};

class Player : public PlayerAbstract
{
public:
	// ���������� ��������� ��� ������ Player
	Player operator=(Player NewPlayer);
	// ������������� ������ � sex
	Sex GetSex();
	// ������ ���������� ������ �� ���� 
	Player& GetThis();
	Player();
	Player(int Score, int NumberActor, Sex sex);
	
};

class NonbinaryPlayer : public PlayerAbstract
{
public:
	// ���������� ��������� ��� ������ NonbinaryPlayer
	NonbinaryPlayer operator=(NonbinaryPlayer NewPlayer);
	// ������ ���������� ������ �� ���� 
	NonbinaryPlayer& GetThis();
	// ������������� ������ � sex
	Sex GetSex();
	NonbinaryPlayer();
	NonbinaryPlayer(int Score, int NumberActor);

};

class Factory {
public:
	// ������� ��������� ���� Player
	Player& getPlayer(int Score, int NumberActor, Sex sex);
	// ������� ��������� ���� NonbinaryPlayer
	NonbinaryPlayer& getPlayerA(int Score, int NumberActor);
};
