#pragma once
#include "Student.h"
#include "List.h"
#include <fstream>

const string FILE_WITH_DEFAULT = "default.txt";
const string FILE_WITH_PRESIDENT = "president.txt";
const string FILE_WITH_SOCIAL = "social.txt";
const string FILE_WITH_PERSONAL = "personal.txt";

class Schoolarship : public Student
{
protected:
	double sum = 0; // Размер стипендии
	static int base; // Базовая стипендия
	double koef = 1; // Коэффициент для расчета стипендии (относительно среднего балла)
public:
	Schoolarship() {}
	~Schoolarship() {}
	void header(); // Шапка для таблицы
	virtual void edit(); // Метод изменения объекта
	virtual void calculateSum(); // Метод пересчета стипендии
	void calculateKoef(); // Метод пересчета коэффициента
	static void find(List <Schoolarship>& list); // Поиск по различным параметрам
	static void sort(List <Schoolarship>& list); // Сортировка по различным параметрам
	static void read(List <Schoolarship>& list); // Чтение из файла
	static void write(List <Schoolarship>& list); // Запись в файл
	friend istream& operator >> (istream& in, Schoolarship& student); // Перегрузка ввода
	friend ostream& operator << (ostream& out, Schoolarship& student); // Перегрузка вывода
	static void setBase();
	static int getBase();
	double getSum();
	double getKoef();
};

