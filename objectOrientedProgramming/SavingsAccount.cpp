#include "SavingsAccount.h"
#include <iostream>
//constructor calls constructor of parent class
SavingsAccount::SavingsAccount(AccountOwner accOwner, long bal, float rate):BankAccount(accOwner, bal, rate)
{
}
//checks if the account is active and sets the flag "status"
void SavingsAccount::checkActive()
{
	//Balance equal to or more than 25 means account is active
	if (Balance < 25)
	{
		Status = false;
	}
	else
	{
		Status = true;
	}
}
//makes deposit transaction
void SavingsAccount::deposit(long value)
{
	checkActive();
	//account is inactive and the deposit value will make it active
	if (!Status&&(Balance+value>=25))
	{
		Status = true;
	}
	BankAccount::deposit(value);
}
//makes withdraw transaction
void SavingsAccount::withdraw(long value)
{
	checkActive();
	//makes transaction if the account is active only
	if (Status)
	{
		BankAccount::withdraw(value);
	}
}
//makes the monthly service charges calculations
void SavingsAccount::monthlyProc()
{
	if (WithdrawalsNum > 4)
	{
		//monthly charges equal 1$ for each withdrawal more than 4
		MonthlyServiceCharges = WithdrawalsNum - 4;
		serviceCharge += MonthlyServiceCharges;
	}
	//deduct charges from account
	BankAccount::monthlyProc();
	//set the activity of the account after updating the alance of the account
	checkActive();
}
