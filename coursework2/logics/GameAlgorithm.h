#pragma once
#include"../logics/Player.h"

class Game {
	Player* _first;  
	Player* _second;
public:
	Game(Player* first, Player* second);
	// ������������ ����� ���������� �� ������ �������� ���� � ���������� ������ �� ����������
	Player& process();
};