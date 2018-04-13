#include "unl_int.h"
#include <iostream>

unl_int::unl_int(const char *new_dig)
{
	u_size_t *len = new u_size_t;			//Для хранения длины
	*len = strlen(new_dig);					//len - длина массива new_dig

	//Записываем по 1 из массива в вектор в обратном порядке
	for (s_size_t i = *len - 1; i >= 0; --i)
	{
		//Добавляем по 1 символу в конец вектора, преобразуя в int
		_dig->push_back(*(new_dig+i) TO_INT);
	}

	delete len;
	return;
}
unl_int::unl_int(std::string *new_dig)
{
	u_size_t *len = new u_size_t;			//Для хранения длины
	*len = new_dig->size();					//len - длина строки new_dig

	//Записываем по 1 из массива в вектор в обратном порядке
	for (s_size_t i = *len - 1; i >= 0; i--)
	{
		//Добавляем по 1 символу в конец вектора, преобразуя в int
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

	delete buff;
	return;
}

void unl_int::addNulls(unl_int *_dig1,unl_int *_dig2)
{
	
	//Длины чисел
	u_size_t size1 = _dig1->size();
	u_size_t size2 = _dig2->size();

	u_size_t *diff = new u_size_t;			//Разница длин
	*diff = 0;

	unl_int *ptr1, *ptr2;					//Указатели
	

	//ptr1 - всегда большее число, ptr2 - меньшее
	if (size1 > size2)
	{
		ptr1 = _dig1;
		ptr2 = _dig2;
	}
	else if (size1 < size2)
	{
		ptr1 = _dig2;
		ptr2 = _dig1;
	}
	//Если равны, то ничего добавлять не надо
	else return;	

	//Находим разницу длин между числами и добавляем нули
	*diff = ptr1->size() - ptr2->size();
	for (u_size_t i = 0; i < *diff; i++) ptr2->push_back(0);

	delete diff;
	return;
}
void unl_int::eraseNulls(unl_int *_dig1)
{
	//Длина числа
	u_size_t *len = new u_size_t;
	*len = _dig1->size();

	//Стираем пока не дойдем до конца или не кончатся нули
	while (*len > 1 && _dig1->at(*len - 1) == 0)
	{
		//Стираем последний символ
		_dig1->erase(*len - 1);
		(*len)--;
	}

	delete len;
	return;
}

std::string unl_int::to_string()
{
	std::string result;						//Результат
	u_size_t *len = new u_size_t;			//Длина числа

	//Присваиваем длину числа
	*len = this->size();					

	//Добавляем по 1 символу в конец строки, преобразуя в char
	for (s_size_t i = *len - 1; i >= 0; i--) result.push_back(this->at(i) TO_CHAR);

	delete len;
	//Возвращаем result
	return result;
}
void unl_int::push_front(char _new_dig)
{
	_dig->insert(_dig->begin(), _new_dig);
}
void unl_int::push_back(char _new_dig)
{
	_dig->push_back(_new_dig);
}
void unl_int::insert(u_size_t pos, char _new_dig)
{
	_dig->insert(_dig->begin() + pos, _new_dig);
}
void unl_int::erase(u_size_t pos)
{
	_dig->erase(_dig->begin() + pos);
}
char unl_int::at(u_size_t num)
{
	return _dig->at(num);
}
u_size_t unl_int::size()
{
	return _dig->size();
}

bool unl_int::operator == (unl_int _dig2)
{
	//Длины чисел
	u_size_t size1 = this->size(), size2 = _dig2.size();
	//Для начала сравним длины чисел
	if (size1 == size2)
	{
		//Сверим на равенство каждую цифру числа (для условия цикла берем любое значене size, т.к size1 = size2)
		for (u_size_t i = 0; i < size1; i++)
		{
			//Если не верно, то возвращаем false
			if (this->at(i) != _dig2.at(i)) return false;
		}
		//Каждая цифра совпала, возвращаем true
		return true;
	}
	//Длины чисел не равны
	return false;
}
bool unl_int::operator != (unl_int _dig2)
{
	return !(*this == _dig2);				//Возвращает значение, обратное ==
}
bool unl_int::operator < (unl_int _dig2)
{
	//Длины чисел
	u_size_t size1 = this->size(), size2 = _dig2.size();
	//Для начала сравним длины чисел
	if (size1 < size2) return true;
	if (size1 > size2) return false;
	//Сверим на равенство каждую цифру числа (для условия цикла берем любое значене size, т.к size1 = size2)
	for (u_size_t i = 0; i < size1; i++)
	{
		//Если меньше, то возвращаем true
		if (this->at(i) < _dig2.at(i)) return true;
	}
	//Цикл закончился, значит число > или =
	return false;
}
bool unl_int::operator > (unl_int _dig2)
{
	//Возвращаем обратный результат логического сложения величин < и ==
	//T.е для того чтобы получить true, необходимо чтобы < и == были false
	return !((*this < _dig2) | (*this == _dig2));	
}

unl_int unl_int::operator + (unl_int _dig2)
{
	unl_int result;							//Для хранения результата
	char *buff = new char;					//Буффер для хранения чисел "в уме"
	*buff = 0;
	char *sum = new char;					//Буффер для хранения суммы 2 цифр
	u_size_t *len = new u_size_t;			//Длина чисел

	//Добавляем нули в начало, для равенства длин чисел, т.е 00123 например, если второе чилсо 5-ти значное
	addNulls(this,&_dig2);

	//Присваиваем len длину числа
	*len = this->size();
	//В цикле по каждой цифре складывем, записываем в result
	for (u_size_t i = 0; i < *len; i++)
	{
		//Сложение + "ум"
		*sum = this->at(i) + _dig2.at(i) + *buff;

		//Обнуляем "ум"
		*buff = 0;

		//Если сумма > 9, то 1 пишем в "ум", отнимаем 10 и пишем в sum;
		if (*sum > 9)
		{
			*sum -= 10;
			*buff = 1;
		}
		result.push_back(*sum);		//Пишем в result
		
	}
	//Если осталась 1 в "уме", складываем с последней цифрой 
	result.push_back(*buff);

	//Убираем лишние нули
	eraseNulls(&result);

	delete buff, len, sum;
	return result;
}
unl_int unl_int::operator - (unl_int _dig2)
{
	unl_int result;							//Для хранения результата
	u_size_t *len = new u_size_t;			//Длина чисел
	char *diff = new char;					//Буффер для хранения разности 2 цифр
	char *lend = new char;					//Занято ли у следующей цифры единица
	*lend = 0;

	//Добавляем нули в начало, для равенства длин чисел, т.е 00123 например, если второе чилсо 5-ти значное
	addNulls(this, &_dig2);

	//Присваиваем len длину числа
	*len = this->size();
	//В цикле по каждой цифре вычитаем, записываем в result
	for (u_size_t i = 0; i < *len - 1; i++)
	{
		//Вычитаем по 1 цифре, если был "заём", то вычитаем и его
		*diff = this->at(i) - _dig2.at(i) - (*lend);

		//Обнуляем "заём"
		*lend = 0;
		
		//Если цифра в уменьшаемом меньше, чем в вычитаемом, "занимаем" 1
		if (*diff < 0)
		{
			*diff += 10;
			*lend = 1;
		}
		result.push_back(*diff);
	}

	delete len, diff, lend;
	return result;
}




