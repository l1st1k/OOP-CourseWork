#pragma once
#include "Schoolarship.h"

class President : public Schoolarship
{
protected:
	static int amount_p; // ������� ������ ������������� ���������
	int year = 2021; // ��� ����������
public:
	President() {};
	~President() {};
	void header(); // ����� ��� �������
	void edit(); // ����� ��������� �������
	void calculateSum(); // ����� ��������� ���������
	static void find(List <President>& list); // ����� �� ��������� ����������
	static void sort(List <President>& list); // ���������� �� ��������� ����������
	static void read(List <President>& list); // ������ �� �����
	static void write(List <President>& list); // ������ � ����
	friend istream& operator >> (istream& in, President& student); // ���������� �����
	friend ostream& operator << (ostream& out, President& student); // ���������� ������
	static void setAmountPresident();
	static int getAmountPresident();
	void setYear();
	int getYear();
};

