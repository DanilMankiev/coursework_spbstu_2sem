#pragma once
#include"curses.h"
#include"../app/app.h"
class menu {
public:
	// ������� ���� � ������� ����� ���������� 3 �������
	WINDOW* getwin();
	// ��������� ������� ������ �������������� ("s" ��� "e")
	void window();
};