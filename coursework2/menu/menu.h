#pragma once
#include"curses.h"
#include"../app/app.h"
class menu {
public:
	// —оздает окно в котором будут реалиованы 3 надписи
	WINDOW* getwin();
	// —читывает нажатие клавиш пользоваетелем ("s" или "e")
	void window();
};