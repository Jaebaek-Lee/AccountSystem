#include <iostream>
#include "Account.h"

using namespace std;

Account::Account(int num) : num{ num }, name{ NULL }, bal{ 0 } {}

void Account::setName(string name) {
	this->name = name;
}

void Account::setbal(double balance) {
	this->bal = balance;
}

string Account::getName() {
	return this->name;
}