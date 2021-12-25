#include "validation.h"



bool isNumberNumeric() {
	if (cin.get() == '\n') return true;
	else
	{
		cin.clear();
		cin.ignore(256, '\n');
		return false;
	}
}

bool isNumberRangeCorrect(int number, int left_range, int right_range) {
	if ((number >= left_range) && (number <= right_range))return true;
	else return false;
}

int inputNumber(int left_range, int right_range) {
	int number;
	while (true) {
		cin >> number;
		if (isNumberNumeric() && isNumberRangeCorrect(number, left_range, right_range)) {
			return number;
		}
		else {
			cout << "Некорректный ввод!" << endl;
			cout << "Введите корректные данные: ";
		}
	}
}