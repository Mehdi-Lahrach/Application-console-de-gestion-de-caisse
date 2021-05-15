
#include "food.h"


food::food() : Id(0)
{ 
	
	name = " ";
	price = 0.0;
	counter = 0;
}

food::food(std::string n, double p, int c ,int id ) :Id(id)
{
	
	name = n;
	price = p;
	counter = c;
	
}


 
double food::getprice(int q)
{
	return price*q;
}

 int food::getID()
{
	return Id;
}

int food::getcounter()
{
	return counter;
}

std::string food::getname()
{
	return name;
}

void food::setcounter(int q)
{
	counter += q;
}

void food::setFoodPrice(double p)
{
	price = p;
}

void food::setname(std::string n)
{
	name = n;
}

food::~food()
{
}


