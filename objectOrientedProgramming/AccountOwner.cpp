#include "AccountOwner.h"
//default constructor
AccountOwner::AccountOwner()
{
	//empty default constructor 
}
//constructor of owner class (setting nof owner's name, mobile number and ID number) 
AccountOwner::AccountOwner(string name, string mob, string ID)
{
	//setting name of account owner
	FullName = name;
	//setting mobile number of account owner
	MobileNum = mob;
	//setting national ID number of account owner
	NationalID = ID;
}
