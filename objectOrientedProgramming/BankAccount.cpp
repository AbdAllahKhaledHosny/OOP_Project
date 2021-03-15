#include "BankAccount.h"
#include <string>
#include <iostream>

//constructor
BankAccount::BankAccount(AccountOwner accOwner, long bal, float rate)
{	
	//setting owner, balance and annual interest rate of the account
	Owner = accOwner;
	Balance = bal;
	initialBalance = bal;
	InterestRate = rate;
	//initialize no. of withdrawals and no. of deposits to zero and the monthly service charges to zero
	DepositsNum = 0;
	WithdrawalsNum = 0;
	MonthlyServiceCharges = 0;
	serviceCharge = 0;
}
//deposit mechanism of the account
void BankAccount:: deposit(long value)
{
	//increment balance by deposit value
	Balance += value;
	//increment no. of deposits by one
	DepositsNum++;
}
//withdrawal mechanism of the account
void BankAccount::withdraw(long value)
{
	//Decrement balance by the withdrawal value
	Balance -= value;
	//increment no. of withdrawals by one
	WithdrawalsNum++;
}
//Updating the balance according to interest rate
void BankAccount::calcInt()
{
	float monthlyInterest, monthlyRate;
	//calculating monthly rate
	monthlyRate = InterestRate / 12;
	//calculating monthly interest
	monthlyInterest = Balance * monthlyRate;
	//updating balance
	Balance += monthlyInterest;
}
//Updating balance according to monthly service charge 
void BankAccount::monthlyProc()
{
	//deduct the monthly service charges from the balance
	Balance -= MonthlyServiceCharges;
	//Updating the balance according to interest rate
	calcInt();
	//clears the no. of deposits,no. of withdrawals and monthly service charge
	DepositsNum = 0;
	WithdrawalsNum = 0;
	MonthlyServiceCharges = 0;
}
//shows history of the account 
void BankAccount::showHistory()
{
	cout << "initial balance: " << initialBalance << endl;
	cout << "ending balance: " << Balance << endl;
	cout << "No. of withdrawals: " << WithdrawalsNum << endl;
	cout << "Interest rate : " << InterestRate << endl;
	cout << "No. of Deposits: " << DepositsNum << endl;
	cout << "Monthly service charges:" << serviceCharge << endl;

}