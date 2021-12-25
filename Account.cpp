#include "Account.h"

bool Account::getRole() {
	return isAdmin;
}

void Account::setlog() {
	cout << "������� ����� ����� ������������:\n";
	cin >> login;
}

void Account::setlog(string a) {
	login = a;
}

void Account::setpass(string a) {
	// ������������, ����� � ������ � ���������  ������ � ������� ����
	pass = md5(a);
}

void Account::replacePass(string a) {
	// ������������, ����� � ������ � ���������  ������ � ������������ ����
	pass = a;
}

void Account::changeRole() {
	if (isAdmin == false) isAdmin = true;
	else isAdmin = false;
}

void Account::header() {
	cout << "�\t�����\t����\n";
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
		if (first_attempt) cout << "��� ��������� ������ ������� ���� ������� ������: ";
		else cout << "������������ ���� ������. ��������� �������: ";
		pass_comparison = inputPass();
		fail_counter++;
		first_attempt = false;
	}
	if (fail_counter != 3) {
		string new_pass, new_pass_copy;
		cout << "������� ����� ������: ";
		new_pass = inputPass();
		cout << endl;
		bool first_attempt = true, match = false;
		int fails = 0;
		while (!match && fails != 3) {
			if (first_attempt) cout << "��������� ����� ������: ";
			else cout << "������������ ����! ��������� ����� ������: ";
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
			cout << "��� ������ ������� �������!" << endl;
			system("pause");
		}
		else {
			cout << "��������� ���� ������ �� ������ ������. �������� ��������� ������ ���������. ������ �� �������!" << endl;
			system("pause");
		}
	}
	else {
		cout << "������������ ������ ��� ������ ������. ��������� ������ ����������!" << endl;
		system("pause");
		system("cls");
	}
}

void Account::read(List <Account>& list) {
	ifstream fin(FILE_WITH_ACCOUNTS, ios::in); // ������� ���� ��� ������
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
	fin.close(); //������� ����
}

void Account::write(List <Account>& list) {
	ofstream fout(FILE_WITH_ACCOUNTS, ios::out);
	fout << list.Size() << '\n';
	for (int i = 0; i < list.Size(); i++)
		fout << list[i].login << ' ' << list[i].pass << ' ' << list[i].isAdmin << '\n';
	fout.close();
}

istream& operator >> (istream& in, Account& a) {
	cout << "������� ����� ������ ������������:\n";
	in >> a.login;
	string temp;
	cout << "������� ����� ������:\n";
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
	cout << "�������� ������ �������� � �������" << endl;
	bool flag = false;
	while (!flag) {
		flag = true;
		cout << "������� �����: ";
		cin >> new_acc.login;
		for (int i = 0; i < acc.Size(); i++) {
			if (acc[i].getLogin() == new_acc.login) {
				flag = false;
				cout << "������� � ����� ������� ��� ���������������! ����������, ���������� ������." << endl;
			}
		}
	}
	cout << "������� ������: ";
	cin >> new_acc.pass;
	new_acc.pass = md5(new_acc.pass);
	app.ListAdd(new_acc);
	system("cls");
	cout << "���� ������ �� ����������� �������!" << endl << "������� ����� �������� ����� ��������� ����� ������ ���������������." << endl;
	system("pause");
}