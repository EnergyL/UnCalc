#include "unl_int.h"
#include <iostream>

unl_int::unl_int(std::string _new_dig)
{
	*this = _new_dig;
	return;
}
unl_int::unl_int(const char *_new_dig)
{
	*this = _new_dig;
	return;
}
unl_int::unl_int(int _new_dig)
{
	*this = _new_dig;
	return;
}

void unl_int::addNulls						(unl_int *_dig1,unl_int *_dig2)
{
	
	//Длины чисел
	u_size_t size1 = _dig1->size();
	u_size_t size2 = _dig2->size();

	u_size_t diff = 0;						//Разница длин
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
	diff = ptr1->size() - ptr2->size();
	for (u_size_t i = 0; i < diff; i++) ptr2->push_back(0);

	return;
}
void unl_int::eraseNulls					(unl_int *_dig1)
{
	//Длина числа
	u_size_t len = _dig1->size();

	//Стираем пока не дойдем до конца или не кончатся нули
	while (len > 1 && _dig1->at(len - 1) == 0)
	{
		//Стираем последний символ
		_dig1->erase(len - 1);
		len--;
	}

	return;
}

void unl_int::push_front					(char _new_dig)
{
	_dig->insert(_dig->begin(), _new_dig);
}
void unl_int::push_back						(char _new_dig)
{
	_dig->push_back(_new_dig);
}
void unl_int::insert						(u_size_t pos, char _new_dig)
{
	_dig->insert(_dig->begin() + pos, _new_dig);
}
void unl_int::erase							(u_size_t pos)
{
	_dig->erase(_dig->begin() + pos);
	return;
}
void unl_int::clear							()
{
	_dig->clear();
}
std::string unl_int::to_string				()
{
	std::string result;						//Результат
	u_size_t *len = new u_size_t;			//Длина числа
											
	//Присваиваем длину числа
	*len = this->size();

	//Добавляем по 1 символу в конец строки, преобразуя в char
	for (u_size_t i = *len; i > 0; i--) result.push_back(this->at(i-1) TO_CHAR);

	delete len;
	return result;
}
char unl_int::at							(u_size_t num)
{
	return _dig->at(num);
}
u_size_t unl_int::size						()
{
	return _dig->size();
}

