#include <iostream>
#ifndef ACCOUNT_H
#define ACCOUNT_H
#pragma once

class Account
{
public:
	Account(int);
	void setName(std::string);
	void setbal(double);
	double getBal();
	void display(); //��� cpp���� ����
private:
	const int num; //���¹�ȣ�� �ٲ� �� ����.
	std::string name; //���������̸�
	double bal; //�ܾ�
};

#endif