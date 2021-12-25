#pragma once
#include <iostream>
#include <functional>
#include "ListError.h"

using namespace std;

template<typename T>
class List
{
private:
	template<typename T>
	struct Node
	{
	public:
		T Data;
		Node<T>* Next;
		Node<T>* Previous;
	};
	Node<T>* First; // Указатель на первый элемент списка 
	Node<T>* Last; // Указатель на последний элемент списка 
	int size = 1;
public:
	List();
	~List() {
		clean();
	};
	void ListAdd(T data); // добавление объекта в лист
	bool isListEmpty(); // проверка на наличие объектов в листе
	void clean(); // очистка листа
	void del(int pos); // удаление конкретного элемента листа по индексу
	T& operator[](int pos); // перегрузка оператора [] для удобного обращения к элементам листа
	int Size(); // размер листа
	void sort(function<bool(T obj1, T obj2)> comp); // сортировка через лямбда-функцию
	template<typename Attr>
	void find(function<bool(T obj, Attr attr)> equalFunc, Attr _attr); // поиск через лямбда-функцию
};

template<typename T>
List<T>::List()
{
	First = NULL;
	Last = NULL;
	size = 0;
}

template<typename T>
bool List<T>::isListEmpty() {
	if (this->First == NULL) return true;
	else return false;
}

template<typename T>
void List<T>::ListAdd(T data)
{
	Node<T>* Item = new Node<T>();
	Item->Data = data;
	Item->Next = NULL;
	Item->Previous = Last;
	Last = Item;
	if (First == NULL)
	{
		First = Item;
	}
	else
	{
		Node<T>* Token = this->First;
		while ((Token->Next) != NULL)
		{
			Token = Token->Next;
		}
		Token->Next = Item;
	}
}

template<typename T>
int List<T>::Size()
{
	int num = 0;
	Node<T>* Token = this->First;
	if (this->First == NULL)
	{
		return 0;
	}
	while (Token->Next != NULL)
	{
		Token = Token->Next;
		num++;
	}
	num++;
	return num;
}

template<typename T>
void List<T>::clean()
{
	Node<T>* p, * q;
	p = First;
	while (p != NULL)
	{
		q = p->Next;
		delete p;
		p = q;
	}
	First = NULL;
	Last = NULL;
}

template<typename T>
T& List<T>::operator[](int location)
{	
	T obj = T();
	try {
		if (this->Size() == 0) throw ListError("Список пуст!");
		if (location + 1 > this->Size() || location < 0) throw ListError("Неправильный индекс!");
	}
	catch(ListError& e){
		cout << e.error_msg() << endl;
	}
	if (location == 0)
	{
		return First->Data;
	}
	Node<T>* Token = this->First;
	
	if (location == 0)
	{
		cout << First->Data;
	}
	else
	{
		for (int k = 0; k < location; k++)
		{
			Token = Token->Next;
		}
	}
	return Token->Data;
}

template<typename T>
void List<T>::del(int pos)
{
	Node<T>* Token = First;
	for (int i = 0; i <= pos; i++)
	{
		if (Token == First && size == 1 && i == pos)
		{
			Token->Next = NULL;
			Token->Previous = NULL;
			First = NULL;
			Last = NULL;
			size = 0;
			return;
		}
		if (Token == First && i == pos)
		{
			Token->Next->Previous = NULL;
			First = Token->Next;
			size--;
			continue;
		}
		else
		{
			if (Token == Last && i == pos)
			{
				Last = Token->Previous;
				Token->Previous->Next = NULL;
				size--;
				return;
			}
			else
				if (size == 3 && i == pos)
				{
					First->Next = Last;
					Last->Previous = First;
					size--;
					continue;
				}
				else if (i == pos)
				{
					Token->Next->Previous = Token->Previous;
					Token->Previous->Next = Token->Next;
					delete Token;
					size--;
					continue;
				}
		}
		Token = Token->Next;
	}
}

template <typename T>
void List<T>::sort(function<bool(T obj1, T obj2)> comp)
{
	Node<T>* i, * j;

	for (i = this->First; i->Next != nullptr; i = i->Next)
	{
		for (j = i->Next; j != nullptr; j = j->Next)
		{
			if (comp(i->Data, j->Data))
			{
				swap(i->Data, j->Data);
			}
		}
	}
}

template<typename T>
template<typename Attr>
void List<T>::find(function<bool(T obj, Attr attr)> equalFunc, Attr _attr)
{
	Node<T>* tempNode = First;
	int i = 0;
	
	while (tempNode != nullptr)
	{
		if (equalFunc(tempNode->Data, _attr)) {
			i++;
			if (i == 1) tempNode->Data.header();
			cout <<i <<")\t" <<tempNode->Data<<endl;
		} 
		tempNode = tempNode->Next;
	}
if (i == 0) cout << "По вашему запросу ничего не найдено!\n";
}