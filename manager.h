#pragma once
#include<iostream>

class manager
{
public:
	manager();
	manager(std::string p, double a = 0);

	//getters
	std::string getpasswd();
	double getamountmoney();

	//setters
	void setamountmoney(double t);
	void setpasswd(std::string newpass);
	
	~manager();

private:
	std::string passwd;
	double Amountmoney;
};

