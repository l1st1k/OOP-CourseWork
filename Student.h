#pragma once
#include "validation.h"
#include <iostream>
#include <string>

using namespace std;

const string NOT_ACTIVE = "�� �������";
const string ACTIVE = "�������";

class Student
{
protected:
	int mark = 0; // ������� ����
	string surname; // �������
	bool isActive = false; // ���������� ��������
	int group = 111111; // ����� ������
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