#include<iostream>
#include"Player.h"
#include<ctime>
#include<random>
using namespace std;

bool PlayerAbstract::operator==(PlayerAbstract& ComparePlayer)
{
	if (_Score == ComparePlayer._Score && _NumberActor == ComparePlayer._NumberActor) {
		return true;
	}
	else {
		return false;
	}
}

void PlayerAbstract::GetAnother(int dice)
{
	_Score = 0;
	srand(time(0));   
	random_device rd;	// Подключенные библиотеки обеспечивает случайность выпадения
	mt19937 gen(rd());  // при каждой итерации в цикле
	uniform_int_distribution<> dist(1, dice);  // Диапвзон от 1 до 6 включительно
	uniform_int_distribution<> dist1(1, 3);    // Диапвзон от 1 до 3 включительно
	uniform_int_distribution<> dist2(1, 4);    // Диапвзон от 1 до 4 включительно
	uniform_int_distribution<> dist3(1, 10);   // Диапвзон от 1 до 10 включительно
	while (true) {
		if (_Score <= 15) {
			_Score += dist(gen);
		}
		else if (_Score == 16 || _Score == 17) {
			int probability = dist1(gen);// Диапвзон от 1 до 3 включительно
			if (probability == 1 || probability == 2) {  // Вероятность 2/3
				_Score += dist(gen);
			}
			else {
				break;
			}
		}
		else if (_Score == 18 || _Score == 19) {
			int probability = dist2(gen); // Диапазон от 1 до 4 
			if (probability == 1) {   // вероятность 1/4
				_Score += dist(gen);
			}
			else {
				break;
			}
		}
		else if (_Score == 20) {
			int probability = dist3(gen);
			if (probability == 1) {     // вероятность 1/10
				_Score += dist(gen);
			}
			else { break; }
		}
		else if (_Score == 21) {
			_Score += 0;
			break;
		}
		else if (_Score > 21) {
			break;
		}
	}
}
bool PlayerAbstract::IsLoser()
{
	if (_Score > 21) return true;
	else {
		return false;
	}
}
int& PlayerAbstract::GetScore()
{
	return _Score;
}

int& PlayerAbstract::GetNumberA()
{
	return _NumberActor;
}



Player Player::operator=(Player NewPlayer)
{
	if (*this == NewPlayer) {  // Защита от самоприсваивания
		return *this;
	}

	this->_Score = NewPlayer._Score;
	this->_NumberActor = NewPlayer._NumberActor;
	this->_sex = NewPlayer._sex;
	return *this;
}


Sex Player::GetSex()
{
	return _sex;
}

Player& Player::GetThis()
{
	return *this;
}



Player::Player() {
	_NumberActor = 0;
	_Score = 0;
	_sex = none;
}
Player::Player(int Score, int NumberActor, Sex sex) {

	_NumberActor = NumberActor;
	_Score = Score;
	_sex = sex;
}

NonbinaryPlayer NonbinaryPlayer::operator=(NonbinaryPlayer NewPlayer)
{

	if (*this == NewPlayer) {    // Защита от самоприсваивания
		return *this;
	}

	this->_Score = NewPlayer._Score;
	this->_NumberActor = NewPlayer._NumberActor;
	return *this;
}

NonbinaryPlayer& NonbinaryPlayer::GetThis()
{
	return *this;
}

Sex NonbinaryPlayer::GetSex()
{
	return none;
}


NonbinaryPlayer::NonbinaryPlayer()
{
	_NumberActor = 0;
	_Score = 0;
	_sex = none;
}

NonbinaryPlayer::NonbinaryPlayer(int Score, int NumberActor)
{
	_NumberActor = NumberActor;
	_Score = Score;
	_sex = none;
}


// Создает экземпляр типа Player
Player &Factory::getPlayer(int Score, int NumberActor, Sex sex) 
{
	Player* toreturn = new Player(Score, NumberActor, sex);
	return *toreturn;
}

// Создает экземпляр типа NonbinaryPlayer
NonbinaryPlayer &Factory::getPlayerA(int Score, int NumberActor)
{
	NonbinaryPlayer* toreturn = new NonbinaryPlayer(Score, NumberActor);
	return *toreturn;
}