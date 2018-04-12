#pragma once
#include <vector>
#include <string>

//Отнимаем '0', тем самым преобразуя char в int
#define TO_INT - '0'	
//Прибавляем '0', тем самым преобразуя int в char
#define TO_CHAR + '0'

class unl_int
{
private:

	std::vector <char> *_dig = new std::vector<char>();
	void addNulls(unl_int*);

public:
	

	unl_int(){}							//Пустой конструктор
	unl_int(const char*);				//Конструктор для массивов
	unl_int(std::string*);				//Конструктор для string
	unl_int(int);						//Конструктор для int

	std::string to_string();			//Преобразование из unl_int в string
	void push_front(char);				//Вставить цифру в начало
	void push_back(char);				//Вставить цифру в конец
	void insert(size_t,char);			//Вставить цифру на позицию
	char at(size_t);					//Возвращает определенный элемент вектора
	size_t size();						//Возвращает длину числа

	bool unl_int::operator == (unl_int);
	bool unl_int::operator != (unl_int);
	bool unl_int::operator < (unl_int);
	bool unl_int::operator > (unl_int);
	
	unl_int operator + (unl_int);


}typedef unlimited_int; //typedef
