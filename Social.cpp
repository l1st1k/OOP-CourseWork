#include "Social.h"

int Social::amount_s = 70;

void Social::calculateSum() {
	calculateKoef();
	sum = base * koef;
	if (isActive) sum *= 1.25;
	sum += amount_s;
}

void Social::setAmountSocial() {
	cout << "������� ������ ���������� ���������:\n";
	amount_s = inputNumber(50, 250);
}

int Social::getAmountSocial() {
	return amount_s;
}

void Social::setCause() {
	cout << "�� ����� ������� ������� �������� ���������� ���������?\n1) "<< cause1<<"\n2) "<<cause2 << "\n3) " << cause3 << "\n4) " << cause4 << "\n";
	cause = inputNumber(1, 4);
}

string Social::getCause() {
	switch (cause)
	{
	case 1: return cause1; break;
	case 2: return cause2; break; 
	case 3: return cause3; break;
	case 4: return cause4; break;
	}
}

void Social::header() {
	cout << "�\t�������\t\t������\t��.����\t����������\t���������\t������� ����������\n";
	for (int i = 0; i < 94; i++) cout << "-";
	cout << endl;
}

void Social::find(List <Social>& list) {
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
			[](Social ob, string temp_surn) -> bool
			{
				return ob.getSurname() == temp_surn;
			}, temp_surn);
		system("pause");
		break;
	case 2:
		cout << "������� ����� ������ ��� ������:\n";
		temp_int = inputNumber(111111, 999999);
		list.find<int>(
			[](Social ob, int temp_int) -> bool
			{
				return ob.getGroup() == temp_int;
			}, temp_int);
		system("pause");
		break;
	case 3:
		cout << "������� ������� ���� ��� ������:\n";
		temp_int = inputNumber(0, 10);
		list.find<int>(
			[](Social ob, int temp_int) -> bool
			{
				return ob.getMark() == temp_int;
			}, temp_int);
		system("pause");
		break;
	}
}

void Social::sort(List <Social>& list) {
	cout << "�������� ����������:\n1) ������������� �� ��������\n2) ������������� �� ������ ������\n3) ������������� �� �������� �����\n";
	cout << "4) ������������� �� ������� ���������\n5) ������������� �� ����������\n";
	int choice = inputNumber(1, 5);
	switch (choice)
	{
	case 1:
		list.sort(
			[](Social ob1, Social ob2) -> bool
			{
				return ob1.getSurname() > ob2.getSurname();
			});
		break;
	case 2:
		list.sort(
			[](Social ob1, Social ob2) -> bool
			{
				return ob1.getGroup() > ob2.getGroup();
			});
		break;
	case 3:
		list.sort(
			[](Social ob1, Social ob2) -> bool
			{
				return ob1.getMark() < ob2.getMark();
			});
		break;
	case 4:
		list.sort(
			[](Social ob1, Social ob2) -> bool
			{
				return ob1.getSum() < ob2.getSum();
			});
		break;
	case 5:
		list.sort(
			[](Social ob1, Social ob2) -> bool
			{
				return ob1.getActivity() > ob2.getActivity();
			});
		break;
	}
}

void Social::edit() {
	bool flag = true;
	int choice;
	while (flag) {
		system("cls");
		this->header();
		cout << "x)\t" << *this << "\n\n";
		cout << "�������� ���� ��� ���������:\n1) �������\n2) ����� ������\n3) ����������\n4) ������� ����\n5) ������� ����������\n\n0) ��������� ��������������\n";
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
			this->setCause();
			break;
		}
	}
}

istream& operator >> (istream& in, Social& student) {
	system("cls");
	in >> dynamic_cast<Schoolarship&>(student);
	student.setCause();
	student.calculateSum();
	return in;
}

ostream& operator << (ostream& out, Social& student) {
	cout << dynamic_cast<Schoolarship&>(student);
	cout << "\t\t" << student.getCause();
	return out;
}

void Social::read(List <Social>& v) {
	ifstream fin(FILE_WITH_SOCIAL, ios::in); // ������� ���� ��� ������
	int size;
	Social temp;
	if (fin.is_open()) {
		fin >> size;
		for (int i = 0; i < size; i++) {
			fin >> temp.surname
				>> temp.group
				>> temp.isActive
				>> temp.mark
				>> temp.sum
				>> temp.cause; //may trouble
			v.ListAdd(temp);
		}
	}
	fin.close(); //������� ����
}

void Social::write(List <Social>& list) {
	ofstream fout(FILE_WITH_SOCIAL, ios::out);
	fout << list.Size() << '\n';
	for (int i = 0; i < list.Size(); i++)
		fout << list[i].surname << ' ' << list[i].group << ' ' << list[i].isActive << ' ' << list[i].mark << ' ' << list[i].sum << ' ' << list[i].cause << '\n';
	fout.close();
}