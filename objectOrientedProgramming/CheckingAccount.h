#pragma once
#include "BankAccount.h"
class CheckingAccount :public BankAccount
{
public:
	//constructor
	CheckingAccount(AccountOwner accOwner, long bal, float rate);
	//makes withdraw transaction
	void withdraw(long value);
	//makes monthly service charges deduction from the balance
	void monthlyProc();
	
};

