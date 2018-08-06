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
	
	//����� �����
	u_size_t size1 = _dig1->size();
	u_size_t size2 = _dig2->size();

	u_size_t diff = 0;						//������� ����
	unl_int *ptr1, *ptr2;					//���������
	

	//ptr1 - ������ ������� �����, ptr2 - �������
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
	//���� �����, �� ������ ��������� �� ����
	else return;	

	//������� ������� ���� ����� ������� � ��������� ����
	diff = ptr1->size() - ptr2->size();
	for (u_size_t i = 0; i < diff; i++) ptr2->push_back(0);

	return;
}
void unl_int::eraseNulls					(unl_int *_dig1)
{
	//����� �����
	u_size_t len = _dig1->size();

	//������� ���� �� ������ �� ����� ��� �� �������� ����
	while (len > 1 && _dig1->at(len - 1) == 0)
	{
		//������� ��������� ������
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
	std::string result;						//���������
	u_size_t *len = new u_size_t;			//����� �����
											
	//����������� ����� �����
	*len = this->size();

	//��������� �� 1 ������� � ����� ������, ���������� � char
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
	//������� ������ ����, ���� ��� ������ ����, ��� ���������
	eraseNulls(this);
	if (this->size() == 0) this->push_back(0);
	eraseNulls(&_dig2);
	if (_dig2.size() == 0) _dig2.push_back(0);
	//����� �����
	u_size_t size1 = this->size();
	u_size_t size2 = _dig2.size();
	//��� ������ ������� ����� �����
	if (size1 == size2)
	{
		//������ �� ��������� ������ ����� ����� (��� ������� ����� ����� ����� ������� size, �.� size1 = size2)
		for (u_size_t i = 0; i < size1; i++)
		{
			//���� �� �����, �� ���������� false
			if (this->at(i) != _dig2.at(i)) return false;
		}
		//������ ����� �������, ���������� true
		return true;
	}
	//����� ����� �� �����
	return false;
}
bool unl_int::operator !=					(unl_int _dig2)
{
	return !(*this == _dig2);				//���������� ��������, �������� ==
}
bool unl_int::operator <					(unl_int _dig2)
{
	//������� ������ ����, ���� ��� ������ ����, ��� ���������
	eraseNulls(this);
	if (this->size() == 0) this->push_back(0);
	eraseNulls(&_dig2);
	if (_dig2.size() == 0) _dig2.push_back(0);
	//����� �����
	u_size_t size1 = this->size();
	u_size_t size2 = _dig2.size();

	//��� ������ ������� ����� �����
	if (size1 < size2) return true;
	if (size1 > size2) return false;

	//������ �� ��������� ������ ����� ����� (��� ������� ����� ����� ����� ������� size, �.� size1 = size2)
	for (u_size_t i = size1; i > 0; i--)
	{
		//���� ������ - true, ���� ������ - false
		if (this->at(i - 1) < _dig2.at(i - 1)) return true;
		if (this->at(i - 1) > _dig2.at(i - 1)) return false;
	}
	//���� ����������, ������ ����� ==
	return false;
}
bool unl_int::operator <=					(unl_int _dig2)
{
	//���������� ��������� ����������� �������� < � ==
	return (*this < _dig2) | (*this == _dig2);
}
bool unl_int::operator >					(unl_int _dig2)
{
	//���������� �������� ��������� <=
	bool a = !(*this <= _dig2);
	return !(*this <= _dig2);
}
bool unl_int::operator >=					(unl_int _dig2)
{
	//���������� �������� ��������� >
	return !(*this < _dig2);
}

unl_int unl_int::operator =					(std::string _new_dig)
{
	u_size_t len;							//��� �������� �����
	len = _new_dig.size();					//len - ����� ������ new_dig

	//�������
	_dig->clear();

	//���������� �� 1 �� ������� � ������ � �������� �������
	for (u_size_t i = len; i > 0; i--)
	{
		//��������� �� 1 ������� � ����� �������, ���������� � int
		_dig->push_back(_new_dig.at(i - 1) TO_INT);
	}

	//������� ������ ����
	eraseNulls(this);

	return *this;
}
unl_int unl_int::operator =					(char _new_dig)
{
	//�������, ���������� �����
	_dig->clear();
	_dig->push_back(_new_dig);

	return *this;
}
unl_int unl_int::operator =					(const char *_new_dig)
{
	u_size_t len;							//��� �������� �����
	len = strlen(_new_dig);					//len - ����� ������� new_dig

	//�������
	_dig->clear();

	//���������� �� 1 �� ������� � ������ � �������� �������
	for (u_size_t i = len; i > 0; i--)
	{
		//��������� �� 1 ������� � ����� �������, ���������� � int
		_dig->push_back(*(_new_dig + (i - 1)) TO_INT);
	}

	//������� ������ ����
	eraseNulls(this);

	return *this;
}
unl_int unl_int::operator =					(int _new_dig)
{
	std::string buff;							//������ ��� ����� ����
	buff = std::to_string(_new_dig);			//��������������� �� int � string
	*this = buff;								//������������ ��� string

	return *this;
}

unl_int unl_int::operator +					(unl_int _dig2)
{
	unl_int result;							//��� �������� ����������
	char buff;								//������ ��� �������� ����� "� ���"
	char sum;								//������ ��� �������� ����� 2 ����
	u_size_t len;							//����� �����

	buff = 0;

	//��������� ���� � ������, ��� ��������� ���� �����
	addNulls(this,&_dig2);

	//����������� len ����� �����
	len = this->size();
	//� ����� �� ������ ����� ���������, ���������� � result
	for (u_size_t i = 0; i < len; i++)
	{
		//�������� + "��"
		sum = this->at(i) + _dig2.at(i) + buff;

		//�������� ����� � "���"
		buff = 0;

		//���� ����� > 9, �� 1 ����� � "��", �������� 10 � sum;
		if (sum > 9)
		{
			buff = 1;
			sum -= 10;
		}

		//����� � result
		result.push_back(sum);		
		
	}
	//���� �������� 1 � "���", ���������� � ��������� ������ 
	result.push_back(buff);

	//������� ������ ����
	eraseNulls(&result);

	return result;
}
unl_int unl_int::operator -					(unl_int _dig2)
{
	unl_int result;							//��� �������� ����������
	u_size_t len;							//����� �����
	char diff = 0;							//������ ��� �������� �������� 2 ����
	char lend = 0;							//������ �� � ��������� ����� �������


	//��������� ���� � ������, ��� ��������� ���� �����
	addNulls(this, &_dig2);

	//����������� len ����� �����
	len = this->size();
	//� ����� �� ������ ����� ��������, ���������� � result
	for (u_size_t i = 0; i < len; i++)
	{
		//�������� �� 1 �����, ���� ��� "���", �� �������� � ���
		diff = this->at(i) - _dig2.at(i) - lend;

		//�������� "���"
		lend = 0;
		
		//���� ����� � ����������� ������, ��� � ����������, "��������" 1
		if (diff < 0)
		{
			diff += 10;
			lend = 1;
		}

		//����� � result
		result.push_back(diff);
	}

	//������� ������ ����
	eraseNulls(&result);

	return result;
}
unl_int unl_int::operator *					(unl_int _dig2)
{
	unl_int result;							//��� �������� ������ ����������
	unl_int buff_result;					//��� ���������� �������� ���������� ��������� �� 1 �����
	char buff;								//������ ��� �������� ����� "� ���"
	char mul;								//������ ��� �������� ��������� 2 ����
	unl_int *ptr1, *ptr2;					//���������

	//����� �����
	u_size_t size1 = 0;
	u_size_t size2 = 0;

	size1 = this->size();
	size2 = _dig2.size();
	buff = 0;
	mul = 0;

	//ptr1 - ������ ������� �����, ptr2 - �������
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

	//����������� ����� �������
	size1 = ptr1->size();
	size2 = ptr2->size();

	//i - ������� �����, j - ������� �����
	for (u_size_t i = 0; i < size2; i++)
	{
		for (u_size_t j = 0; j < size1; j++)
		{
			//�������� + "��"
			mul = ptr1->at(j) * ptr2->at(i) + buff;

			//�������� ����� � "���"
			buff = 0;

			//���� ������������ > 9, �� ������� ����� � "��", � ������� � mul;
			if (mul > 9)
			{
				buff = mul / 10;
				mul = mul % 10;
			}

			//��������� � buff_result
			buff_result.push_back(mul);
		}
		//���� ��� - �� �������� � buff, ���������� ��� � �����
		buff_result.push_back(buff);
		buff = 0;

		//���������� � ����� �����������, �������������� "�������" �� 1 ������
		for (u_size_t k = 0; k < i; k++)
		{
			//��������� ����, ��� ����� "�������" ������
			buff_result.push_front(0);
		}
		result = result + buff_result;

		//������� buff_result
		buff_result.clear();
	}

	return result;
}
unl_int unl_int::operator /					(unl_int _dig2)
{
	if (*this == 0) return unl_int(0);
	unl_int result;							//��� �������� ����������
	unl_int diff1, diff2;					//����� �������� � ����� ����������, ���������� �� �������� (����������)
	u_size_t i = 0;							//����� �����, ������� ����� ��������
	u_size_t j = 1;							/*���������, �� ������� ����������� ��������, 
											����� �������� ����������� �������� ����������*/
	
	i = this->size();						//����������� �����

	for (i; i > 0; i--)
	{
		//��������� �� 1 ����� �� �������� � ��������
		diff1.push_front(this->at(i - 1));

		//���� �������� ������ ����� ��������, ������� ���� � ������ ������
		if (_dig2 > diff1)
		{
			result.push_front(0);
			continue;
		}

		//��������� ���������
		j = 1;

		//���� �� ������, ��� ����� ��������
		while(1)
		{
			diff2 = _dig2 * j;				//��������� �� j, ���� ����������� ��������� ���������� �� ����� �������
			if ((diff2 + _dig2) > diff1)	//���������, ���� ��������� �� ����. ��������� ������ ����� ��������, ������� �� �����
				break;
			j++;							//����������� ���������
		}
		result.push_front(j);				//���������� ���������
		diff1 = diff1 - diff2;				//������������ ����� ����� ��������
		diff2.clear();						//������� ����������
	}
	
	//������� ������ ����
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
