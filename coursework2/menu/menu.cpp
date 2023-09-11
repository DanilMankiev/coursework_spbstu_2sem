#include"menu.h"
#include"curses.h"
#include<iostream>

using namespace std;
WINDOW* menu::getwin()
{
	initscr();
	int xMax, yMax;
	noecho();
	curs_set(0);
	getmaxyx(stdscr, yMax, xMax);
	WINDOW* window = newwin(yMax / 2, xMax / 2, yMax / 4, xMax / 4);  // ������� ���� ������������ ��������
	box(window, 0, 0);

	mvwprintw(window, 0, 25, "Dice Game");
	mvwprintw(window, 3, 24, "Start game(s)");  // ������� � ���� �������
	mvwprintw(window, 6, 24, "End game(e)");
	return window;
}
void menu::window()
{
	this->getwin();
	char ch;
	while (ch = wgetch(this->getwin()))  // ����������� ����, ������� ��������� ������� ������
	{
		switch (ch) {
		case 's':      // ��������� ��������� 
			wgetch(this->getwin());
			endwin();
			Program tmp;
			tmp.Exec();
			break;
		case 'e':      // ������� �� ���������
			exit(0);
			break;
		}
	}
}