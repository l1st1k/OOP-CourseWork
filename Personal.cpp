#include "Personal.h"

int Personal::amount_pers = 350;

void Personal::calculateSum() {
	calculateKoef();
	sum = base * koef;
	if (isActive) sum *= 1.25;
	sum += amount_pers;
}

void Personal::setAmountPersonal() {
	cout << "������� ������ ������� ���������:\n";
	amount_pers = inputNumber(50, 1500);
}

int Personal::getAmountPersonal() {
	return amount_pers;
}

void Personal::setAuthor() {
	cout << "����� ������� ��������� � ������� ��������?:\n";
	cin >> author;
}

string Personal::getAuthor() {
	return author;
}

void Personal::header() {
	cout << "�\t�������\t\t������\t��.����\t����������\t���������\t��������\n";
	for (int i = 0; i < 80; i++) cout << "-";
	cout << endl;
}

void Personal::find(List <Personal>& list) {
	cout << "�������� �����:\n1) �� �������\n2) �� ������ ������\n3) �� �������� �����\n";
	int choice = inputNumber(1, 3);
	string temp_surn;
	int temp_int;
	switch (choice)
	{
	case 1:
		cout << "������� ������� ��� ������:\n";
		cin >> temp_surn;
		list.find<string>(
			[](Personal ob, string temp_surn) -> bool
			{
				return ob.getSurname() == temp_surn;
			}, temp_surn);
		system("pause");
		break;
	case 2:
		cout << "������� ����� ������ ��� ������:\n";
		temp_int = inputNumber(111111, 999999);
		list.find<int>(
			[](Personal ob, int temp_int) -> bool
			{
				return ob.getGroup() == temp_int;
			}, temp_int);
		system("pause");
		break;
	case 3:
		cout << "������� ������� ���� ��� ������:\n";
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
	cout << "�������� ����������:\n1) ������������� �� ��������\n2) ������������� �� ������ ������\n3) ������������� �� �������� �����\n";
	cout << "4) ������������� �� ������� ���������\n5) ������������� �� ����������\n";
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
		cout << "�������� ���� ��� ���������:\n1) �������\n2) ����� ������\n3) ����������\n4) ������� ����\n5) �������� ���������\n\n0) ��������� ��������������\n";
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
	cout << "����� ������� ��������� �������� �������? (��������: ��.��������� �������) \n";
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
	ifstream fin(FILE_WITH_PERSONAL, ios::in); // ������� ���� ��� ������
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
	fin.close(); //������� ����
}

void Personal::write(List <Personal>& list) {
	ofstream fout(FILE_WITH_PERSONAL, ios::out);
	fout << list.Size() << '\n';
	for (int i = 0; i < list.Size(); i++)
		fout << list[i].surname << ' ' << list[i].group << ' ' << list[i].isActive << ' ' << list[i].mark << ' ' << list[i].sum << ' ' << list[i].author << '\n';
	fout.close();
}