#include "Menu.h"

void Menu::core() {
	List<Application> app;
	List<Account> acc;
	Application::read(app);
	Account::read(acc);
	Account current_acc;
	bool core_flag = true;
	while (core_flag) {
		system("cls");
		system("color 8E");
		cout << "1) �����" << endl << "2) ���������������� ����� �������" << endl << "0) ����� �� �������" << endl;
		int user_choice = inputNumber(0, 2);
		system("cls");
		switch (user_choice) {
		case 0: core_flag = false; break;
		case 1:
			Menu::login(app, acc, current_acc);
			break;
		case 2:
			Account::newApplication(app,acc);
			break;
		}
	}
	Menu::save(app, acc);
}

void Menu::AdminMenuOfScholars() {
	bool flag = true;
	int choice;
	while (flag) {
		system("cls");
		cout << "� ������������������ �������� ������������ ������ ���������, ���������� ������ ���� ���������.\n\n�������� ������ ��� ������:\n";
		cout << "1) ������� ���������\n2) ������������� ���������\n3) ���������� ���������\n4) ������� ���������\n0) ��������� �����\n";
		choice = inputNumber(0, 4);
		switch (choice)
		{
		case 0: 
			flag = false;
			break; 
		case 1:
			Interface<Schoolarship>::AdminUI();
			break; 
		case 2: 
			Interface<President>::AdminUI();
			break; 
		case 3: 
			Interface<Social>::AdminUI();
			break; 
		case 4: 
			Interface<Personal>::AdminUI();
			break; 
		}
	}
}

void Menu::UserMenuOfScholars() {
	bool flag = true;
	int choice;
	while (flag) {
		system("cls");
		cout << "� ������������������ �������� ������������ ������ ���������, ���������� ������ ���� ���������.\n\n�������� ������ ��� ������:\n";
		cout << "1) ������� ���������\n2) ������������� ���������\n3) ���������� ���������\n4) ������� ���������\n0) ��������� �����\n";
		choice = inputNumber(0, 4);
		switch (choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			Interface<Schoolarship>::UserUI();
			break;
		case 2:
			Interface<President>::UserUI();
			break;
		case 3:
			Interface<Social>::UserUI();
			break;
		case 4:
			Interface<Personal>::UserUI();
			break;
		}
	}
}

void Menu::SchoolarshipAmountManagement() {
	int choice;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "� ������ ���� ����� �������� ������� ������� ���������!\n\n";
		cout << "1) ������� ���������:\t\t" << Schoolarship::getBase() << endl;
		cout << "2) ������� ���������:\t\t" << Personal::getAmountPersonal() << endl;
		cout << "3) ������������� ���������:\t" << President::getAmountPresident() << endl;
		cout << "4) ���������� ���������:\t" << Social::getAmountSocial() << endl << endl;
		cout << "�������� ����� ��������� ��� ��������� ( 0 - ��������� ����� ) \n";
		choice = inputNumber(0, 4);
		switch (choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			Schoolarship::setBase();
			break;
		case 2:
			Personal::setAmountPersonal();
			break;
		case 3:
			President::setAmountPresident();
			break;
		case 4:
			Social::setAmountSocial();
			break;
		}
	}
}

void Menu::showAccounts(List <Account>& acc, Account& current_acc) {
	bool flag = true;
	int choice, ch_choice, del_choice, confirm;
	Account temp;
	while (flag) {
		system("cls");
		Account::header();
		for (int i = 0; i < acc.Size(); i++) {
			cout << i+1<< ")\t" << acc[i];
		}
		cout << "\n\n�������� ��������:\n1) �������� �������\n2) ������� �������\n3) �������� ����\n";
		cout << "4) ������������� �� ��������\n5) ������������� �� ����\n0) ��������� �����\n";
		choice = inputNumber(0, 5);
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			cin >> temp;
			acc.ListAdd(temp);
			break;
		case 2:
			if (acc.isListEmpty())
			{
				cout << "������ ����" << endl;
				system("pause");
			}
			else
			{
				cout << "������� ����� �������� ��� ��������:\n";
				del_choice = inputNumber(1, acc.Size());
				if (current_acc.getLogin() == acc[del_choice - 1].getLogin()) {
					cout << "�� �� ������ ������� ���� �������!" << endl;
					system("pause");
				}
				else {
					cout << "�� ������������� ������ ������� ������� � ������� " << acc[del_choice - 1].getLogin() << " ?\n1) ��\n2) ���\n";
					confirm = inputNumber(1, 2);
					if (confirm == 1) acc.del(del_choice - 1);
				}
			}
			break;
		case 3:
			cout << "������� ����� ��������:\n";
			ch_choice = inputNumber(1, acc.Size());
			if (current_acc.getLogin() == acc[ch_choice - 1].getLogin()) {
				cout << "�� �� ������ �������� ���� ������ ��������!" << endl;
				system("pause");
			}
			else {
				acc[ch_choice - 1].changeRole();
			}
			break;
		case 4:
			acc.sort(
				[](Account ob1, Account ob2) -> bool
				{
					return ob1.getLogin() > ob2.getLogin();
				});
			break;
		case 5:
			acc.sort(
				[](Account ob1, Account ob2) -> bool
				{
					return ob1.getRole() < ob2.getRole();
				});
			break;
		}
	}
}

