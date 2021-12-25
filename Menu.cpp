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
		cout << "1) Войти" << endl << "2) Зарегистрировать новый аккаунт" << endl << "0) Выйти из системы" << endl;
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
		cout << "В нижепредставленных разделах представлены списки студентов, получающих разные виды стипендий.\n\nВыберите раздел для работы:\n";
		cout << "1) Учебная стипендия\n2) Президентская стипендия\n3) Социальная стипендия\n4) Именная стипендия\n0) Вернуться назад\n";
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
		cout << "В нижепредставленных разделах представлены списки студентов, получающих разные виды стипендий.\n\nВыберите раздел для работы:\n";
		cout << "1) Учебная стипендия\n2) Президентская стипендия\n3) Социальная стипендия\n4) Именная стипендия\n0) Вернуться назад\n";
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
		cout << "В данном меню можно изменить размеры базовых стипендий!\n\n";
		cout << "1) Учебная стипендия:\t\t" << Schoolarship::getBase() << endl;
		cout << "2) Именная стипендия:\t\t" << Personal::getAmountPersonal() << endl;
		cout << "3) Президентская стипендия:\t" << President::getAmountPresident() << endl;
		cout << "4) Социальная стипендия:\t" << Social::getAmountSocial() << endl << endl;
		cout << "Выберите номер стипендии для изменения ( 0 - Вернуться назад ) \n";
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
		cout << "\n\nВыберите действие:\n1) Добавить аккаунт\n2) Удалить аккаунт\n3) Изменить роль\n";
		cout << "4) Отсортировать по алфавиту\n5) Отсортировать по роли\n0) Вернуться назад\n";
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
				cout << "Список пуст" << endl;
				system("pause");
			}
			else
			{
				cout << "Введите номер аккаунта для удаления:\n";
				del_choice = inputNumber(1, acc.Size());
				if (current_acc.getLogin() == acc[del_choice - 1].getLogin()) {
					cout << "Вы не можете удалить свой аккаунт!" << endl;
					system("pause");
				}
				else {
					cout << "Вы действительно хотите удалить аккаунт с логином " << acc[del_choice - 1].getLogin() << " ?\n1) Да\n2) Нет\n";
					confirm = inputNumber(1, 2);
					if (confirm == 1) acc.del(del_choice - 1);
				}
			}
			break;
		case 3:
			cout << "Введите номер аккаунта:\n";
			ch_choice = inputNumber(1, acc.Size());
			if (current_acc.getLogin() == acc[ch_choice - 1].getLogin()) {
				cout << "Вы не можете изменить роль своего аккаунта!" << endl;
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
		cout << "\n\nВыберите действие:\n1) Одобрить заявку\n2) Удалить заявку\n3) Отсортировать по алфавиту\n0) Вернуться назад\n";
		choice = inputNumber(0, 3);
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			cout << "Введите номер заявки для одобрения:\n";
			ch_choice = inputNumber(1, acc.Size());
			temp.setlog(app[ch_choice-1].getLogin());
			temp.replacePass(app[ch_choice - 1].getHash());
			acc.ListAdd(temp);
			app.del(ch_choice - 1);
			break;
		case 2:
			if (app.isListEmpty())
			{
				cout << "Список пуст" << endl;
				system("pause");
			}
			else
			{
				cout << "Введите номер аккаунта для удаления:\n";
				del_choice = inputNumber(1, app.Size());
				system("cls");
				cout << "Вы действительно хотите удалить аккаунт с логином " << app[del_choice - 1].getLogin() << " ?\n1) Да\n2) Нет\n";
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
		cout << "Модуль управления аккаунтами системы\n\nВыберите действие:\n1) Показать все аккаунты\n2) Показать новые заявки на вход в систему\n0) Назад\n";
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
		cout << "Добро пожаловать в систему расчёта и начисления стипендий!\n" 
			<< "Вы находитесь в режиме администратора!\n\n" 
			<< "1) Списки стипендиантов\n2) Меню управления базовыми размерами стипендий\n3) Модуль управления аккаунтами\n4) Изменить пароль\n0) Выйти из аккаунта" << endl;
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
		cout << "Добро пожаловать в систему расчёта и начисления стипендий!\n"
			<< "Вы находитесь в режиме пользователя!\n\n"
			<< "1) Списки стипендиантов\n2) Изменить пароль\n0) Выйти из аккаунта" << endl;
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
	cout << "***Авторизируйтесь в системе***" << endl;
	while (!similar) {
		cout << "Введите логин: "; cin >> written_login;
		cout << "Введите пароль: ";
		written_password = Account::inputPass();
		cout << endl;
		for (int i = 0; i < acc.Size(); i++) {
			if (acc[i].login == written_login && acc[i].pass == md5(written_password)) {
				current_acc = acc[i];
				similar = true;
			}
		}
		if (!similar) cout << "Данные введены некорректно! Повторите попытку. " << endl;
	}
	system("cls");
	if (current_acc.isAdmin) Menu::AdminMenu(app, acc, current_acc);
	else Menu::UserMenu(acc,current_acc);
}

void Menu::save(List <Application>& app, List <Account>& acc) {
	Application::write(app);
	Account::write(acc);
}