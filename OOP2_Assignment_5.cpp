#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"

using namespace std;

void interface() { //최대한 반복을 줄이기 위해 함수화
	cout << "1. input initial information\n"
		<< "2. update an account\n"
		<< "3. add a new account\n"
		<< "4. delete an account\n"
		<< "5. display information\n"
		<< "6. end program\n"
		<< "? ";
}

void input(Account* account) { //add 기능에서도 사용됩니다.
	string name; double balance;
	cin.ignore(); //accountSelector를 입력했을때 마지막에 개행문자가 남았기 때문에, 아래 getline함수가 입력을 받지 않고 종료된다. 따라서 ignore
	cout << "Enter name: ";
	getline(cin, name); //공백까지 포함해서 입력받는다. 그리고 마지막에 들어온 개행을 제거한다.
	account->setName(name);
	cout << "Enter balance: ";
	cin >> balance; //getline에서 마지막 개행이 제거되었으니 정상적으로 입력 커서 깜빡깜빡
	account->setbal(balance);
}

void update(Account* account) {
	double bal;
	account->display();
	cout << "Enter charge (+) or payment (-): ";
	cin >> bal;
	account->setbal(bal + account->getBal()); //클래스 내에 따로 함수를 둘 수도 있었겠지만, getbal을 이용해서 더 간단하게 해결하고자 함
	account->display();
}

int main() {
	/*int* a = new int{ 5 };
	cout << *a;*///배열이랑은 좀 다르게 동작한다.
	Account* account = new Account[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//account == &account[0] account는 힙공간에 생성된 객체 배열의 첫 번째 원소의 주소를 가리킨다.
	//과 같이 시작부터 10개의 계좌를 모두 생성하고
	//1 ~ 10을 인자로 보내서 num을 초기화한 뒤 name과 ball을 "0"과 NULL로 초기화.
	//처음에는 Account* account[10] = { nullptr, }; //Account 타입의 객체를 가리킬 수 있는 포인터 10개를 선언하고 모두 nullptr로 초기화하여
	//구현하였으나, 과제 일단 모든 계좌의 생성자가 호출되길 요구하는 것 같아 전체 수정함.
	//런타임에서 한 번도 생성되지 않은 계좌에 대해서는 생성자를 호출하지 않는게 더 효율적일 것 같았다...
	interface();

	int order = cin.get() - 48; //인터페이스에 입력할 명령. cin.get()은 개행을 남겨둔다.
	int accountSelector = 0; //명령을 수행할 계좌번호

	while (order != 6) { //6이 들어오면 탈출해서 프로그램 종료 수순 밟음.
		if (order == 1) { //input order
			cout << "\nEnter account number (1 - 10, 0 to end input): ";
			cin >> accountSelector; //개행을 무시한다.
			while (accountSelector != 0) { //계좌번호 0이 들어오면 탈출
				if (account[accountSelector - 1].getName() == "0") { //account[int]는 배열의 원소를 직접적으로 참조하고 있기 때문에, -> 아니고 .으로 한다.
					//account가 포인터로 구성된 배열이고 각각 원소가 개별적으로 객체를 참조한다면, ->였을것. ex) 처음 완성했던 객체 포인터 배열 코드
					//사용자가 입력하지 않은 계좌일 경우 name이 문자열 0일 것. 
					input(&account[accountSelector - 1]);
				}
				else cout << "Account already exists.\n";
				cout << "Enter account number (1 - 10, 0 to end input): ";
				cin >> accountSelector; //개행을 무시한다. 여기서 문자열 넣으면 cin객체가 fail상태로 돌아가고 프로그램은 무한루프에 빠진다...
			}
		}
		else if (order == 2) {
			cout << "\nEnter account number to update (1 - 10): ";
			cin >> accountSelector; //맨 앞 cin,get()에서 제대로된 값이 들어왔다면 여기서 cin이 버퍼의 첫 부분에 남은 개행을 무시해줄 것이라 문제 x.
			if (accountSelector != 0) {
				if (account[accountSelector - 1].getName() != "0") {
					update(&account[accountSelector - 1]);
				}
				else cout << "Account has no information.\n";
			}
		}
		else if (order == 3) {
			cout << "\nEnter new account number (1 - 10): ";
			cin >> accountSelector;
			if (accountSelector != 0) {
				if (account[accountSelector - 1].getName() == "0") {
					//account[accountSelector - 1] = new Account(accountSelector);
					input(&account[accountSelector - 1]);
					account[accountSelector - 1].display();
				}
				else cout << "Account already exists.\n";
			}
		}
		else if (order == 4) {
			cout << "\nEnter account number to delete (1 - 10): ";
			cin >> accountSelector;
			if (accountSelector != 0) {
				if (account[accountSelector - 1].getName() != "0") {
					account[accountSelector - 1].setName("0");
					//account[accountSelector - 1] = NULL;
					cout << "Account #" << accountSelector << " deleted.\n";
				}
				else cout << "Account #" << accountSelector << " is empty.\n";
			}
		}
		else if (order == 5) {
			cout << "\nAccounts information.\n";
			for (int i = 0; i < 10; ++i) {
				if (account[i].getName() != "0") {
					account[i].display();
				}
			}
		}
		cout << '\n';
		interface();
		cin >> order;
	}
	delete[] account;
	//왜 동작 안할까?
	//account는 포인터를 담고 있는 주소일 뿐이다. 이걸 해제해줘도 각각의 포인터가 간접 참조하는 것들은 살아있다.
	//일반적으로 delete는 그 라인에서 직접 new로 힙영역에 연결한 변수에 대해서만 동작하는 것 같다. 즉, 직접적으로 참조를 선언한 변수.
	/*for (int i = 0; i < 10; ++i) {
		delete account[i];
	}*/
}