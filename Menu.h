#pragma once
#include "Interface.h"

using namespace std;

class Menu
{
public:
	Menu() {

	}
	static void core(); // ������� ������� ���������
	static void login(List <Application>& app, List <Account>& acc, Account& current_acc); // ���� �����������
	static void save(List <Application>& app, List <Account>& acc); // ���������� ����� �������
	static void AdminMenu(List <Application>& app, List <Account>& acc, Account& current_acc);  // ������� ���� ��������������
	static void UserMenu(List <Account>& acc, Account& current_acc);  // ������� ���� ������������
	static void AdminMenuOfScholars(); // ���� �� �������������� ��� ��������������
	static void UserMenuOfScholars(); // ���� �� �������������� ��� ������������
	static void SchoolarshipAmountManagement(); // ���� ��� ��������� ������� ���������
	static void AccountManagement(List <Application>& app, List <Account>& acc, Account& current_acc); // ������ ���������� ����������
	static void showAccounts(List <Account>& acc, Account& current_acc); // ���� � ����������
	static void showNewApplications(List <Application>& app,List <Account>& acc, Account& current_acc); // ���� � ��������
};