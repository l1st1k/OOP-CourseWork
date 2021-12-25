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
	string login; // Логин аккаунта
	string pass; // Пароль аккаунта в хешированном виде
public:
	Application() {
		login = "0";
		pass = "0";
	};
	~Application() {};
	static void header(); // Шапка для таблицы
	static void read(List <Application>& list); // Чтение из файла
	static void write(List <Application>& list); // Запись в файл
	friend istream& operator >> (istream& in, Application& a); // Перегрузка ввода
	friend ostream& operator << (ostream& out, Application& a); // Перегрузка вывода
	string getLogin();
	string getHash();
};