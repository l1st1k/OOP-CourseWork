#pragma once
#include "Schoolarship.h"
#include "validation.h"
#include <iostream>

class Personal : public Schoolarship
{
protected:
	static int amount_pers; // Базовый размер именной стипендии
	string author; // Название стипендии
public:
	Personal () {};
	~Personal() {};
	void header(); // Шапка для таблицы
	void edit(); // Метод изменения объекта
	void calculateSum(); // Метод пересчета стипендии
	static void find(List <Personal>& list); // Поиск по различным параметрам
	static void sort(List <Personal>& list); // Сортировка по различным параметрам
	static void read(List <Personal>& list); // Чтение из файла
	static void write(List <Personal>& list); // Запись в файл
	friend istream& operator >> (istream& in, Personal& student); // Перегрузка ввода
	friend ostream& operator << (ostream& out, Personal& student); // Перегрузка вывода
	static void setAmountPersonal();
	static int getAmountPersonal();
	void setAuthor();
	string getAuthor();
};