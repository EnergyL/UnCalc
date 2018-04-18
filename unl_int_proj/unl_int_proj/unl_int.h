#pragma once
#include "header.h"

class unl_int
{
private:

	std::vector <char> *_dig = new std::vector<char>();

	static void addNulls			(unl_int*,unl_int*);			//�������� ���� �� ��������� �� ���-�� ����
	static void eraseNulls			(unl_int*);						//������ ������ ���� � ������

public:
	

	unl_int							() {}							//������ �����������
	unl_int(std::string);
	unl_int(const char*);
	unl_int(int);

	void push_front					(char);							//�������� ����� � ������
	void push_back					(char);							//�������� ����� � �����
	void insert						(u_size_t,char);				//�������� �����
	void erase						(u_size_t pos);					//������� �����
	void clear						();								//������� ��
	std::string to_string			();								//�������������� �� unl_int � string
	char at							(u_size_t);						//���������� ������������ ������� �������
	u_size_t size					();								//���������� ����� �����

	//���������
	bool operator ==				(unl_int);
	bool operator !=				(unl_int);
	bool operator <					(unl_int);
	bool operator <=				(unl_int);
	bool operator >					(unl_int);
	bool operator >=				(unl_int);

	unl_int operator =				(std::string);
	unl_int operator =				(char);
	unl_int operator =				(const char*);
	unl_int operator=				(int _new_dig);

	unl_int operator +				(unl_int);
	unl_int operator -				(unl_int);
	unl_int operator *				(unl_int);
	unl_int operator /				(unl_int);

	//�������
	unl_int inv						(u_size_t);						//���������� � �������


}typedef unlimited_int; //typedef
