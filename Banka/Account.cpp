#include "Bank.h"
#include "Account.h"
#include "Client.h"
#include <iostream>

int Account::objectsCount = 0;

int Account::GetObjectsCount()
{
	return Account::objectsCount;
}

Account::Account(int n, Client* c)
{
	this->number = n;
	this->interestRate = 0;
	this->useDefaultIr = true;
	this->owner = c;
	this->partner = NULL;
	this->balance = 0;
	Account::objectsCount += 1;
}

Account::Account(int n, Client* c, double ir)
{
	this->number = n;
	this->interestRate = ir;
	this->useDefaultIr = false;
	this->owner = c;
	this->partner = NULL;
	this->balance = 0;
	Account::objectsCount += 1;
}

Account::Account(int n, Client* c, Client* p)
{
	this->number = n;
	this->interestRate = 0;
	this->useDefaultIr = true;
	this->owner = c;
	this->partner = p;
	this->balance = 0;
	Account::objectsCount += 1;
}

Account::Account(int n, Client* c, Client* p, double ir)
{
	this->number = n;
	this->interestRate = ir;
	this->useDefaultIr = false;
	this->owner = c;
	this->partner = p;
	this->balance = 0;
	Account::objectsCount += 1;
}

Account::~Account()
{
	Account::objectsCount -= 1;
}

int Account::GetNumber()
{
	return this->number;
}

double Account::GetBalance()
{
	return this->balance;
}

double Account::GetInterestRate()
{
	if (this->GetUseDefaultIr())
	{
		return Bank::GetDefaultIr();
	}
	else
	{
		return this->interestRate;
	}
	
}

Client* Account::GetOwner()
{
	return this->owner;
}

Client* Account::GetPartner()
{
	return this->partner;
}

bool Account::CanWithdraw(double a)
{
	if (this->balance >= a)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Account::GetUseDefaultIr()
{
	return this->useDefaultIr;
}

void Account::Deposit(double a)
{
	this->balance += a;
}

bool Account::Withdraw(double a)
{
	if (this->CanWithdraw(a))
	{
		this->balance -= a;
		return true;
	}
	else
	{
		cout << "Not enough money in the account" << endl;
		return false;
	}
}

void Account::AddInterest()
{
	this->Deposit(this->interestRate);
}