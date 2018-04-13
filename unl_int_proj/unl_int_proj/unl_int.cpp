#include "unl_int.h"
#include <iostream>

unl_int::unl_int(const char *new_dig)
{
	u_size_t *len = new u_size_t;			//��� �������� �����
	*len = strlen(new_dig);					//len - ����� ������� new_dig

	//���������� �� 1 �� ������� � ������ � �������� �������
	for (s_size_t i = *len - 1; i >= 0; --i)
	{
		//��������� �� 1 ������� � ����� �������, ���������� � int
		_dig->push_back(*(new_dig+i) TO_INT);
	}

	delete len;
	return;
}
unl_int::unl_int(std::string *new_dig)
{
	u_size_t *len = new u_size_t;			//��� �������� �����
	*len = new_dig->size();					//len - ����� ������ new_dig

	//���������� �� 1 �� ������� � ������ � �������� �������
	for (s_size_t i = *len - 1; i >= 0; i--)
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

	delete buff;
	return;
}

void unl_int::addNulls(unl_int *_dig1,unl_int *_dig2)
{
	
	//����� �����
	u_size_t size1 = _dig1->size();
	u_size_t size2 = _dig2->size();

	u_size_t *diff = new u_size_t;			//������� ����
	*diff = 0;

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
	*diff = ptr1->size() - ptr2->size();
	for (u_size_t i = 0; i < *diff; i++) ptr2->push_back(0);

	delete diff;
	return;
}
void unl_int::eraseNulls(unl_int *_dig1)
{
	//����� �����
	u_size_t *len = new u_size_t;
	*len = _dig1->size();

	//������� ���� �� ������ �� ����� ��� �� �������� ����
	while (*len > 1 && _dig1->at(*len - 1) == 0)
	{
		//������� ��������� ������
		_dig1->erase(*len - 1);
		(*len)--;
	}

	delete len;
	return;
}

std::string unl_int::to_string()
{
	std::string result;						//���������
	u_size_t *len = new u_size_t;			//����� �����

	//����������� ����� �����
	*len = this->size();					

	//��������� �� 1 ������� � ����� ������, ���������� � char
	for (s_size_t i = *len - 1; i >= 0; i--) result.push_back(this->at(i) TO_CHAR);

	delete len;
	//���������� result
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
	//����� �����
	u_size_t size1 = this->size(), size2 = _dig2.size();
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
bool unl_int::operator != (unl_int _dig2)
{
	return !(*this == _dig2);				//���������� ��������, �������� ==
}
bool unl_int::operator < (unl_int _dig2)
{
	//����� �����
	u_size_t size1 = this->size(), size2 = _dig2.size();
	//��� ������ ������� ����� �����
	if (size1 < size2) return true;
	if (size1 > size2) return false;
	//������ �� ��������� ������ ����� ����� (��� ������� ����� ����� ����� ������� size, �.� size1 = size2)
	for (u_size_t i = 0; i < size1; i++)
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
	u_size_t *len = new u_size_t;			//����� �����

	//��������� ���� � ������, ��� ��������� ���� �����, �.� 00123 ��������, ���� ������ ����� 5-�� �������
	addNulls(this,&_dig2);

	//����������� len ����� �����
	*len = this->size();
	//� ����� �� ������ ����� ���������, ���������� � result
	for (u_size_t i = 0; i < *len; i++)
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

	//������� ������ ����
	eraseNulls(&result);

	delete buff, len, sum;
	return result;
}
unl_int unl_int::operator - (unl_int _dig2)
{
	unl_int result;							//��� �������� ����������
	u_size_t *len = new u_size_t;			//����� �����
	char *diff = new char;					//������ ��� �������� �������� 2 ����
	char *lend = new char;					//������ �� � ��������� ����� �������
	*lend = 0;

	//��������� ���� � ������, ��� ��������� ���� �����, �.� 00123 ��������, ���� ������ ����� 5-�� �������
	addNulls(this, &_dig2);

	//����������� len ����� �����
	*len = this->size();
	//� ����� �� ������ ����� ��������, ���������� � result
	for (u_size_t i = 0; i < *len - 1; i++)
	{
		//�������� �� 1 �����, ���� ��� "���", �� �������� � ���
		*diff = this->at(i) - _dig2.at(i) - (*lend);

		//�������� "���"
		*lend = 0;
		
		//���� ����� � ����������� ������, ��� � ����������, "��������" 1
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




