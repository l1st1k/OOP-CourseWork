#include "Schoolarship.h"

int Schoolarship::base = 90;

void Schoolarship::setBase() {
	cout << "Введите размер базовой стипендии (в рублях):\n";
	base = inputNumber(50, 500);
}

int Schoolarship::getBase() {
	return base;
}

void Schoolarship::calculateSum() {
	calculateKoef();
	sum = base * koef*1.00;
	if (isActive) sum *= 1.25;
}

void Schoolarship::calculateKoef() {
	if (mark < 5) {
		koef = 0;
		return;
	}
	switch (mark)
	{
	case 5:			koef = 1; break;
	case 6: case 7: koef = 1.2; break;
	case 8:			koef = 1.4; break;
	case 9: case 10:koef = 1.6; break;
	}
}

double Schoolarship::getKoef() {
	return koef;
}

double Schoolarship::getSum() {
	return sum;
}

void Schoolarship::find(List <Schoolarship>& list) {
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
			[](Schoolarship ob, string temp_surn) -> bool
			{
				return ob.getSurname() == temp_surn;
			}, temp_surn);
		system("pause");
		break;
	case 2:
		cout << "Введите номер группы для поиска:\n";
		temp_int = inputNumber(111111, 999999);
		list.find<int>(
			[](Schoolarship ob, int temp_int) -> bool
			{
				return ob.getGroup() == temp_int;
			}, temp_int);
		system("pause");
		break;
	case 3:
		cout << "Введите средний балл для поиска:\n";
		temp_int = inputNumber(0, 10);
		list.find<int>(
			[](Schoolarship ob, int temp_int) -> bool
			{
				return ob.getMark() == temp_int;
			}, temp_int);
		system("pause");
		break;
	}
}

void Schoolarship::sort(List <Schoolarship>& list) {
	cout << "Выберите сортировку:\n1) Отсортировать по алфавиту\n2) Отсортировать по номеру группы\n3) Отсортировать по среднему баллу\n";
	cout <<"4) Отсортировать по размеру стипендии\n5) Отсортировать по активности\n";
	int choice = inputNumber(1, 5);
	switch (choice)
	{
	case 1:
		list.sort(
			[](Schoolarship ob1, Schoolarship ob2) -> bool
			{
				return ob1.getSurname() > ob2.getSurname();
			});
		break;
	case 2:
		list.sort(
			[](Schoolarship ob1, Schoolarship ob2) -> bool
			{
				return ob1.getGroup() > ob2.getGroup();
			});
		break;
	case 3:
		list.sort(
			[](Schoolarship ob1, Schoolarship ob2) -> bool
			{
				return ob1.getMark() < ob2.getMark();
			});
		break;
	case 4:
		list.sort(
			[](Schoolarship ob1, Schoolarship ob2) -> bool
			{
				return ob1.getSum() < ob2.getSum();
			});
		break;
	case 5:
		list.sort(
			[](Schoolarship ob1, Schoolarship ob2) -> bool
			{
				return ob1.getActivity() > ob2.getActivity();
			});
		break;
	}
}

void Schoolarship::edit() {
	bool flag = true;
	int choice;
	while (flag) {
		system("cls");
		this->header();
		cout << "x)\t"<< *this << "\n\n";
		cout << "Выберите поле для изменения:\n1) Фамилия\n2) Номер группы\n3) Активность\n4) Средний балл\n\n0) Завершить редактирование\n";
		choice = inputNumber(0, 4);
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
		}
	}
}

void Schoolarship::header() {
	cout << "№\tФамилия\t\tГруппа\tСр.Балл\tАктивность\tСтипендия\n";
	for (int i = 0; i < 65; i++) cout << "-";
	cout << endl;
}

istream& operator >> (istream& in, Schoolarship& student) {
	system("cls");
	cout << "***Создание нового студента***\nВведите фамилию студента: \n";
	in >> student.surname;
	cout << "Введите номер группы студента: \n";
	in >> student.group;
	cout << "Введите средний балл студента:\n";
	in >> student.mark;
	cout << "Если студент активен, нажмите 1\nЕсли нет, нажмите 0 \n";
	in >> student.isActive;
	student.calculateSum();
	return in;
}

ostream& operator << (ostream& out, Schoolarship& student) {
	cout << student.surname << "\t\t" << student.group << "\t" << student.mark << "\t";
	if (student.isActive) cout << "Активен  \t";
	else cout << "Неактивен\t";
	cout << student.sum << "руб.";
	return out;
}

void Schoolarship::read(List <Schoolarship>& list) {
	ifstream fin(FILE_WITH_DEFAULT, ios::in); // Открыли файл для чтения
	int size;
	Schoolarship temp;
	if (fin.is_open()) {
		fin >> size;
		for (int i = 0; i < size; i++) {
			fin >> temp.surname
				>> temp.group
				>> temp.isActive
				>> temp.mark
				>> temp.sum;
			list.ListAdd(temp);
		}
	}
	fin.close(); //Закрыли файл
}

void Schoolarship::write(List <Schoolarship>& list) {
	ofstream fout(FILE_WITH_DEFAULT, ios::out);
	fout << list.Size() << '\n';
	for (int i = 0; i < list.Size(); i++)
		fout << list[i].surname << ' ' << list[i].group << ' ' << list[i].isActive << ' ' << list[i].mark << ' ' << list[i].sum << ' ' << '\n';
	fout.close();
}