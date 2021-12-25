#pragma once
#include "Schoolarship.h"

// Константы (причины присвоения)
const string cause1 = "Инвалидность";
const string cause2 = "Малообеспеченная семья";
const string cause3 = "Проживание в зоне АЭС";
const string cause4 = "Сирота";

class Social : public Schoolarship
{
protected:
	static int amount_s; // Базовый размер социальной стипендии
	int cause = 0; // Причина присвоения социальной стипендии (номер константы)
public:
	Social() {};
	~Social() {};
	void header(); // Шапка для таблицы
	void edit(); // Метод изменения объекта
	void calculateSum(); // Метод пересчета стипендии
	static void find(List <Social>& list); // Поиск по различным параметрам
	static void sort(List <Social>& list); // Сортировка по различным параметрам
	static void read(List <Social>& list); // Чтение из файла
	static void write(List <Social>& list); // Запись в файл
	friend istream& operator >> (istream& in, Social& student); // Перегрузка ввода
	friend ostream& operator << (ostream& out, Social& student); // Перегрузка вывода
	static void setAmountSocial();
	static int getAmountSocial();
	void setCause();
	string getCause();
};