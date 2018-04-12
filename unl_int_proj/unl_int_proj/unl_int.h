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
	void addNulls(unl_int*);

public:
	

	unl_int(){}							//������ �����������
	unl_int(const char*);				//����������� ��� ��������
	unl_int(std::string*);				//����������� ��� string
	unl_int(int);						//����������� ��� int

	std::string to_string();			//�������������� �� unl_int � string
	void push_front(char);				//�������� ����� � ������
	void push_back(char);				//�������� ����� � �����
	void insert(size_t,char);			//�������� ����� �� �������
	char at(size_t);					//���������� ������������ ������� �������
	size_t size();						//���������� ����� �����

	bool unl_int::operator == (unl_int);
	bool unl_int::operator != (unl_int);
	bool unl_int::operator < (unl_int);
	bool unl_int::operator > (unl_int);
	
	unl_int operator + (unl_int);


}typedef unlimited_int; //typedef
