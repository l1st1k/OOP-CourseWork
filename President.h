#pragma once
#include "Schoolarship.h"

class President : public Schoolarship
{
protected:
	static int amount_p; // Базовый размер президентской стипендии
	int year = 2021; // Год присвоения
public:
	President() {};
	~President() {};
	void header(); // Шапка для таблицы
	void edit(); // Метод изменения объекта
	void calculateSum(); // Метод пересчета стипендии
	static void find(List <President>& list); // Поиск по различным параметрам
	static void sort(List <President>& list); // Сортировка по различным параметрам
	static void read(List <President>& list); // Чтение из файла
	static void write(List <President>& list); // Запись в файл
	friend istream& operator >> (istream& in, President& student); // Перегрузка ввода
	friend ostream& operator << (ostream& out, President& student); // Перегрузка вывода
	static void setAmountPresident();
	static int getAmountPresident();
	void setYear();
	int getYear();
};

