#pragma once
#include "Schoolarship.h"

// ��������� (������� ����������)
const string cause1 = "������������";
const string cause2 = "���������������� �����";
const string cause3 = "���������� � ���� ���";
const string cause4 = "������";

class Social : public Schoolarship
{
protected:
	static int amount_s; // ������� ������ ���������� ���������
	int cause = 0; // ������� ���������� ���������� ��������� (����� ���������)
public:
	Social() {};
	~Social() {};
	void header(); // ����� ��� �������
	void edit(); // ����� ��������� �������
	void calculateSum(); // ����� ��������� ���������
	static void find(List <Social>& list); // ����� �� ��������� ����������
	static void sort(List <Social>& list); // ���������� �� ��������� ����������
	static void read(List <Social>& list); // ������ �� �����
	static void write(List <Social>& list); // ������ � ����
	friend istream& operator >> (istream& in, Social& student); // ���������� �����
	friend ostream& operator << (ostream& out, Social& student); // ���������� ������
	static void setAmountSocial();
	static int getAmountSocial();
	void setCause();
	string getCause();
};