void Menu::showNewApplications(List <Application>& app, List <Account>& acc, Account& current_acc) {
	bool flag = true;
	int choice, ch_choice, del_choice, confirm;
	Account temp;
	while (flag) {
		system("cls");
		Application::header();
		for (int i = 0; i < app.Size(); i++) {
			cout << i + 1 << ")\t" << app[i];
		}
		cout << "\n\n�������� ��������:\n1) �������� ������\n2) ������� ������\n3) ������������� �� ��������\n0) ��������� �����\n";
		choice = inputNumber(0, 3);
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			cout << "������� ����� ������ ��� ���������:\n";
			ch_choice = inputNumber(1, acc.Size());
			temp.setlog(app[ch_choice-1].getLogin());
			temp.replacePass(app[ch_choice - 1].getHash());
			acc.ListAdd(temp);
			app.del(ch_choice - 1);
			break;
		case 2:
			if (app.isListEmpty())
			{
				cout << "������ ����" << endl;
				system("pause");
			}
			else
			{
				cout << "������� ����� �������� ��� ��������:\n";
				del_choice = inputNumber(1, app.Size());
				system("cls");
				cout << "�� ������������� ������ ������� ������� � ������� " << app[del_choice - 1].getLogin() << " ?\n1) ��\n2) ���\n";
				confirm = inputNumber(1, 2);
				if (confirm == 1) app.del(del_choice - 1);
			}
			break;
		case 3:
			app.sort(
				[](Application ob1, Application ob2) -> bool
				{
					return ob1.getLogin() > ob2.getLogin();
				});
			break;
		}
	}
}

void Menu::AccountManagement(List <Application>& app, List <Account>& acc, Account& current_acc) {
	bool acc_menu = true;
	int choice;
	while (acc_menu) {
		system("cls");
		system("color 81");
		cout << "������ ���������� ���������� �������\n\n�������� ��������:\n1) �������� ��� ��������\n2) �������� ����� ������ �� ���� � �������\n0) �����\n";
		choice = inputNumber(0, 2);
		system("cls");
		switch (choice) {
		case 0: acc_menu = false; break;
		case 1: Menu::showAccounts(acc, current_acc); break;
		case 2: Menu::showNewApplications(app, acc,current_acc); break;
		}
	}
}

void Menu::AdminMenu(List <Application>& app, List <Account>& acc, Account& current_acc) {
	int choice;
	bool flag = true;
	while (flag) {
		system("cls");
		system("color 84");
		cout << "����� ���������� � ������� ������� � ���������� ���������!\n" 
			<< "�� ���������� � ������ ��������������!\n\n" 
			<< "1) ������ �������������\n2) ���� ���������� �������� ��������� ���������\n3) ������ ���������� ����������\n4) �������� ������\n0) ����� �� ��������" << endl;
		choice = inputNumber(0, 4);
		system("cls");
		switch (choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			Menu::AdminMenuOfScholars();
			break;
		case 2:
			Menu::SchoolarshipAmountManagement();
			break;
		case 3:
			Menu::AccountManagement(app,acc, current_acc);
			break;
		case 4:
			current_acc.changePassword(acc,current_acc);
			break;
		}
	}
}

void Menu::UserMenu(List <Account>& acc, Account& current_acc) {
	int choice;
	bool flag = true;
	while (flag) {
		system("cls");
		system("color 8A");
		cout << "����� ���������� � ������� ������� � ���������� ���������!\n"
			<< "�� ���������� � ������ ������������!\n\n"
			<< "1) ������ �������������\n2) �������� ������\n0) ����� �� ��������" << endl;
		choice = inputNumber(0, 2);
		system("cls");
		switch (choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			Menu::UserMenuOfScholars();
			break;
		case 2:
			current_acc.changePassword(acc, current_acc);
			break;
		}
	}
}

void Menu::login(List <Application>& app, List <Account>& acc, Account& current_acc) {
	string written_login, written_password;
	bool similar = false;
	cout << "***��������������� � �������***" << endl;
	while (!similar) {
		cout << "������� �����: "; cin >> written_login;
		cout << "������� ������: ";
		written_password = Account::inputPass();
		cout << endl;
		for (int i = 0; i < acc.Size(); i++) {
			if (acc[i].login == written_login && acc[i].pass == md5(written_password)) {
				current_acc = acc[i];
				similar = true;
			}
		}
		if (!similar) cout << "������ ������� �����������! ��������� �������. " << endl;
	}
	system("cls");
	if (current_acc.isAdmin) Menu::AdminMenu(app, acc, current_acc);
	else Menu::UserMenu(acc,current_acc);
}

void Menu::save(List <Application>& app, List <Account>& acc) {
	Application::write(app);
	Account::write(acc);
}