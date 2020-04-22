#include "Bank.h"
#include "Account.h"
#include "Client.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	Bank* bank = new Bank(200, 100);

	Bank::SetDefaultIr(0.010);
	cout << "default interest rate: " << Bank::GetDefaultIr() << endl;

	bank->CreateClient(1, "Novak");
	bank->CreateClient(2, "Svoboda");
	bank->CreateClient(3, "Novotny");
	bank->CreateClient(4, "Horak");
	bank->CreateClient(5, "Zeman");
	bank->CreateClient(6, "Urban");
	bank->CreateClient(7, "Soukup");
	bank->CreateClient(8, "Toman");
	bank->CreateClient(9, "Sikora");
	bank->CreateClient(10, "Lysek");
	
	cout << "Clients count: " << Client::GetObjectsCount() << endl;

	
	bank->CreateAccount(1, bank->GetClient(1));
	bank->CreateAccount(2, bank->GetClient(2));
	bank->CreateAccount(3, bank->GetClient(3));
	bank->CreateAccount(4, bank->GetClient(4), 0.015);
	bank->CreateAccount(5, bank->GetClient(5), 0.015);
	bank->CreateAccount(6, bank->GetClient(6), 0.015);
	bank->CreateAccount(7, bank->GetClient(7), 0.020);
	bank->CreateAccount(8, bank->GetClient(8), 0.020);
	bank->CreateAccount(9, bank->GetClient(9), 0.020);
	bank->CreateAccount(10, bank->GetClient(10), 0.020);
	
	cout << "Accounts count: " << Account::GetObjectsCount() << endl << endl;

	bank->GetAccount(1)->Deposit(100000);
	bank->GetAccount(4)->Deposit(100000);
	cout << " .. deposit 100000 - clients 1 and 4 .." << endl;

	cout << "client 1 name: " << bank->GetClient(1)->GetName() << endl;
	cout << "client 1 balance: " << fixed << setprecision(2) << bank->GetAccount(1)->GetBalance() << endl;
	cout << "client 1 interest rate: " << fixed << setprecision(3) << bank->GetAccount(1)->GetInterestRate() << endl << endl;

	cout << "client 4 name: " << bank->GetClient(4)->GetName() << endl;
	cout << "client 4 balance: " << fixed << setprecision(2) << bank->GetAccount(4)->GetBalance() << endl;
	cout << "client 4 interest rate: " << fixed << setprecision(3) << bank->GetAccount(4)->GetInterestRate() << endl << endl;

	bank->AddInterest();
	cout << " .. add month interests .." << endl;

	cout << "client 1 balance: " << fixed << setprecision(2) << bank->GetAccount(1)->GetBalance() << endl;
	cout << "client 4 balance: " << fixed << setprecision(2) << bank->GetAccount(4)->GetBalance() << endl << endl;
	
	cout << " .. withdraw 100000 - client 1 .." << endl;
	bank->GetAccount(1)->Withdraw(100000);

	cout << "client 1 balance: " << fixed << setprecision(2) << bank->GetAccount(1)->GetBalance() << endl;
	
	cout << " .. withdraw 1000 - client 1 .." << endl;
	bank->GetAccount(1)->Withdraw(1000);


	cout << "client 1 balance: " << fixed << setprecision(2) << bank->GetAccount(1)->GetBalance() << endl;

	delete bank;
	return 0;
}
