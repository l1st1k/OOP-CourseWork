#include "Account.h"

bool Account::getRole() {
	return isAdmin;
}

void Account::setlog() {
	cout << "Введите новый логин пользователя:\n";
	cin >> login;
}

void Account::setlog(string a) {
	login = a;
}

void Account::setpass(string a) {
	// Используется, когда в строке а находится  пароль в ОБЫЧНОМ виде
	pass = md5(a);
}

void Account::replacePass(string a) {
	// Используется, когда в строке а находится  пароль в ХЕШИРОВАННОМ виде
	pass = a;
}

void Account::changeRole() {
	if (isAdmin == false) isAdmin = true;
	else isAdmin = false;
}

void Account::header() {
	cout << "№\tЛогин\tРоль\n";
	for (int i = 0; i < 21; i++) cout << "-";
	cout << endl;
}

string Account::inputPass() {
	string pass;
	char input[30], c;
	int counter = 0;
	while ((c = _getch()) != '\r')
	{
		input[counter++] = c;
		_putch('*');
	}
	pass.assign(input, 0, counter);
	cout << endl;
	return pass;
}

void Account::changePassword(List <Account>& list, Account a) {
	system("cls");
	string pass_comparison;
	bool first_attempt = true;
	int fail_counter = 0;
	while ((a.pass != md5(pass_comparison)) && (fail_counter != 3)) {
		if (first_attempt) cout << "Для изменения пароля введите свой текущий пароль: ";
		else cout << "Некорректный ввод пароля. Повторите попытку: ";
		pass_comparison = inputPass();
		fail_counter++;
		first_attempt = false;
	}
	if (fail_counter != 3) {
		string new_pass, new_pass_copy;
		cout << "Введите новый пароль: ";
		new_pass = inputPass();
		cout << endl;
		bool first_attempt = true, match = false;
		int fails = 0;
		while (!match && fails != 3) {
			if (first_attempt) cout << "Повторите новый пароль: ";
			else cout << "Некорректный ввод! Повторите новый пароль: ";
			new_pass_copy = inputPass();
			if (new_pass == new_pass_copy) match = true;
			fails++;
			first_attempt = false;
		}
		if (fails != 3) {
			a.pass = new_pass;
			for (int i = 0; i < list.Size(); i++) {
				if (list[i].login == a.login) {
					list[i].pass = md5(new_pass); break;
				}
			}
			cout << "Ваш пароль изменен успешно!" << endl;
			system("pause");
		}
		else {
			cout << "Повторный ввод пароля не совпал трижды. Операция изменения пароля завершена. Пароль не изменен!" << endl;
			system("pause");
		}
	}
	else {
		cout << "Неправильный пароль был введен трижды. Изменение пароля недоступно!" << endl;
		system("pause");
		system("cls");
	}
}

void Account::read(List <Account>& list) {
	ifstream fin(FILE_WITH_ACCOUNTS, ios::in); // Открыли файл для чтения
	int size;
	Account temp;
	if (fin.is_open()) {
		fin >> size;
		for (int i = 0; i < size; i++) {
			fin >> temp.login
				>> temp.pass
				>> temp.isAdmin;
			list.ListAdd(temp);
		}
	}
	fin.close(); //Закрыли файл
}

void Account::write(List <Account>& list) {
	ofstream fout(FILE_WITH_ACCOUNTS, ios::out);
	fout << list.Size() << '\n';
	for (int i = 0; i < list.Size(); i++)
		fout << list[i].login << ' ' << list[i].pass << ' ' << list[i].isAdmin << '\n';
	fout.close();
}

istream& operator >> (istream& in, Account& a) {
	cout << "Введите логин нового пользователя:\n";
	in >> a.login;
	string temp;
	cout << "Введите новый пароль:\n";
	in >> temp;
	a.pass = md5(temp);
	return in;
}

ostream& operator << (ostream& out, Account& a) {
	cout << a.login << "\t";
	if (a.isAdmin) cout << "Admin\n";
	else cout << "User\n";
	return out;
}

void Account::newApplication(List <Application>& app, List <Account>& acc) {
	Application new_acc;
	cout << "Создание нового аккаунта в системе" << endl;
	bool flag = false;
	while (!flag) {
		flag = true;
		cout << "Введите логин: ";
		cin >> new_acc.login;
		for (int i = 0; i < acc.Size(); i++) {
			if (acc[i].getLogin() == new_acc.login) {
				flag = false;
				cout << "Аккаунт с таким логином уже зарегистрирован! Пожалуйста, придумайте другой." << endl;
			}
		}
	}
	cout << "Введите пароль: ";
	cin >> new_acc.pass;
	new_acc.pass = md5(new_acc.pass);
	app.ListAdd(new_acc);
	system("cls");
	cout << "Ваша заявка на регистрацию принята!" << endl << "Система будет доступна после одобрения вашей заявки администратором." << endl;
	system("pause");
}