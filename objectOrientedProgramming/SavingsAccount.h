#pragma once
#include "BankAccount.h"
class SavingsAccount :public BankAccount
{
	//True means active while false means inactive account
	bool Status;
public:
	//constructor
	SavingsAccount(AccountOwner accOwner, long bal, float rate);
	//checks if the account is active and sets the flag "status"
	void checkActive();
	//makes deposit transaction
	void deposit(long value);
	//makes withdraw transaction
	void withdraw(long value);
	//makes the monthly service charges calculations
	void monthlyProc();
	
};

