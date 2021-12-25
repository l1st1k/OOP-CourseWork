#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "List.h"
#include "md5.h"

const string FILE_WITH_APPLICATIONS = "applications.txt";
const string FILE_WITH_ACCOUNTS = "accounts.txt";

class Application
{
	friend class Account;
protected:
	string login; // ����� ��������
	string pass; // ������ �������� � ������������ ����
public:
	Application() {
		login = "0";
		pass = "0";
	};
	~Application() {};
	static void header(); // ����� ��� �������
	static void read(List <Application>& list); // ������ �� �����
	static void write(List <Application>& list); // ������ � ����
	friend istream& operator >> (istream& in, Application& a); // ���������� �����
	friend ostream& operator << (ostream& out, Application& a); // ���������� ������
	string getLogin();
	string getHash();
};