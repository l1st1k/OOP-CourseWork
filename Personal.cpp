#include "Personal.h"

int Personal::amount_pers = 350;

void Personal::calculateSum() {
	calculateKoef();
	sum = base * koef;
	if (isActive) sum *= 1.25;
	sum += amount_pers;
}

void Personal::setAmountPersonal() {
	cout << "Введите размер Именной стипендии:\n";
	amount_pers = inputNumber(50, 1500);
}

int Personal::getAmountPersonal() {
	return amount_pers;
}

void Personal::setAuthor() {
	cout << "Какая именная стипендия у данного студента?:\n";
	cin >> author;
}

string Personal::getAuthor() {
	return author;
}

void Personal::header() {
	cout << "№\tФамилия\t\tГруппа\tСр.Балл\tАктивность\tСтипендия\tНазвание\n";
	for (int i = 0; i < 80; i++) cout << "-";
	cout << endl;
}

void Personal::find(List <Personal>& list) {
	cout << "Выберите поиск:\n1) По фамилии\n2) По номеру группы\n3) По среднему баллу\n";
	int choice = inputNumber(1, 3);
	string temp_surn;
	int temp_int;
	switch (choice)
	{
	case 1:
		cout << "Введите фамилию для поиска:\n";
		cin >> temp_surn;
		list.find<string>(
			[](Personal ob, string temp_surn) -> bool
			{
				return ob.getSurname() == temp_surn;
			}, temp_surn);
		system("pause");
		break;
	case 2:
		cout << "Введите номер группы для поиска:\n";
		temp_int = inputNumber(111111, 999999);
		list.find<int>(
			[](Personal ob, int temp_int) -> bool
			{
				return ob.getGroup() == temp_int;
			}, temp_int);
		system("pause");
		break;
	case 3:
		cout << "Введите средний балл для поиска:\n";
		temp_int = inputNumber(0, 10);
		list.find<int>(
			[](Personal ob, int temp_int) -> bool
			{
				return ob.getMark() == temp_int;
			}, temp_int);
		system("pause");
		break;
	}
}

void Personal::sort(List <Personal>& list) {
	cout << "Выберите сортировку:\n1) Отсортировать по алфавиту\n2) Отсортировать по номеру группы\n3) Отсортировать по среднему баллу\n";
	cout << "4) Отсортировать по размеру стипендии\n5) Отсортировать по активности\n";
	int choice = inputNumber(1, 5);
	switch (choice)
	{
	case 1:
		list.sort(
			[](Personal ob1, Personal ob2) -> bool
			{
				return ob1.getSurname() > ob2.getSurname();
			});
		break;
	case 2:
		list.sort(
			[](Personal ob1, Personal ob2) -> bool
			{
				return ob1.getGroup() > ob2.getGroup();
			});
		break;
	case 3:
		list.sort(
			[](Personal ob1, Personal ob2) -> bool
			{
				return ob1.getMark() < ob2.getMark();
			});
		break;
	case 4:
		list.sort(
			[](Personal ob1, Personal ob2) -> bool
			{
				return ob1.getSum() < ob2.getSum();
			});
		break;
	case 5:
		list.sort(
			[](Personal ob1, Personal ob2) -> bool
			{
				return ob1.getActivity() > ob2.getActivity();
			});
		break;
	}
}

void Personal::edit() {
	bool flag = true;
	int choice;
	while (flag) {
		system("cls");
		this->header();
		cout << "x)\t" << *this << "\n\n";
		cout << "Выберите поле для изменения:\n1) Фамилия\n2) Номер группы\n3) Активность\n4) Средний балл\n5) Название стипендии\n\n0) Завершить редактирование\n";
		choice = inputNumber(0, 5);
		switch (choice) {
		case 0:
			flag = false;
			break;
		case 1:
			this->setSurname();
			break;
		case 2:
			this->setGroup();
			break;
		case 3:
			this->setActivity();
			this->calculateSum();
			break;
		case 4:
			this->setMark();
			this->calculateKoef();
			this->calculateSum();
			break;
		case 5:
			this->setAuthor();
			break;
		}
	}
}

istream& operator >> (istream& in, Personal& student) {
	system("cls");
	in >> dynamic_cast<Schoolarship&>(student);
	cout << "Какую именную стипендию получает студент? (Например: им.Франциска Скорины) \n";
	in >> student.author;
	student.calculateSum();
	return in;
}

ostream& operator << (ostream& out, Personal& student) {
	cout << dynamic_cast<Schoolarship&>(student);
	cout << "\t\t" << student.author;
	return out;
}

void Personal::read(List <Personal>& v) {
	ifstream fin(FILE_WITH_PERSONAL, ios::in); // Открыли файл для чтения
	int size;
	Personal temp;
	if (fin.is_open()) {
		fin >> size;
		for (int i = 0; i < size; i++) {
			fin >> temp.surname
				>> temp.group
				>> temp.isActive
				>> temp.mark
				>> temp.sum
				>> temp.author;
			v.ListAdd(temp);
		}
	}
	fin.close(); //Закрыли файл
}

void Personal::write(List <Personal>& list) {
	ofstream fout(FILE_WITH_PERSONAL, ios::out);
	fout << list.Size() << '\n';
	for (int i = 0; i < list.Size(); i++)
		fout << list[i].surname << ' ' << list[i].group << ' ' << list[i].isActive << ' ' << list[i].mark << ' ' << list[i].sum << ' ' << list[i].author << '\n';
	fout.close();
}