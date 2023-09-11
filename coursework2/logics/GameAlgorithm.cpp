#include "GameAlgorithm.h"
Game::Game(Player* first, Player* second)
{
	_first = first;
	_second = second;
}
Player& Game::process() {
	Player* draw = new Player();
	_first->GetAnother(6);  // Первый игрок получает определенное значение близкое к 21
	_second->GetAnother(6); // Второй игрок получает определенное значение близкое к 21
	if (_first->GetScore() <= 21 && _second->GetScore() <= 21) {

		return (_first->GetScore() > _second->GetScore() ? _first->GetThis() : _first->GetScore() == _second->GetScore() ? draw->GetThis() : _second->GetThis());
	}
	else if (_first->GetScore() > 21 && _second->GetScore() <= 21) {
		return _second->GetThis();
	}
	else if (_first->GetScore() <= 21 && _second->GetScore() > 21) {
		return _first->GetThis();
	}
	else if (_first->GetScore() > 21 && _second->GetScore() > 21) {
		return (_first->GetScore() < _second->GetScore() ? _first->GetThis() : _first->GetScore() == _second->GetScore() ? draw->GetThis() : _second->GetThis());
	}
}
