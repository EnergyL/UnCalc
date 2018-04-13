#pragma once
#include "header.h"

class unl_int
{
private:

	std::vector <char> *_dig = new std::vector<char>();

	static void addNulls(unl_int*,unl_int*);
	static void eraseNulls(unl_int*);

public:
	

	unl_int() {}						//������ �����������
	unl_int(const char*);				//����������� ��� ��������
	unl_int(std::string);				//����������� ��� string
	unl_int(int);						//����������� ��� int

	void push_front(char);				//�������� ����� � ������
	void push_back(char);				//�������� ����� � �����
	void insert(u_size_t,char);			//�������� �����
	void erase(u_size_t pos);			//������� �����
	void clear();						//������� ��
	std::string to_string();			//�������������� �� unl_int � string
	char at(u_size_t);					//���������� ������������ ������� �������
	u_size_t size();					//���������� ����� �����

	//���������
	bool unl_int::operator == (unl_int);
	bool unl_int::operator != (unl_int);
	bool unl_int::operator < (unl_int);
	bool unl_int::operator > (unl_int);
	
	unl_int operator + (unl_int);
	unl_int operator - (unl_int);
	unl_int operator * (unl_int);


}typedef unlimited_int; //typedef
