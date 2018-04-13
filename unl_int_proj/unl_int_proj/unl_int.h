#pragma once
#include "header.h"

class unl_int
{
private:

	std::vector <char> *_dig = new std::vector<char>();

	static void addNulls(unl_int*,unl_int*);
	static void eraseNulls(unl_int*);

public:
	

	unl_int(){}							//Пустой конструктор
	unl_int(const char*);				//Конструктор для массивов
	unl_int(std::string*);				//Конструктор для string
	unl_int(int);						//Конструктор для int

	std::string to_string();			//Преобразование из unl_int в string
	void push_front(char);				//Вставить цифру в начало
	void push_back(char);				//Вставить цифру в конец
	void insert(u_size_t,char);			//Вставить цифру
	void erase(u_size_t pos);			//Стереть цифру
	char at(u_size_t);					//Возвращает определенный элемент вектора
	u_size_t size();					//Возвращает длину числа

	//Операторы
	bool unl_int::operator == (unl_int);
	bool unl_int::operator != (unl_int);
	bool unl_int::operator < (unl_int);
	bool unl_int::operator > (unl_int);
	
	unl_int operator + (unl_int);
	unl_int operator - (unl_int);


}typedef unlimited_int; //typedef