bool unl_int::operator ==					(unl_int _dig2)
{
	//Очищаем лишние нули, если там только нуль, его оставляем
	eraseNulls(this);
	if (this->size() == 0) this->push_back(0);
	eraseNulls(&_dig2);
	if (_dig2.size() == 0) _dig2.push_back(0);
	//Длины чисел
	u_size_t size1 = this->size();
	u_size_t size2 = _dig2.size();
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
bool unl_int::operator !=					(unl_int _dig2)
{
	return !(*this == _dig2);				//Возвращает значение, обратное ==
}
bool unl_int::operator <					(unl_int _dig2)
{
	//Очищаем лишние нули, если там только нуль, его оставляем
	eraseNulls(this);
	if (this->size() == 0) this->push_back(0);
	eraseNulls(&_dig2);
	if (_dig2.size() == 0) _dig2.push_back(0);
	//Длины чисел
	u_size_t size1 = this->size();
	u_size_t size2 = _dig2.size();

	//Для начала сравним длины чисел
	if (size1 < size2) return true;
	if (size1 > size2) return false;

	//Сверим на равенство каждую цифру числа (для условия цикла берем любое значене size, т.к size1 = size2)
	for (u_size_t i = size1; i > 0; i--)
	{
		//Если меньше - true, если больше - false
		if (this->at(i - 1) < _dig2.at(i - 1)) return true;
		if (this->at(i - 1) > _dig2.at(i - 1)) return false;
	}
	//Цикл закончился, значит число ==
	return false;
}
bool unl_int::operator <=					(unl_int _dig2)
{
	//Возвращаем результат логического сложения < и ==
	return (*this < _dig2) | (*this == _dig2);
}
bool unl_int::operator >					(unl_int _dig2)
{
	//Возвращаем обратный результат <=
	bool a = !(*this <= _dig2);
	return !(*this <= _dig2);
}
bool unl_int::operator >=					(unl_int _dig2)
{
	//Возвращаем обратный результат >
	return !(*this < _dig2);
}

unl_int unl_int::operator =					(std::string _new_dig)
{
	u_size_t len;							//Для хранения длины
	len = _new_dig.size();					//len - длина строки new_dig

	//Очищаем
	_dig->clear();

	//Записываем по 1 из массива в вектор в обратном порядке
	for (u_size_t i = len; i > 0; i--)
	{
		//Добавляем по 1 символу в конец вектора, преобразуя в int
		_dig->push_back(_new_dig.at(i - 1) TO_INT);
	}

	//Убираем лишние нули
	eraseNulls(this);

	return *this;
}
unl_int unl_int::operator =					(char _new_dig)
{
	//Очищаем, присваивем цифру
	_dig->clear();
	_dig->push_back(_new_dig);

	return *this;
}
unl_int unl_int::operator =					(const char *_new_dig)
{
	u_size_t len;							//Для хранения длины
	len = strlen(_new_dig);					//len - длина массива new_dig

	//Очищаем
	_dig->clear();

	//Записываем по 1 из массива в вектор в обратном порядке
	for (u_size_t i = len; i > 0; i--)
	{
		//Добавляем по 1 символу в конец вектора, преобразуя в int
		_dig->push_back(*(_new_dig + (i - 1)) TO_INT);
	}

	//Убираем лишние нули
	eraseNulls(this);

	return *this;
}
unl_int unl_int::operator =					(int _new_dig)
{
	std::string buff;							//Буффер для смены типа
	buff = std::to_string(_new_dig);			//Преобразовываем из int в string
	*this = buff;								//Обрабатываем как string

	return *this;
}

unl_int unl_int::operator +					(unl_int _dig2)
{
	unl_int result;							//Для хранения результата
	char buff;								//Буффер для хранения чисел "в уме"
	char sum;								//Буффер для хранения суммы 2 цифр
	u_size_t len;							//Длина чисел

	buff = 0;

	//Добавляем нули в начало, для равенства длин чисел
	addNulls(this,&_dig2);

	//Присваиваем len длину числа
	len = this->size();
	//В цикле по каждой цифре складывем, записываем в result
	for (u_size_t i = 0; i < len; i++)
	{
		//Сложение + "ум"
		sum = this->at(i) + _dig2.at(i) + buff;

		//Обнуляем число в "уме"
		buff = 0;

		//Если сумма > 9, то 1 пишем в "ум", отнимаем 10 у sum;
		if (sum > 9)
		{
			buff = 1;
			sum -= 10;
		}

		//Пишем в result
		result.push_back(sum);		
		
	}
	//Если осталась 1 в "уме", складываем с последней цифрой 
	result.push_back(buff);

	//Убираем лишние нули
	eraseNulls(&result);

	return result;
}
unl_int unl_int::operator -					(unl_int _dig2)
{
	unl_int result;							//Для хранения результата
	u_size_t len;							//Длина чисел
	char diff = 0;							//Буффер для хранения разности 2 цифр
	char lend = 0;							//Занято ли у следующей цифры единица


	//Добавляем нули в начало, для равенства длин чисел
	addNulls(this, &_dig2);

	//Присваиваем len длину числа
	len = this->size();
	//В цикле по каждой цифре вычитаем, записываем в result
	for (u_size_t i = 0; i < len; i++)
	{
		//Вычитаем по 1 цифре, если был "заём", то вычитаем и его
		diff = this->at(i) - _dig2.at(i) - lend;

		//Обнуляем "заём"
		lend = 0;
		
		//Если цифра в уменьшаемом меньше, чем в вычитаемом, "занимаем" 1
		if (diff < 0)
		{
			diff += 10;
			lend = 1;
		}

		//Пишем в result
		result.push_back(diff);
	}

	//Убираем лишние нули
	eraseNulls(&result);

	return result;
}
unl_int unl_int::operator *					(unl_int _dig2)
{
	unl_int result;							//Для хранения общего результата
	unl_int buff_result;					//Для временного хранения результата умножения на 1 цифру
	char buff;								//Буффер для хранения чисел "в уме"
	char mul;								//Буффер для хранения умножения 2 цифр
	unl_int *ptr1, *ptr2;					//Указатели

	//Длины чисел
	u_size_t size1 = 0;
	u_size_t size2 = 0;

	size1 = this->size();
	size2 = _dig2.size();
	buff = 0;
	mul = 0;

	//ptr1 - всегда большее число, ptr2 - меньшее
	if (size1 >= size2)
	{
		ptr1 = this;
		ptr2 = &_dig2;
	}
	else if (size1 < size2)
	{
		ptr1 = &_dig2;
		ptr2 = this;
	}

	//Присваиваем новые размеры
	size1 = ptr1->size();
	size2 = ptr2->size();

	//i - меньшее число, j - большее число
	for (u_size_t i = 0; i < size2; i++)
	{
		for (u_size_t j = 0; j < size1; j++)
		{
			//Умножаем + "ум"
			mul = ptr1->at(j) * ptr2->at(i) + buff;

			//Обнуляем число в "уме"
			buff = 0;

			//Если произведение > 9, то десятки пишем в "ум", а единицы в mul;
			if (mul > 9)
			{
				buff = mul / 10;
				mul = mul % 10;
			}

			//Добавляем в buff_result
			buff_result.push_back(mul);
		}
		//Если что - то осталось в buff, дописываем это в конец
		buff_result.push_back(buff);
		buff = 0;

		//Складываем с общим результатом, предварительно "сдвинув" на 1 разряд
		for (u_size_t k = 0; k < i; k++)
		{
			//Добавляем нули, тем самым "сдвигая" разряд
			buff_result.push_front(0);
		}
		result = result + buff_result;

		//Очищаем buff_result
		buff_result.clear();
	}

	return result;
}
unl_int unl_int::operator /					(unl_int _dig2)
{
	if (*this == 0) return unl_int(0);
	unl_int result;							//Для хранения результата
	unl_int diff1, diff2;					//Часть делимого и цифра результата, умноженная на делитель (вычитаемое)
	u_size_t i = 0;							//Номер цифры, которую нужно добавить
	u_size_t j = 1;							/*Множитель, на который домнажается делитель, 
											чтобы получить максимально возможое вычитаемое*/
	
	i = this->size();						//Присваиваем длину

	for (i; i > 0; i--)
	{
		//Добавляем по 1 цифре из делимого в разность
		diff1.push_front(this->at(i - 1));

		//Если делитель больше части делимого, запишем нуль и пойдем дальше
		if (_dig2 > diff1)
		{
			result.push_front(0);
			continue;
		}

		//Обновляем множитель
		j = 1;

		//Пока не больше, чем часть делимого
		while(1)
		{
			diff2 = _dig2 * j;				//Домножаем на j, ищем максимально возможное вычитаемое из части деимого
			if ((diff2 + _dig2) > diff1)	//Проверяем, если умножение на след. множитель больше части делимого, выходим из цикла
				break;
			j++;							//Увеличиваем множитель
		}
		result.push_front(j);				//Записываем результат
		diff1 = diff1 - diff2;				//Переписываем новую часть делимого
		diff2.clear();						//Очищаем вычитаемое
	}
	
	//Убираем лишние нули
	eraseNulls(&result);
	
	return result;
}

unl_int unl_int::inv						(u_size_t num)
{
	unl_int mul = *this;
	for (u_size_t i = 0; i < num; i++)
	{
		*this = (*this) * mul;
	}
	return *this;
}
