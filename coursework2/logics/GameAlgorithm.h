#pragma once
#include"../logics/Player.h"

class Game {
	Player* _first;  
	Player* _second;
public:
	Game(Player* first, Player* second);
	// Осуществляет поиск победителя на основе механики игры и возвращяет ссылку на победителя
	Player& process();
};