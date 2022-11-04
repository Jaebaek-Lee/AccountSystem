#include <iostream>
#include <iomanip>
#include "Account.h"

using namespace std;

Account::Account(int num) : num{ num }, name{ NULL }, bal{ 0 } {} //name�� �ʱ�ȭ�Ǵ� ���� ���� ���� ����ڰ� ��Ÿ���� ���̴�. ���� NULL�� ���൵ �����ϴ�.
//���� ���ۺ��� �ʼ��� �����ؾ� �ߴٸ�, "0"ó�� �ؾ����� ��. NULL�� int�� �����Ͽ� ���ǹ��� !=, ==�����ڰ� ���۵��ϱ� �����̴�. �� ���, "0"�̶�� �̸��� ���� ����ڴ�
//���¸� �������� �� �ϴ� �һ�簡 �����. ���ڷ� ���� ���� ���¹�ȣ�� �����Ѵ�.

void Account::setName(string name) { //�Ϲ����� ���Լ�
	this->name = name;
}

void Account::setbal(double balance) { //�Ϲ����� ���Լ�
	this->bal = balance;
}

double Account::getBal() { //�Ϲ����� ���Լ�
	return this->bal;
}

void Account::display() { //�̹� ������ �ٽ�...?
	cout << setfill('0') << setw(2) << num; //�� ���� ������ num�� 10�϶��� 1~9�϶��� �����Ͽ� �ۼ��ؾ��ϴµ� ���ŷӴ�. �׷��� setw(2)�� 2��ŭ ������ ����ְ�,
	//�⺻������ ��������. 1~9�ϰ�� �տ� ���鹮�ڸ� 0���� ������ش�.
	cout << setfill(' '); //�� �Լ��� ������ ���� ��� ������ 0���� ����� ������, �ٽ� ���鹮�ڷ� ������Ѵ�,
	cout << ' ' << setw(10) << left << name; //�� ĭ ����ְ�, �̸��� 10ĭ��ŭ �����������ش�.
	cout << setw(8) << right << fixed << setprecision(2) << bal; //name���� �̸� ���� ���� �κ��� ������ �Ǿ� bal�� ������ ä��� ���� ���̴�.
	//���� �׳� 8��ŭ ���� ��� �������ķ� �Ҽ��� 2�ڸ����� �����Ͽ� balance�� ������ָ� ���̴�.
	//�� ���ļ� Accounts informatin.�� ������ 21��ŭ �����ϸ� �ȴ�. ���� �����ؼ� ���ĺ��� 20�� ���´�.
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