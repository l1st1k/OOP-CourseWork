#pragma once
#include "Application.h"
#include <conio.h>

class Account : public Application
{
	friend class Menu;
protected:
	bool isAdmin = false; // �������� ���� (true -> Admin / false -> User)
public:
	Account() {
		login = "0";
		pass = "0";
		isAdmin = false;
	}
	~Account() {};
	static void header(); // ����� ��� �������
	static string inputPass(); // ������� ����� ������ � ����������� � ���� ���������
	void changeRole(); // ����� ��������� ���� ��������
	void changePassword(List <Account>& list, Account a); // ����� ��������� ������ ��������
	static void read(List <Account>& list); // ������ �� �����
	static void write(List <Account>& list); // ������ � ����
	static void newApplication(List <Application>& app, List <Account>& acc); // ����� ����������� ����� ������
	friend istream& operator >> (istream& in, Account& a); // ���������� �����
	friend ostream& operator << (ostream& out, Account& a); // ���������� ������
	void setlog();
	void setlog(string a);
	void setpass(string a);
	void replacePass(string a);
	bool getRole();
};