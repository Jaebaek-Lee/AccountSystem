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
	void display();
private:
	const int num;
	std::string name;
	double bal;
};

#endif