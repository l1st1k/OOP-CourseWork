#pragma once
#include "Application.h"
#include <conio.h>

class Account : public Application
{
	friend class Menu;
protected:
	bool isAdmin = false; // Параметр роли (true -> Admin / false -> User)
public:
	Account() {
		login = "0";
		pass = "0";
		isAdmin = false;
	}
	~Account() {};
	static void header(); // Шапка для таблицы
	static string inputPass(); // Функция ввода пароля с маскировкой в виде звездочек
	void changeRole(); // Метод изменения роли аккаунта
	void changePassword(List <Account>& list, Account a); // Метод изменения пароля аккаунта
	static void read(List <Account>& list); // Чтение из файла
	static void write(List <Account>& list); // Запись в файл
	static void newApplication(List <Application>& app, List <Account>& acc); // Метод регистрации новой заявки
	friend istream& operator >> (istream& in, Account& a); // Перегрузка ввода
	friend ostream& operator << (ostream& out, Account& a); // Перегрузка вывода
	void setlog();
	void setlog(string a);
	void setpass(string a);
	void replacePass(string a);
	bool getRole();
};