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

public:
	
	~unl_int();						//Деструктор

	unl_int(){}						//Пустой конструктор
	unl_int(const char*);			//Конструктор для массивов
	unl_int(std::string*);			//Конструктор для string
	unl_int(int);					//Конструктор для int

	char at(size_t);


}typedef unlimited_int; //typedef
