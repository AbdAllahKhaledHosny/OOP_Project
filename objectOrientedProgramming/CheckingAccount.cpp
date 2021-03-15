#include "CheckingAccount.h"
//constructor calls constructor of parent class
CheckingAccount::CheckingAccount(AccountOwner accOwner, long bal, float rate) :BankAccount(accOwner, bal, rate)
{
}
//makes withdraw transaction
void CheckingAccount::withdraw(long value)
{
	//not enough balance in the account for the value of the check
	if (Balance - value < 0)
	{
		//makes 15$ charges without making the transaction
		Balance -= 15;
		return;
	}
	BankAccount::withdraw(value);
}
//makes monthly service charges deduction from the balance
void CheckingAccount::monthlyProc()
{	
	//calculates the monthly service charges (5$ fee plus 0.1$ for each withdrawal made)
	MonthlyServiceCharges = 5 + 0.1*WithdrawalsNum;
	serviceCharge += MonthlyServiceCharges;
	BankAccount::monthlyProc();
}
