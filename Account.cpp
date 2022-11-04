#include <iostream>
#include <iomanip>
#include "Account.h"

using namespace std;

Account::Account(int num) : num{ num }, name{ NULL }, bal{ 0 } {} //name이 초기화되는 경우는 오직 실제 사용자가 나타났을 때이다. 따라서 NULL로 해줘도 무방하다.
//만약 시작부터 필수로 생성해야 했다면, "0"처럼 해야했을 것. NULL을 int로 간주하여 조건문의 !=, ==연산자가 오작동하기 때문이다. 이 경우, "0"이라는 이름을 가진 사용자는
//계좌를 생성하지 못 하는 불상사가 생긴다. 인자로 받은 수를 계좌번호로 설정한다.

void Account::setName(string name) { //일반적인 셋함수
	this->name = name;
}

void Account::setbal(double balance) { //일반적인 셋함수
	this->bal = balance;
}

double Account::getBal() { //일반적인 겟함수
	return this->bal;
}

void Account::display() { //이번 과제의 핵심...?
	cout << setfill('0') << setw(2) << num; //셋 필이 없으면 num이 10일때랑 1~9일때를 구분하여 작성해야하는데 번거롭다. 그래서 setw(2)로 2만큼 공간을 잡아주고,
	//기본적으로 우측정렬. 1~9일경우 앞에 공백문자를 0으로 만들어준다.
	cout << setfill(' '); //위 함수가 앞으로 나올 모든 공백을 0으로 만들기 때문에, 다시 공백문자로 해줘야한다,
	cout << ' ' << setw(10) << left << name; //한 칸 비워주고, 이름을 10칸만큼 좌측정렬해준다.
	cout << setw(8) << right << fixed << setprecision(2) << bal; //name에서 이름 쓰고 남은 부분이 공백이 되어 bal의 왼쪽을 채우고 있을 것이다.
	//이제 그냥 8만큼 공간 잡고 우측정렬로 소수점 2자리까지 고정하여 balance를 출력해주면 끝이다.
	//총 합쳐서 Accounts informatin.의 공간인 21만큼 차지하면 된다. 공백 포함해서 합쳐보면 20이 나온다.
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