#include "Student.h"

void Student::setGroup() {
	cout << "Введите номер учебной группы:\n";
	group = inputNumber(111111, 999999);
}

int Student::getGroup() {
	return group;
}

void Student::setMark() {
	cout << "Введите средний балл студента:\n";
	mark = inputNumber(0, 10);
}

int Student::getMark() {
	return mark;
}

void Student::setActivity() {
	cout << "Студент принимает активное участие в жизни университета?\n1) Да\n2) Нет\n";
	int temp = inputNumber(1, 2);
	if (temp == 1) isActive = true;
	else isActive = false;
}

string Student::getActivity() {
	if (!isActive) return NOT_ACTIVE;
	return ACTIVE;
}

void Student::setSurname() {
	cout << "Введите фамилию студента:\n";
	cin >> surname;
}

string Student::getSurname() {
	return surname;
}