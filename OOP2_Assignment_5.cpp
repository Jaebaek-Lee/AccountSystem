#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"

using namespace std;

void interface() {
	cout << "1. input initial information\n"
		<< "2. update an account\n"
		<< "3. add a new account\n"
		<< "4. delete an account\n"
		<< "5. display information\n"
		<< "6. end program\n"
		<< "? ";
}

void initial(Account& account) {
	string name; double balance;
	cin.ignore(); //accountSelector를 입력했을때 마지막에 개행문자가 남았기 때문에, 아래 getline함수가 입력을 받지 않고 종료된다. 따라서 ignore
	cout << "Enter name: ";
	getline(cin, name); //공백까지 포함해서 입력받는다. 그리고 마지막에 들어온 개행을 제거한다.
	account.setName(name);
	cout << "Enter balance: ";
	cin >> balance;
	account.setbal(balance);
}

int main() {
	Account* account[10] = { nullptr, }; //전부 null로 해놓고 생성을 따로 해도 될듯

	interface();

	int order = cin.get() - 48; //개행을 남겨둔다.
	int accountSelector = 0;

	while (order != 6) {
		if (order == 1) {
			cout << "\nEnter account number (1 - 10, 0 to end input): ";
			cin >> accountSelector; //개행을 무시한다.
			while (accountSelector != 0) {
				if (account[accountSelector - 1] == nullptr) {						
					account[accountSelector - 1] = new Account(accountSelector);
					//스코프 변수에 새로 할당한 것이 아니라서 스코프가 종료돼도 문제가 없다. 그리고 힙공간은 사라지지 않음.
					initial(*account[accountSelector - 1]);
				}
				else cout << "Account already exists.\n";
				cout << "Enter account number (1 - 10, 0 to end input): ";
				cin >> accountSelector; //개행을 무시한다.
			}
		}
		if (order == 2) {

		}
		cout << '\n';
		interface();
		cin >> order;
	}
}