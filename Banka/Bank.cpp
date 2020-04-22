#include "Bank.h"
#include "Account.h"
#include "Client.h"
#include <iostream>

double Bank::defaultIr = 0.01;

double Bank::GetDefaultIr()
{
	return Bank::defaultIr;
}

void Bank::SetDefaultIr(double ir)
{
	Bank::defaultIr = ir;
}

Bank::Bank(int c, int a)
{
	this->clients = new Client *[c];
	this->accounts = new Account *[a];

	this->clientsCount = -1;
	this->accountsCount = -1;
}

Bank::~Bank()
{
	for (int i = 0; i < this->clientsCount; i++)
	{
		delete this->clients[i];
	}
	for (int i = 0; i < this->accountsCount; i++)
	{
		delete this->accounts[i];
	}
	delete[] this->clients;
	delete[] this->accounts;
}

Client* Bank::GetClient(int c)
{
	for (int i = 0; i <= clientsCount; i++)
	{
		if (this->clients[i]->GetCode() == c)
		{
			return this->clients[i];
		}
	}
	cout << "klient s kodem " << c << " nebyl nalezen" << endl;
	return NULL;
}

Account* Bank::GetAccount(int n)
{
	for (int i = 0; i <= accountsCount; i++)
	{
		if (this->accounts[i]->GetNumber() == n)
		{
			return this->accounts[i];
		}
	}
	cout << "Ucet s cislem " << n << " nebyl nalezen" << endl;
	return NULL;
}

Client* Bank::CreateClient(int c, string n)
{
	clientsCount++;
	this->clients[this->clientsCount] = new Client(c, n);

	return this->clients[this->clientsCount];
}

Account* Bank::CreateAccount(int n, Client* c)
{
	accountsCount++;
	this->accounts[this->accountsCount] = new Account(n, c);

	return this->accounts[this->accountsCount];
}

Account* Bank::CreateAccount(int n, Client* c, double ir)
{
	accountsCount++;
	this->accounts[this->accountsCount] = new Account(n, c, ir);

	return this->accounts[this->accountsCount];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p)
{
	accountsCount++;
	this->accounts[this->accountsCount] = new Account(n, c, p);

	return this->accounts[this->accountsCount];
}

Account* Bank::CreateAccount(int n, Client* c, Client* p, double ir)
{
	accountsCount++;
	this->accounts[this->accountsCount] = new Account(n, c, p, ir);

	return this->accounts[this->accountsCount];
}

void Bank::AddInterest()
{
	for (int i = 0; i <= this->accountsCount; i++)
	{
		this->accounts[i]->Deposit(this->accounts[i]->GetBalance() * this->accounts[i]->GetInterestRate() / 12.0);
	}
}