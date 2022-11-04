#include <iostream>
#include <string>
#include <iomanip>
#include "Account.h"

using namespace std;

void interface() { //최대한 반복을 줄이기 위해
	cout << "1. input initial information\n"
		<< "2. update an account\n"
		<< "3. add a new account\n"
		<< "4. delete an account\n"
		<< "5. display information\n"
		<< "6. end program\n"
		<< "? ";
}

void input(Account& account) { //add 기능에서도 사용됩니다.
	string name; double balance;
	cin.ignore(); //accountSelector를 입력했을때 마지막에 개행문자가 남았기 때문에, 아래 getline함수가 입력을 받지 않고 종료된다. 따라서 ignore
	cout << "Enter name: ";
	getline(cin, name); //공백까지 포함해서 입력받는다. 그리고 마지막에 들어온 개행을 제거한다.
	account.setName(name);
	cout << "Enter balance: ";
	cin >> balance; //getline에서 마지막 개행이 제거되었으니 정상적으로 입력 커서 깜빡깜빡
	account.setbal(balance);
}

void update(Account& account) {
	double bal;
	account.display();
	cout << "Enter charge (+) or payment (-): ";
	cin >> bal;
	account.setbal(bal + account.getBal()); //클래스 내에 따로 메소드를 둘 수도 있었겠지만, getbal를 이용해서 더 효율적으로 해결하고자 함.
	account.display();
}

int main() {
	Account* account[10] = { nullptr, }; //Account 타입의 객체를 가리킬 수 있는 포인터 10개를 선언하고 모두 nullptr로 초기화한다.
	//Account* account = new Account[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//account == &account[0] account는 힙공간에 생성된 객체 배열의 첫 번째 원소의 주소를 가리킨다.
	//과 같이 시작부터 10개의 계좌를 모두 생성하고
	//1 ~ 10을 인자로 보내서 num을 초기화한 뒤 name과 ball을 "0"과 NULL로 초기화.
	//위와 같이 만들어보기도 했으나, 생성되지도 않은 계좌에까지 메모리를 주는 것은 비효율적으로 보였다.
	//그래서 생성되지 않은 계좌번호는 nullptr을 가리키게 설정했다.
	//그리고, 모든 객체가 처음부터 생성될 경우, 사용자 정보가 있는지 없는지를 nullptr로 구분할 수 없고 내부에 있는 private 변수들로 판단해야 한다.
	//이 경우, name은 기본적으로 생성되었을 것이고, name이나 balance로 판단해야하는데, 이들고 생성 단계에서 필연적으로 '0'이나 NULL로 초기화해야한다.
	//또한 balance는 0일 경우를 고려해야하기때문에, 결국 name으로 판단해야한다. 즉, getName 함수까지 만들어줘야한다.
	//그런데, 사용자 이름이 0이면 어떡하나? 아니면 잔고가 0이면 어떡하나? 모호해진다. 따라서 아예 포인터 배열을 생성하여 사용자가 입력하지 않은 계좌에 대해서는
	//메모리를 내어주지 않기로 했다. 결국, 계좌 자체를 10개까지 생성할 수 있지만, 사용자가 실제로 존재하지 않는 계좌는 백지상태인 것이다.
	interface();

	int order = cin.get() - 48; //인터페이스에 입력할 명령. cin.get()은 개행을 남겨둔다.
	int accountSelector = 0; //명령을 수행할 계좌번호

	while (order != 6) { //6이 들어요면 탈출해서 프로그램 종료 수순 밟음.
		if (order == 1) { //input
			cout << "\nEnter account number (1 - 10, 0 to end input): ";
			cin >> accountSelector; //개행을 무시한다.
			while (accountSelector != 0) { //계좌번호에 0이 들어오면 탈출.
				if (account[accountSelector - 1] == nullptr) { //사용자가 입력하지 않은 계좌번호에 대해서는 해당 포인터가 nullptr일 것이다.
					account[accountSelector - 1] = new Account(accountSelector); //그럼 해당 포인터에 동적으로 객체를 할당해준다. 계좌번호를 인자로 전달한다.
					//이 스코프에서 생성한 변수에 할당한 것이 아니라서 스코프가 종료돼도 문제가 없다. 그리고 힙공간의 데이터는 이 스코프 끝나도 사라지지 않음.
					input(*account[accountSelector - 1]);//input 함수에 객체 자체를 전달해주고 레퍼런스로 받아 수정한다.
				}
				else cout << "Account already exists.\n";
				cout << "Enter account number (1 - 10, 0 to end input): ";
				cin >> accountSelector; //개행을 무시한다. 여기서 문자열 넣으면 cin객체가 fail상태로 돌아가고 프로그램은 무한루프에 빠진다...
			}
		}
		else if (order == 2) { //update
			cout << "\nEnter account number to update (1 - 10): ";
			cin >> accountSelector; //맨 앞 cin,get()에서 제대로된 값이 들어왔다면 여기서 cin이 버퍼의 첫 부분에 남은 개행을 무시해줄 것이라 문제 x.
			if (accountSelector != 0) { //0이면 탈출
				if (account[accountSelector - 1] != nullptr) { //입력받은 계좌번호에 해당하는 포인터가 nullptr이 아닐때, 즉 계좌가 백지 상태가 아닐때
					update(*account[accountSelector - 1]); //업데이트 함수를 호출하여 값을 수정한다.
				}
				else cout << "Account has no information.\n";
			}
		}
		else if (order == 3) { //add
			cout << "\nEnter new account number (1 - 10): ";
			cin >> accountSelector;
			if (accountSelector != 0) { //input함수랑 기본 구조가 동일하고, 루프와 display 유무에서만 차이를 보인다. 따로 설명 x.
				if (account[accountSelector - 1] == nullptr) {
					account[accountSelector - 1] = new Account(accountSelector);
					input(*account[accountSelector - 1]);
					account[accountSelector - 1]->display();
				}
				else cout << "Account already exists.\n";
			}
		}
		else if (order == 4) { //delete
			cout << "\nEnter account number to delete (1 - 10): ";
			cin >> accountSelector;
			if (accountSelector != 0) {
				if (account[accountSelector - 1] != nullptr) { //만약 계좌가 백지상태가 아니라면, 즉 사용자가 존재한다면
					delete account[accountSelector - 1]; //힙공간의 계좌 정보를 삭제하고
					account[accountSelector - 1] = nullptr; //계좌 포인터가 다시 nullptr을 가리키게 한다. 이 과정이 없으면 쓰레기값을 참조해버린다.
					cout << "Account #" << accountSelector << " deleted.\n";
				}
				else cout << "Account #" << accountSelector << " is empty.\n";
			}
		}
		else if (order == 5) { //display
			cout << "\nAccounts information.\n";
			for (int i = 0; i < 10; ++i) {
				if (account[i] != nullptr) { //0~9까지 돌면서 계좌가 존재하는지 판단한다.
					account[i]->display(); //있으면 출력한다.
				}
			}
		}
		cout << '\n';
		interface();
		cin >> order;
	}
	//delete[] account;왜 동작 안할까?
	//account는 포인터를 담고 있는 주소일 뿐이다. 이걸 해제해줘도 각각의 포인터가 간접 참조하는 것들은 살아있다.
	//일반적으로 delete는 그 라인에서 직접 new로 힙영역에 연결한 변수에 대해서만 동작하는 것 같다. 즉, 직접적으로 참조를 선언한 변수.
	for (int i = 0; i < 10; ++i) { //위와같은 이유로 각각의 동적으로 할당한 객체들을 모두 해제해준다.
		delete account[i];
	}
}