
#include "manager.h"

manager::manager() 
{
	passwd = "ESTSB";
	Amountmoney = 0.0;
}

manager::manager(std::string p, double a)
{
	passwd = p;
	Amountmoney = a;
}

std::string manager::getpasswd()
{
	return passwd;
}

void manager::setamountmoney(double t)
{
	Amountmoney += t;
}

double manager::getamountmoney()
{
	return Amountmoney;
}

void manager::setpasswd(std::string newpass)
{
	passwd = newpass;
}

manager::~manager() {}
