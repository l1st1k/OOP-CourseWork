#pragma once
#include "Interface.h"

using namespace std;

class Menu
{
public:
	Menu() {

	}
	static void core(); // Главная функция программы
	static void login(List <Application>& app, List <Account>& acc, Account& current_acc); // Меню авторизации
	static void save(List <Application>& app, List <Account>& acc); // Сохранение перед выходом
	static void AdminMenu(List <Application>& app, List <Account>& acc, Account& current_acc);  // Главное меню администратора
	static void UserMenu(List <Account>& acc, Account& current_acc);  // Главное меню пользователя
	static void AdminMenuOfScholars(); // Меню со стипендиантами для админимтратора
	static void UserMenuOfScholars(); // Меню со стипендиантами для пользователя
	static void SchoolarshipAmountManagement(); // Меню для изменения базовых стипендий
	static void AccountManagement(List <Application>& app, List <Account>& acc, Account& current_acc); // Модуль управления аккаунтами
	static void showAccounts(List <Account>& acc, Account& current_acc); // Меню с аккаунтами
	static void showNewApplications(List <Application>& app,List <Account>& acc, Account& current_acc); // Меню с заявками
};