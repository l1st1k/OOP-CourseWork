#include "Student.h"

void Student::setGroup() {
	cout << "������� ����� ������� ������:\n";
	group = inputNumber(111111, 999999);
}

int Student::getGroup() {
	return group;
}

void Student::setMark() {
	cout << "������� ������� ���� ��������:\n";
	mark = inputNumber(0, 10);
}

int Student::getMark() {
	return mark;
}

void Student::setActivity() {
	cout << "������� ��������� �������� ������� � ����� ������������?\n1) ��\n2) ���\n";
	int temp = inputNumber(1, 2);
	if (temp == 1) isActive = true;
	else isActive = false;
}

string Student::getActivity() {
	if (!isActive) return NOT_ACTIVE;
	return ACTIVE;
}

void Student::setSurname() {
	cout << "������� ������� ��������:\n";
	cin >> surname;
}

string Student::getSurname() {
	return surname;
}