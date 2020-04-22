#pragma once
#include "Client.h"
#include "Account.h"
#include <iostream>

class Bank
{
private:
	static double defaultIr;

	Client** clients;
	int clientsCount;

	Account** accounts;
	int accountsCount;

public:
	static double GetDefaultIr();
	static void SetDefaultIr(double ir);

	Bank(int c, int a);
	~Bank();

	Client* GetClient(int c);
	Account* GetAccount(int n);

	Client* CreateClient(int c, string n);
	Account* CreateAccount(int n, Client* c);
	Account* CreateAccount(int n, Client* c, double ir);
	Account* CreateAccount(int n, Client* c, Client* p);
	Account* CreateAccount(int n, Client* c, Client* p, double ir);

	void AddInterest();
};

