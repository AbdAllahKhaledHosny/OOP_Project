#pragma once
#include <string>
#include "AccountOwner.h"
using namespace std;

 class  BankAccount
{	
	//Can not be accessed from main but can be accessed from sub classess (saving account or checking account)
	protected:
	//Owner of the account
	AccountOwner Owner;
	//Balance of the account
	long Balance;
	//initial balance
	long initialBalance;
	//Number of deposits made to the account
	int DepositsNum;
	//Number of withdrawals made to the account 
	int WithdrawalsNum;
	//Annual interest rate
	float InterestRate;
	//Monthly service charges
	float MonthlyServiceCharges;
	//accumulating charges paid for an account
	float serviceCharge;
	//APIs of the class 
	public:
	//constructor
	BankAccount(AccountOwner accOwner,long bal,float rate);
	//deposit mechanism of the account
	virtual void deposit(long value);
	//withdrawal mechanism of the account
	virtual void withdraw(long value);
	//Updating the balance according to interest rate
	virtual void calcInt();
	//Updating balance according to monthly service charge 
	virtual void monthlyProc();
	//shows history of the account 
	void showHistory();
	
};

