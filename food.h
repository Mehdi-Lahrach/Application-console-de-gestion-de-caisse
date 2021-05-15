#pragma once

#include <iostream>

class food
{
public:


	food();
	food(std::string n, double p =0.0 , int c=0 , int id = 0);
	~food();
;
//getters
	double getprice(int q = 1);
    int getID();
	int getcounter();
	std::string getname();
	
//setters
	void setcounter(int q);
	void setFoodPrice(double p);
	void setname(std::string n);

private:
	const int Id;
	std::string name;
	double price;
	int counter;

};





