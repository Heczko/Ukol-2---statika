#pragma once
#include "Client.h"
#include <iostream>

class Account
{
private:
	static int objectsCount;

	int number;
	double balance;
	double interestRate;
	bool useDefaultIr;

	Client* owner;
	Client* partner;

public:
	static int GetObjectsCount();

	Account(int n, Client* c);
	Account(int n, Client* c, double ir);
	Account(int n, Client* c, Client* p);
	Account(int n, Client* c, Client* p, double ir);
	~Account();

	int GetNumber();
	double GetBalance();
	double GetInterestRate();
	Client* GetOwner();
	Client* GetPartner();
	bool CanWithdraw(double a);
	bool GetUseDefaultIr();

	void Deposit(double a);
	bool Withdraw(double a);
	void AddInterest();
};