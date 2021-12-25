#pragma once
#include "validation.h"
#include <iostream>
#include <string>

using namespace std;

const string NOT_ACTIVE = "Не активен";
const string ACTIVE = "Активен";

class Student
{
protected:
	int mark = 0; // Средний балл
	string surname; // Фамилия
	bool isActive = false; // Активность студента
	int group = 111111; // Номер группы
public:
	Student() {};
	~Student() {};
	virtual void header() = 0;
	void setGroup();
	int getGroup();
	void setActivity();
	string getActivity();
	void setSurname();
	string getSurname();
	void setMark();
	int getMark();
};