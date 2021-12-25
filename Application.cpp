#include "Application.h"

string Application::getLogin() {
	return login;
}

string Application::getHash() {
	return pass;
}

void Application::header() {
	cout << "№\tЛогин\n";
	for (int i = 0; i < 13; i++) cout << "-";
	cout << endl;
}

void Application::read(List <Application>& list) {
	ifstream fin(FILE_WITH_APPLICATIONS, ios::in); // Открыли файл для чтения
	int size;
	Application temp;
	if (fin.is_open()) {
		fin >> size;
		for (int i = 0; i < size; i++) {
			fin >> temp.login
				>> temp.pass;
			list.ListAdd(temp);
		}
	}
	fin.close(); //Закрыли файл
}

void Application::write(List <Application>& list) {
	ofstream fout(FILE_WITH_APPLICATIONS, ios::out);
	fout << list.Size() << '\n';
	for (int i = 0; i < list.Size(); i++)
		fout << list[i].login << ' ' << list[i].pass << '\n';
	fout.close();
}

istream& operator >> (istream& in, Application& a) {
	cout << "Введите логин нового пользователя:\n";
	in >> a.login;
	string temp;
	cout << "Введите новый пароль:\n";
	in >> temp;
	a.pass = md5(temp);
	return in;
}

ostream& operator << (ostream& out, Application& a) {
	cout << a.login << "\n";
	return out;
}