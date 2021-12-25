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
	static void AdminUI(); // ��������� ��� ��������������
	static void UserUI(); // ��������� ��� ������������
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
			cout << "������ ����" << endl;
		}
		else
		{
			system("cls");
			list[0].header();
			for (int i = 0; i < list.Size(); i++) {
				cout << i + 1 << "\t" << list[i] << endl;
			}
		}
		cout << "\n\n�������� ��������:\n1) �������� ������������\n2) ������� ������������\n3) ������������� ���������� � ������������\n";
		cout << "4) �������������\n5) �����\n0) ��������� �����\n";
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
				cout << "������ ����" << endl;
				system("pause");
			}
			else
			{
				cout << "������� ����� ������������ ��� ��������:\n";
				del_choice = inputNumber(1, list.Size());
				system("cls");
				cout << "�� ������������� ������ ������� ������������ � �������� " << list[del_choice - 1].getSurname() << " ?\n1) ��\n2) ���\n";
				confirm = inputNumber(1, 2);
				if (confirm == 1) list.del(del_choice - 1);
			}
			break;
		case 3:
			if (list.isListEmpty())
			{
				cout << "������ ����" << endl;
				system("pause");
			}
			else
			{
				cout << "������� ����� ������������ ��� ��������������:";
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
			cout << "������ ����" << endl;
		}
		else
		{
			system("cls");
			list[0].header();
			for (int i = 0; i < list.Size(); i++) {
				cout << i + 1 << "\t" << list[i] << endl;
			}
		}
		cout << "\n\n�������� ��������:\n1) �������� ������������\n";
		cout << "2) �������������\n3) �����\n0) ��������� �����\n";
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