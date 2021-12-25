#pragma once
#include "Account.h"
#include "President.h"
#include "Personal.h"
#include "Social.h"
#include "List.h"
#include "validation.h"
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
class Interface
{
public:
	static void AdminUI(); // Интерфейс для администратора
	static void UserUI(); // Интерфейс для пользователя
};

template<typename T>
void Interface<T>::AdminUI() {
	List<T> list;
	T::read(list);
	for (int i = 0; i < list.Size(); i++) list[i].calculateSum();
	T temp;
	bool flag = true;
	int choice, del_choice, confirm, edit_choice;
	while (flag) {
		if (list.isListEmpty())
		{
			system("cls");
			cout << "Список пуст" << endl;
		}
		else
		{
			system("cls");
			list[0].header();
			for (int i = 0; i < list.Size(); i++) {
				cout << i + 1 << "\t" << list[i] << endl;
			}
		}
		cout << "\n\nВыберите действие:\n1) Добавить стипендианта\n2) Удалить стипендианта\n3) Редактировать информацию о стипендианте\n";
		cout << "4) Отсортировать\n5) Поиск\n0) Вернуться назад\n";
		choice = inputNumber(0, 5);
		switch (choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			cin >> temp;
			list.ListAdd(temp);
			break;
		case 2:
			if (list.isListEmpty())
			{
				cout << "Список пуст" << endl;
				system("pause");
			}
			else
			{
				cout << "Введите номер стипендианта для удаления:\n";
				del_choice = inputNumber(1, list.Size());
				system("cls");
				cout << "Вы действительно хотите удалить стипендианта с фамилией " << list[del_choice - 1].getSurname() << " ?\n1) Да\n2) Нет\n";
				confirm = inputNumber(1, 2);
				if (confirm == 1) list.del(del_choice - 1);
			}
			break;
		case 3:
			if (list.isListEmpty())
			{
				cout << "Список пуст" << endl;
				system("pause");
			}
			else
			{
				cout << "Введите номер стипендианта для редактирования:";
				edit_choice = inputNumber(1, list.Size());
				list[edit_choice - 1].edit();
			}
			break;
		case 4:
			T::sort(list);
			break;
		case 5:
			T::find(list);
			break;
		}
	}
	T::write(list);
}

template<typename T>
void Interface<T>::UserUI() {
	List<T> list;
	T::read(list);
	T temp;
	bool flag = true;
	int choice;
	while (flag) {
		if (list.isListEmpty())
		{
			system("cls");
			cout << "Список пуст" << endl;
		}
		else
		{
			system("cls");
			list[0].header();
			for (int i = 0; i < list.Size(); i++) {
				cout << i + 1 << "\t" << list[i] << endl;
			}
		}
		cout << "\n\nВыберите действие:\n1) Добавить стипендианта\n";
		cout << "2) Отсортировать\n3) Поиск\n0) Вернуться назад\n";
		choice = inputNumber(0, 3);
		switch (choice)
		{
		case 0:
			flag = false;
			break;
		case 1:
			cin >> temp;
			list.ListAdd(temp);
			break;
		case 2:
			T::sort(list);
			break;
		case 3:
			T::find(list);
			break;
		}
	}
	T::write(list);
}