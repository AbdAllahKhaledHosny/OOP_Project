#pragma once
#include <string>
using namespace std;
class AccountOwner
{
	//Full name of the owner (First name + Last name)
	string FullName;
	//Mobile phone number
	string MobileNum; 
	//National ID number
	string NationalID;

public:
	//default constructor
	AccountOwner();
	//constructor of owner class (setting nof owner's name, mobile number and ID number) 
	AccountOwner(string name, string mob, string ID);

};

