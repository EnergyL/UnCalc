#pragma once
#include "header.h"

class unl_int
{
private:

	std::vector <char> *_dig = new std::vector<char>();

	static void addNulls			(unl_int*,unl_int*);			//Добавить нули до равенства по кол-ву цифр
	static void eraseNulls			(unl_int*);						//Убрать лишние нули в начале

public:
	

	unl_int							() {}							//Пустой конструктор
	unl_int(std::string);
	unl_int(const char*);
	unl_int(int);

	void push_front					(char);							//Вставить цифру в начало
	void push_back					(char);							//Вставить цифру в конец
	void insert						(u_size_t,char);				//Вставить цифру
	void erase						(u_size_t pos);					//Стереть цифру
	void clear						();								//Стереть всё
	std::string to_string			();								//Преобразование из unl_int в string
	char at							(u_size_t);						//Возвращает определенный элемент вектора
	u_size_t size					();								//Возвращает длину числа

	//Операторы
	bool operator ==				(unl_int);
	bool operator !=				(unl_int);
	bool operator <					(unl_int);
	bool operator <=				(unl_int);
	bool operator >					(unl_int);
	bool operator >=				(unl_int);

	unl_int operator =				(std::string);
	unl_int operator =				(char);
	unl_int operator =				(const char*);
	unl_int operator=				(int _new_dig);

	unl_int operator +				(unl_int);
	unl_int operator -				(unl_int);
	unl_int operator *				(unl_int);
	unl_int operator /				(unl_int);

	//Функции
	unl_int inv						(u_size_t);						//Возведение в степень


}typedef unlimited_int; //typedef
