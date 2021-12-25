#pragma once
#include "Student.h"
#include "List.h"
#include <fstream>

const string FILE_WITH_DEFAULT = "default.txt";
const string FILE_WITH_PRESIDENT = "president.txt";
const string FILE_WITH_SOCIAL = "social.txt";
const string FILE_WITH_PERSONAL = "personal.txt";

class Schoolarship : public Student
{
protected:
	double sum = 0; // ������ ���������
	static int base; // ������� ���������
	double koef = 1; // ����������� ��� ������� ��������� (������������ �������� �����)
public:
	Schoolarship() {}
	~Schoolarship() {}
	void header(); // ����� ��� �������
	virtual void edit(); // ����� ��������� �������
	virtual void calculateSum(); // ����� ��������� ���������
	void calculateKoef(); // ����� ��������� ������������
	static void find(List <Schoolarship>& list); // ����� �� ��������� ����������
	static void sort(List <Schoolarship>& list); // ���������� �� ��������� ����������
	static void read(List <Schoolarship>& list); // ������ �� �����
	static void write(List <Schoolarship>& list); // ������ � ����
	friend istream& operator >> (istream& in, Schoolarship& student); // ���������� �����
	friend ostream& operator << (ostream& out, Schoolarship& student); // ���������� ������
	static void setBase();
	static int getBase();
	double getSum();
	double getKoef();
};

