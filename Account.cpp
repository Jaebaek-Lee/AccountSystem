#include <iostream>
#include <iomanip>
#include "Account.h"

using namespace std;

Account::Account(int num) : num{ num }, name{ NULL }, bal{ 0 } {}

void Account::setName(string name) {
	this->name = name;
}

void Account::setbal(double balance) {
	this->bal = balance;
}

double Account::getBal() {
	return this->bal;
}

void Account::display() {
	cout << setfill('0') << setw(2) << num;
	cout << setfill(' ');
	cout << ' ' << setw(11) << left << name;
	cout << setw(7) << right << fixed << setprecision(2) << bal;
	cout << '\n';
}

/*
1
1
wook lee
0
2
dlwlrma
123.4567
2
0
5
2
5
2
2
-10.1
3
2
3
3
pby
-12.3
4
5
4
1
5
6

*/