#pragma once
#include <vector>
#include <string>

//�������� '0', ��� ����� ���������� char � int
#define TO_INT - '0'	
//���������� '0', ��� ����� ���������� int � char
#define TO_CHAR + '0'

class unl_int
{
private:

	std::vector <char> *_dig = new std::vector<char>();

public:
	
	~unl_int();						//����������

	unl_int(){}						//������ �����������
	unl_int(const char*);			//����������� ��� ��������
	unl_int(std::string*);			//����������� ��� string
	unl_int(int);					//����������� ��� int

	char at(size_t);


}typedef unlimited_int; //typedef
