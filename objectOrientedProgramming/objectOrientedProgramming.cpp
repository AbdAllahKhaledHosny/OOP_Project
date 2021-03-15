// objectOrientedProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "BankAccount.h"
#include "SavingsAccount.h"
#include "AccountOwner.h"
#include "CheckingAccount.h"
using namespace std;

int main()
{
	//user1
	AccountOwner owner1("ahmed","01111111111","12345678901234");
	//number of user1 accounts
	int owner1Accounts = 0;
	//accounts of user1
	BankAccount* acc1[10];
	//user2
	AccountOwner owner2("mohammed", "01011111111", "12345678904321");
	//number of user2 accounts
	int owner2Accounts = 0;
	//accounts of user2
	BankAccount* acc2[10];
	//annual rate (used when creating new account)
	float rate;
	//balance of the newly created account
	long balance;
	//variables to hold user choice in the program
	int choice1, user,choice3,accNum,type,transaction;


	while (1)
	{
		cout << "Welcome to the bank home page,what would you like to do?" << endl;
		cout << "1-show users" << endl;
		cout << "2-exit" << endl;
		cin >> choice1;
		while (choice1!=1&& choice1 != 2)
		{
			cout << "please choose a valid number 1 or 2" << endl;
			cin >> choice1;
		}
		//user selected showusers
		if (choice1 == 1)
		{
			cout << "please select the user you want" << endl;
			cout << "1-Ahmed" << endl;
			cout << "2-Mohammed" << endl;
			cin >> user;
			//user entered uncorrect user
			while (user != 1 && user != 2)
			{
				cout << "please select correct user" << endl;
				cin >> user;
			}
			if (user == 1)
			{
				cout << "welcome Ahmed ";
			}
			else
			{
				cout << "welcome Mohammed";
			}

			cout << "what would you like to do?" << endl;
			cout << "1-show accounts" << endl;
			cout << "2-create new account" << endl;
			cin >> choice3;
			//user entered uncorrect choice
			while (choice3 != 1 && choice3 != 2)
			{
				cout << "please enter a valid choice" << endl;
				cin >> choice3;
			}
			//show accounts ptions
			if (choice3 == 1)
			{
				//user did not create users yet
				if ((user ==1&&owner1Accounts==0)||(user ==2 && owner2Accounts == 0))
				{
					cout << "user doe not have any accounts" << endl;
				}
				else
				{

					if (user == 1)
					{
						//print available accounts for user1
						for (int i = 1; i <= owner1Accounts; i++)
						{
							cout << i << "-account" << i << endl;						
						}
						cout << "select account" << endl;
						cin >> accNum;
						while (accNum < 1 || accNum > owner1Accounts)
						{
							//user enter invalid account number
							cout << "please enter valid account" << endl;
							cin >> accNum;
						}
						cout << "account" << accNum << "selected " << endl;
						cout << "what do you want to do?" << endl;
						cout << "1-deposit" << endl;
						cout << "2-withdrw" << endl;
						cout << "3-apply service charge" << endl;
						cout << "4-show statistics for the account" << endl;
						cin >> transaction;
						switch (transaction)
						{
						case (1):
						{
							//deposit option
							long val;
							cout << "enter deposit value" << endl;
							try
							{
								cin >> val;
								if (val > 0)
								{
									acc1[accNum - 1]->deposit(val);
									break;
								}
								else
								{
									throw(val);
								}
							}
							catch (long d)
							{
								cout << "deposit can not be negative" << endl;
								cout << "you entered: " << d;
							}
							break;
						}
						case(2):
						{
							//withdraw option
							long val;
							cout << "enter withdraw value" << endl;
			
							try
							{
								cin >> val;
								if (val > 0)
								{
									acc1[accNum - 1]->withdraw(val);
									break;
								}
								else
								{
									throw(val);
								}
							}
							catch (long d)
							{
								cout << "withdraw can not be negative" << endl;
								cout << "you entered: " << d << endl;
							}
							break;

						}
						case(3):
						{
							//deduct monthly charges and apply monthly interest rate
							acc1[accNum-1]->monthlyProc();
						}
						case(4):
						{
							//show statistics of the account
							acc1[accNum-1]->showHistory();
						}
						}
						
					}
					else
					{
						//print available accounts for user2
						for (int i = 1; i <= owner2Accounts; i++)
						{
							cout << i << "-account" << i << endl;
						}
						cout << "select account" << endl;
						cin >> accNum;
						while (accNum >= 1 && accNum < owner2Accounts)
						{
							//user selected invalid account number
							cout << "please enter valid account" << endl;
							cin >> accNum;
						}
						while (accNum < 1 || accNum > owner2Accounts)
						{
							cout << "please enter valid account" << endl;
							cin >> accNum;
						}
						cout << "account" << accNum << " selected " << endl;
						cout << "what do you want to do?" << endl;
						cout << "1-deposit" << endl;
						cout << "2-withdrw" << endl;
						cout << "3-apply service charge" << endl;
						cout << "4-show statistics for the account" << endl;
						cin >> transaction;
						switch (transaction)
						{
						case (1):
						{
							//deposit option
							long val;
							cout << "enter deposit value" << endl;
							try
							{
								cin >> val;
								if (val > 0)
								{
									acc2[accNum - 1]->deposit(val);
									break;
								}
								else
								{
									throw(val);
								}
							}
							catch (long d)
							{
								cout << "deposit can not be negative" << endl;
								cout << "you entered: " << d<<endl;
							}
							break;
						}
						case(2):
						{
							//withdraw option
							long val;
							cout << "enter withdraw value" << endl;
							try
							{
								cin >> val;
								if (val > 0)
								{
									acc2[accNum - 1]->withdraw(val);
									break;
								}
								else
								{
									throw(val);
								}
							}
							catch (long d)
							{
								cout << "withdraw can not be negative" << endl;
								cout << "you entered: " << d << endl;
							}
							break;
						}
						case(3):
						{
							//deduct monthly charges and apply monthly interest rate
							acc2[accNum - 1]->monthlyProc();
						}
						case(4):
						{
							//show statistics of the account
							acc2[accNum - 1]->showHistory();
						}
						}
					}
				}
			}
			else
			{
				//create account
				cout << "would you like to make 1-saving account or 2-checking account" << endl;
				cin >> type;
				while (type != 1 && type != 2)
				{
					cout << "enter avalid type" << endl;
					cin >> type;
				}
				cout << "enter the initial balance" << endl;

					try {
					//make sure that the initial is positive (handling exception)
					cin >> balance;
					if (balance > 0) {
						cout << "enter annual rate" << endl;
						try {
							cin >> rate;
							//ensure that the rate is within the range [0,1]
							if (rate >= 0 && rate <= 1) {
								if (user == 1)
								{
									if (type == 1)
									{
										//create saving account
										SavingsAccount saveAcc(owner1, balance, rate);
										acc1[owner1Accounts] = &saveAcc;
										owner1Accounts++;
									}
									else
									{
										//create checking account
										CheckingAccount checkAcc(owner1, balance, rate);
										acc1[owner1Accounts] = &checkAcc;
										owner1Accounts++;
									}
								}
								else
								{
									if (type == 1)
									{
										//create saving account
										SavingsAccount saveAcc(owner2, balance, rate);
										acc2[owner2Accounts] = &saveAcc;
										owner2Accounts++;
									}
									else
									{
										//create checking account
										CheckingAccount checkAcc(owner2, balance, rate);
										acc2[owner2Accounts] = &checkAcc;
										owner2Accounts++;
									}


								}
							}
							else {
								throw(rate);
							}
						}
						catch (float r)
						{
							cout << "rate can not be outside range [0,1]" << endl;
							cout << "you entered: " << r << endl;
						}
					}
					else {
						throw (balance);

					}
				}
				catch (long num) {
					cout << "You can not make account with negative balance" << endl;
					cout << "you've entered" << num << endl;
				
				}
				
				

			}


		}
		//exit choice in the program
		if (choice1 == 2)
		{
			break;
		}
	}

	
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
