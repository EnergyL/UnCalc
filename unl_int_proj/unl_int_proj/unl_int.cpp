#include "unl_int.h"
#include <iostream>

unl_int::~unl_int()
{
	delete _dig;
}

unl_int::unl_int(const char *new_dig)
{
	size_t *len = new size_t;				//Для хранения длины
	*len = strlen(new_dig);					//len - длина массива new_dig

	//Записываем по 1 из массива в вектор
	for (size_t i = 0; i < *len; i++)
	{
		//Добавляем по 1 символу в конец вектора, преобразуя в int
		_dig->push_back(*(new_dig+i) TO_INT);
	}

	delete len;
	return;
}
unl_int::unl_int(std::string *new_dig)
{
	size_t *len = new size_t;				//Для хранения длины
	*len = new_dig->size();					//len - длина строки new_dig

	//Записываем по 1 из массива в вектор
	for (size_t i = 0; i < *len; i++)
	{
		_dig->push_back(new_dig->at(i) TO_INT);
	}

	delete len;
	return;
}
unl_int::unl_int(int new_dig)
{
	std::string *buff = new std::string();	//буффер для преобразования
	*buff = std::to_string(new_dig);		//Преобразовываем из int в string
	unl_int::unl_int(buff);					//Вызываем конструктор для string
}

char unl_int::at(size_t num)
{
	return _dig->at(num);					//Возвращаем нужное значение
}


