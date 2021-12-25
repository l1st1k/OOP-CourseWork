#pragma once
#include "Schoolarship.h"
#include "validation.h"
#include <iostream>

class Personal : public Schoolarship
{
protected:
	static int amount_pers; // ������� ������ ������� ���������
	string author; // �������� ���������
public:
	Personal () {};
	~Personal() {};
	void header(); // ����� ��� �������
	void edit(); // ����� ��������� �������
	void calculateSum(); // ����� ��������� ���������
	static void find(List <Personal>& list); // ����� �� ��������� ����������
	static void sort(List <Personal>& list); // ���������� �� ��������� ����������
	static void read(List <Personal>& list); // ������ �� �����
	static void write(List <Personal>& list); // ������ � ����
	friend istream& operator >> (istream& in, Personal& student); // ���������� �����
	friend ostream& operator << (ostream& out, Personal& student); // ���������� ������
	static void setAmountPersonal();
	static int getAmountPersonal();
	void setAuthor();
	string getAuthor();
};