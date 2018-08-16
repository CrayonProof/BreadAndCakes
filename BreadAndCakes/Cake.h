#pragma once
#include "BakedGood.h"
class Cake :
	public BakedGood
{
public:
	Cake();
	Cake(string cakeFlavor, string frostingType);
	~Cake();
	//Pure virtual function to make Cake class abstract
	virtual void CakeIsAbstract() = 0;
protected:
	string cakeFlavor;
	string frostingType;
};

