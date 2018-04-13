#include "unl_int.h"
#include <iostream>

unl_int::unl_int							(const char *_new_dig)
{
	u_size_t *len = new u_size_t;			//��� �������� �����
	*len = strlen(_new_dig);				//len - ����� ������� new_dig

	//�� ��������� - ����
	if (*len == 0) _dig->push_back(0);
	else
	{
		//���������� �� 1 �� ������� � ������ � �������� �������
		for (s_size_t i = *len - 1; i >= 0; --i)
		{
			//��������� �� 1 ������� � ����� �������, ���������� � int
			_dig->push_back(*(_new_dig + i) TO_INT);
		}
	}
	
	delete len;
	return;
}
unl_int::unl_int							(std::string _new_dig)
{
	u_size_t *len = new u_size_t;			//��� �������� �����
	*len = _new_dig.size();					//len - ����� ������ new_dig

	//���������� �� 1 �� ������� � ������ � �������� �������
	for (s_size_t i = *len - 1; i >= 0; i--)
	{
		//��������� �� 1 ������� � ����� �������, ���������� � int
		_dig->push_back(_new_dig.at(i) TO_INT);
	}

	delete len;
	return;
}
unl_int::unl_int							(int _new_dig)
{
	//����������
	return;
}

void unl_int::addNulls						(unl_int *_dig1,unl_int *_dig2)
{
	
	//����� �����
	u_size_t *size1 = new u_size_t;
	u_size_t *size2 = new u_size_t;
	*size1 = _dig1->size();
	*size2 = _dig2->size();

	u_size_t *diff = new u_size_t;			//������� ����
	*diff = 0;

	unl_int *ptr1, *ptr2;					//���������
	

	//ptr1 - ������ ������� �����, ptr2 - �������
	if (*size1 > *size2)
	{
		ptr1 = _dig1;
		ptr2 = _dig2;
	}
	else if (*size1 < *size2)
	{
		ptr1 = _dig2;
		ptr2 = _dig1;
	}
	//���� �����, �� ������ ��������� �� ����
	else return;	

	//������� ������� ���� ����� ������� � ��������� ����
	*diff = ptr1->size() - ptr2->size();
	for (u_size_t i = 0; i < *diff; i++) ptr2->push_back(0);

	delete size1, size2, diff;
	return;
}
void unl_int::eraseNulls					(unl_int *_dig1)
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
	for (s_size_t i = *len - 1; i >= 0; i--) result.push_back(this->at(i) TO_CHAR);

	delete len;
	//���������� result
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
bool unl_int::operator !=					(unl_int _dig2)
{
	return !(*this == _dig2);				//���������� ��������, �������� ==
}
bool unl_int::operator <					(unl_int _dig2)
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
bool unl_int::operator >					(unl_int _dig2)
{
	//���������� �������� ��������� ����������� �������� ������� < � ==
	//T.� ��� ���� ����� �������� true, ���������� ����� < � == ���� false
	return !((*this < _dig2) | (*this == _dig2));	
}

unl_int unl_int::operator +					(unl_int _dig2)
{
	unl_int result;							//��� �������� ����������
	char *buff = new char;					//������ ��� �������� ����� "� ���"
	char *sum = new char;					//������ ��� �������� ����� 2 ����
	u_size_t *len = new u_size_t;			//����� �����

	*buff = 0;

	//��������� ���� � ������, ��� ��������� ���� �����
	addNulls(this,&_dig2);

	//����������� len ����� �����
	*len = this->size();
	//� ����� �� ������ ����� ���������, ���������� � result
	for (u_size_t i = 0; i < *len; i++)
	{
		//�������� + "��"
		*sum = this->at(i) + _dig2.at(i) + *buff;

		//�������� ����� � "���"
		*buff = 0;

		//���� ����� > 9, �� 1 ����� � "��", �������� 10 � sum;
		if (*sum > 9)
		{
			*buff = 1;
			*sum -= 10;
		}

		//����� � result
		result.push_back(*sum);		
		
	}
	//���� �������� 1 � "���", ���������� � ��������� ������ 
	result.push_back(*buff);

	//������� ������ ����
	eraseNulls(&result);

	delete buff, len, sum;
	return result;
}
unl_int unl_int::operator -					(unl_int _dig2)
{
	unl_int result;							//��� �������� ����������
	u_size_t *len = new u_size_t;			//����� �����
	char *diff = new char;					//������ ��� �������� �������� 2 ����
	char *lend = new char;					//������ �� � ��������� ����� �������

	*lend = 0;

	//��������� ���� � ������, ��� ��������� ���� �����
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

		//����� � result
		result.push_back(*diff);			
	}

	//������� ������ ����
	eraseNulls(&result);

	delete len, diff, lend;
	return result;
}
unl_int unl_int::operator *					(unl_int _dig2)
{
	unl_int result;							//��� �������� ������ ����������
	unl_int *buff_result = new unl_int;		//��� ���������� �������� ���������� ��������� �� 1 �����
	char *buff = new char;					//������ ��� �������� ����� "� ���"
	char *mul = new char;					//������ ��� �������� ��������� 2 ����
	unl_int *ptr1, *ptr2;					//���������

	//����� �����
	u_size_t *size1 = new u_size_t;
	u_size_t *size2 = new u_size_t;

	*size1 = this->size();
	*size2 = _dig2.size();
	*buff = 0;
	*mul = 0;

	//ptr1 - ������ ������� �����, ptr2 - �������
	if (*size1 >= *size2)
	{
		ptr1 = this;
		ptr2 = &_dig2;
	}
	else if (*size1 < *size2)
	{
		ptr1 = &_dig2;
		ptr2 = this;
	}

	//����������� ����� �������
	*size1 = ptr1->size();
	*size2 = ptr2->size();

	//��������� ���� � ������, ��� ��������� ���� �����
	addNulls(this, &_dig2);

	//i - ������� �����, j - ������� �����
	for (u_size_t i = 0; i < *size2; i++)
	{
		for (u_size_t j = 0; j < *size1; j++)
		{
			//�������� + "��"
			*mul = ptr1->at(j) * ptr2->at(i) + *buff;

			//�������� ����� � "���"
			*buff = 0;

			//���� ������������ > 9, �� ������� ����� � "��", ������� � mul;
			if (*mul > 9)
			{
				*buff = *mul / 10;
				*mul = *mul % 10;
			}

			//��������� � buff_result
			buff_result->push_back(*mul);
		}
		//���������� � ����� �����������, �������������� "�������" �� 1 ������
		for (u_size_t k = 0; k < i; k++)
		{
			//��������� ����, ��� ����� "�������" ������
			buff_result->push_front(0);
		}
		result = result + *buff_result;

		//������� buff_result
		buff_result->clear();
	}

	//������� ������ ����
	eraseNulls(&result);

	delete buff, mul, size1, size2, buff_result;
	return result;
}
