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
	void display(); //모두 cpp에서 설명
private:
	const int num; //계좌번호는 바뀔 수 없다.
	std::string name; //계좌주인이름
	double bal; //잔액
};

#endif