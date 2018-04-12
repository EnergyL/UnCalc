#include "unl_int.h"
#include <iostream>

unl_int::~unl_int()
{
	delete _dig;
}

unl_int::unl_int(const char *new_dig)
{
	size_t *len = new size_t;				//��� �������� �����
	*len = strlen(new_dig);					//len - ����� ������� new_dig

	//���������� �� 1 �� ������� � ������
	for (size_t i = 0; i < *len; i++)
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

	//���������� �� 1 �� ������� � ������
	for (size_t i = 0; i < *len; i++)
	{
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

char unl_int::at(size_t num)
{
	return _dig->at(num);					//���������� ������ ��������
}


