#include "President.h"

int President::amount_p = 350;

void President::calculateSum() {
	calculateKoef();
	sum = base * koef;
	if (isActive) sum *= 1.25;
	sum += amount_p;
}

void President::setAmountPresident(){
	cout << "������� ������ ������������� ���������:\n";
	amount_p = inputNumber(50, 1500);
	}

int President::getAmountPresident() {
	return amount_p;
}

void President::setYear() {
	cout << "������� ��� ���������� �������� ������������� ���������:\n";
	year = inputNumber(2000, 2021);
}

int President::getYear() {
	return year;
}

void President::header() {
	cout << "�\t�������\t\t������\t��.����\t����������\t���������\t��� ����������\n";
	for (int i = 0; i < 86; i++) cout << "-";
	cout << endl;
}

void President::find(List <President>& list) {
	cout << "�������� �����:\n1) �� �������\n2) �� ������ ������\n3) �� �������� �����\n4) �� ���� ����������\n";
	int choice = inputNumber(1, 4);
	string temp_surn;
	int temp_int;
	switch (choice)
	{
	case 1:
		cout << "������� ������� ��� ������:\n";
		cin >> temp_surn;
		list.find<string>(
			[](President ob, string temp_surn) -> bool
			{
				return ob.getSurname() == temp_surn;
			}, temp_surn);
		system("pause");
		break;
	case 2:
		cout << "������� ����� ������ ��� ������:\n";
		temp_int = inputNumber(111111, 999999);
		list.find<int>(
			[](President ob, int temp_int) -> bool
			{
				return ob.getGroup() == temp_int;
			}, temp_int);
		system("pause");
		break;
	case 3:
		cout << "������� ������� ���� ��� ������:\n";
		temp_int = inputNumber(0, 10);
		list.find<int>(
			[](President ob, int temp_int) -> bool
			{
				return ob.getMark() == temp_int;
			}, temp_int);
		system("pause");
		break;
	case 4:
		cout << "������� ��� ���������� ��� ������:\n";
		temp_int = inputNumber(2010, 2021);
		list.find<int>(
			[](President ob, int temp_int) -> bool
			{
				return ob.getYear() == temp_int;
			}, temp_int);
		system("pause");
		break;
	}
}

void President::sort(List <President>& list) {
	cout << "�������� ����������:\n1) ������������� �� ��������\n2) ������������� �� ������ ������\n3) ������������� �� �������� �����\n";
	cout << "4) ������������� �� ������� ���������\n5) ������������� �� ����������\n6) ������������� �� ���� ����������\n";
	int choice = inputNumber(1, 6);
	switch (choice)
	{
	case 1:
		list.sort(
			[](President ob1, President ob2) -> bool
			{
				return ob1.getSurname() > ob2.getSurname();
			});
		break;
	case 2:
		list.sort(
			[](President ob1, President ob2) -> bool
			{
				return ob1.getGroup() > ob2.getGroup();
			});
		break;
	case 3:
		list.sort(
			[](President ob1, President ob2) -> bool
			{
				return ob1.getMark() < ob2.getMark();
			});
		break;
	case 4:
		list.sort(
			[](President ob1, President ob2) -> bool
			{
				return ob1.getSum() < ob2.getSum();
			});
		break;
	case 5:
		list.sort(
			[](President ob1, President ob2) -> bool
			{
				return ob1.getActivity() > ob2.getActivity();
			});
		break;
	case 6:
		list.sort(
			[](President ob1, President ob2) -> bool
			{
				return ob1.getYear() > ob2.getYear();
			});
		break;
	}
}

void President::edit() {
	bool flag = true;
	int choice;
	while (flag) {
		system("cls");
		this->header();
		cout << "x)\t" << *this << "\n\n";
		cout << "�������� ���� ��� ���������:\n1) �������\n2) ����� ������\n3) ����������\n4) ������� ����\n5) ��� ����������\n\n0) ��������� ��������������\n";
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
			this->setYear();
			break;
		}
	}
}

istream& operator >> (istream& in, President& student) {
	system("cls");
	in >> dynamic_cast<Schoolarship&>(student);
	cout << "� ����� ���� �������� ��������� ������������� ����������?\n";
	in >> student.year;
	student.calculateSum();
	return in;
}

ostream& operator << (ostream& out, President& student) {
	cout << dynamic_cast<Schoolarship&>(student);
	cout << "\t\t" << student.year << "�.";
	return out;
}

void President::read(List <President>& v) {
	ifstream fin(FILE_WITH_PRESIDENT, ios::in); // ������� ���� ��� ������
	int size;
	President temp;
	if (fin.is_open()) {
		fin >> size;
		for (int i = 0; i < size; i++) {
			fin >> temp.surname
				>> temp.group
				>> temp.isActive
				>> temp.mark
				>> temp.sum
				>> temp.year;
			v.ListAdd(temp);
		}
	}
	fin.close(); //������� ����
}

void President::write(List <President>& list) {
	ofstream fout(FILE_WITH_PRESIDENT, ios::out);
	fout << list.Size() << '\n';
	for (int i = 0; i < list.Size(); i++)
		fout << list[i].surname << ' ' << list[i].group << ' ' << list[i].isActive << ' ' << list[i].mark << ' ' << list[i].sum << ' ' << list[i].year << '\n';
	fout.close();
}