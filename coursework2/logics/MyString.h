#pragma once
#include<iostream>
class MyString
{
	char* m_pStr;
	friend std::ostream& operator<<(std::ostream& out, MyString& str);
	friend std::istream& operator>>(std::istream& in, MyString& str);
public:
	MyString& operator=(const MyString& str);
	MyString operator+(const MyString& str);
	MyString& operator+=(const MyString& str);
	bool operator==(const char* str);

	void SetNewString(const char* newStr);
	char* GetString();
	MyString(const char* str);
	MyString(MyString& p1);
	MyString();
	~MyString();

};