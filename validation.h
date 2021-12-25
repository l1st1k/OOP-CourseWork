#pragma once

#include <iostream>

using namespace std;

// ПРОВЕРКА НА ВВОД	
// Ввод чисел
int inputNumber(int left_range, int right_range);
// Проверка на число
bool isNumberNumeric();
// Проверка на ввод числа из корректного промежутка
bool isNumberRangeCorrect(int number, int left_range, int right_range);