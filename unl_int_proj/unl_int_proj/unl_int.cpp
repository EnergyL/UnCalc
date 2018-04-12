#include "unl_int.h"
#include <iostream>

unl_int::unl_int(const char *new_dig)
{
	size_t *len = new size_t;				//��� �������� �����
	*len = strlen(new_dig);					//len - ����� ������� new_dig

	//���������� �� 1 �� ������� � ������ � �������� �������
	for (int i = *len - 1; i >= 0; --i)
	{
		//��������� �� 1 ������� � ����� �������, ���������� � int
		_dig->push_back(*(new_dig+i) TO_INT);
	}

	delete len;
	return;
}
unl_int::unl_int(std::string *new_dig)
{
	size_t *len = new size_t;				//��� �������� �����
	*len = new_dig->size();					//len - ����� ������ new_dig

	//���������� �� 1 �� ������� � ������ � �������� �������
	for (int i = *len - 1; i >= 0; i--)
	{
		//��������� �� 1 ������� � ����� �������, ���������� � int
		_dig->push_back(new_dig->at(i) TO_INT);
	}

	delete len;
	return;
}
unl_int::unl_int(int new_dig)
{
	std::string *buff = new std::string();	//������ ��� ��������������
	*buff = std::to_string(new_dig);		//��������������� �� int � string
	unl_int::unl_int(buff);					//�������� ����������� ��� string
}

void unl_int::addNulls(unl_int *_dig2)
{
	
	//����� �����
	size_t size1 = this->size();
    size_t size2 = _dig2->size();		
	unl_int *ptr1, *ptr2;					//���������
	size_t diff = 0;						//������� ����

	//ptr1 - ������ ������� �����, ptr2 - �������
	if (size1 > size2)
	{
		ptr1 = this;
		ptr2 = _dig2;
	}
	else if (size1 < size2)
	{
		ptr1 = _dig2;
		ptr2 = this;
	}
	//���� �����, �� ������ ��������� �� ����
	else return;	

	//������� ������� ���� ����� ������� � ��������� ����
	diff = ptr1->size() - ptr2->size();
	for (size_t i = 0; i < diff; i++) ptr2->push_back(0);

	return;
}

std::string unl_int::to_string()
{
	std::string result;						//���������
	size_t *len = new size_t;				//����� �����

	//����������� ����� �����
	*len = this->size();					

	//��������� �� 1 ������� � ����� ������, ���������� � char
	for (int i = *len - 1; i >= 0; i--) result.push_back(this->at(i) TO_CHAR);

	//������ ������, ���������� result
	delete len;
	return result;
}
void unl_int::push_front(char _new_dig)
{
	_dig->insert(_dig->begin(), _new_dig);
}
void unl_int::push_back(char _new_dig)
{
	_dig->push_back(_new_dig);				//��������� ����� � ����� �����
}
void unl_int::insert(size_t pos, char _new_dig)
{
	_dig->insert(_dig->begin() + pos, _new_dig);
}
char unl_int::at(size_t num)
{
	return _dig->at(num);					//���������� ������ ��������
}
size_t unl_int::size()
{
	return _dig->size();					//���������� ����� �����
}

bool unl_int::operator == (unl_int _dig2)
{
	//����� �����
	size_t size1 = this->size(), size2 = _dig2.size();
	//��� ������ ������� ����� �����
	if (size1 == size2)
	{
		//������ �� ��������� ������ ����� ����� (��� ������� ����� ����� ����� ������� size, �.� size1 = size2)
		for (size_t i = 0; i < size1; i++)
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
bool unl_int::operator != (unl_int _dig2)
{
	return !(*this == _dig2);				//���������� ��������, �������� ==
}
bool unl_int::operator < (unl_int _dig2)
{
	//����� �����
	size_t size1 = this->size(), size2 = _dig2.size();
	//��� ������ ������� ����� �����
	if (size1 < size2) return true;
	if (size1 > size2) return false;
	//������ �� ��������� ������ ����� ����� (��� ������� ����� ����� ����� ������� size, �.� size1 = size2)
	for (size_t i = 0; i < size1; i++)
	{
		//���� ������, �� ���������� true
		if (this->at(i) < _dig2.at(i)) return true;
	}
	//���� ����������, ������ ����� > ��� =
	return false;
}
bool unl_int::operator > (unl_int _dig2)
{
	//���������� �������� ��������� ����������� �������� ������� < � ==
	//T.� ��� ���� ����� �������� true, ���������� ����� < � == ���� false
	return !((*this < _dig2) | (*this == _dig2));	
}

unl_int unl_int::operator + (unl_int _dig2)
{
	unl_int result;							//��� �������� ����������
	char *buff = new char;					//������ ��� �������� ����� "� ���"
	*buff = 0;
	char *sum = new char;					//������ ��� �������� ����� 2 ����
	size_t *len = new size_t;				//����� �����

	//��������� ���� � ������, ��� ��������� ���� �����, �.� 00123 ��������, ���� ������ ����� 5-�� �������
	addNulls(&_dig2);

	//����������� len ����� �����
	*len = this->size();
	//� ����� �� ������ ����� ���������, ���������� � result
	for (size_t i = 0; i < *len; i++)
	{
		//�������� + "��"
		*sum = this->at(i) + _dig2.at(i) + *buff;

		//�������� "��"
		*buff = 0;

		//���� ����� > 9, �� 1 ����� � "��", �������� 10 � ����� � sum;
		if (*sum > 9)
		{
			*sum -= 10;
			*buff = 1;
		}
		result.push_back(*sum);		//����� � result
		
	}
	//���� �������� 1 � "���", ���������� � ��������� ������ 
	result.push_back(*buff);

	//������ ������
	delete buff, len, sum;
	return result;
}




