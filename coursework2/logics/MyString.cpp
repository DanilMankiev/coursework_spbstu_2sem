#include "myString.h"
#include <iostream>
using namespace std;
char* MyString::GetString()
{
	return m_pStr;
}


void MyString::SetNewString(const char* newStr)
{
	m_pStr = new char[strlen(newStr) + 1];
	strcpy(m_pStr, newStr);

}
MyString& MyString:: operator=(const MyString& str)
{
	if (&str == this) {
		return *this;
	}
	delete[] m_pStr;
	m_pStr = new char[strlen(str.m_pStr) + 1];
	strcpy(m_pStr, str.m_pStr);
	return *this;

}
MyString MyString :: operator+(const MyString& str) {
	MyString exm;
	exm.m_pStr = new char[strlen(m_pStr) + strlen(str.m_pStr) + 1];
	strcpy(exm.m_pStr, m_pStr);
	strcat(exm.m_pStr, str.m_pStr);
	return exm;
}

MyString& MyString::operator+=(const MyString& str)
{
	char* tmp = m_pStr;
	m_pStr = new char[strlen(tmp) + strlen(str.m_pStr) + 1];
	strcpy(m_pStr, tmp);
	strcat(m_pStr, str.m_pStr);
	return *this;
}

std::ostream& operator<<(std::ostream& out, MyString& str)
{
	return out << str.m_pStr;
}
std::istream& operator>>(std::istream& in, MyString& str) {
	return in >> str.m_pStr;

}
bool MyString :: operator==(const char* str) {
	return strcmp(m_pStr, str) == 0;
}


MyString::MyString(const char* str)
{
	m_pStr = new char[strlen(str) + 1];
	strcpy(m_pStr, str);

}
MyString::MyString(MyString& p1) {

	m_pStr = new char[strlen(p1.m_pStr) + 1];
	strcpy(m_pStr, p1.m_pStr);

}

MyString::MyString()
{
	m_pStr = new char[1];
	strcpy(m_pStr, "");
}
MyString::~MyString() {
	delete[] m_pStr;
}