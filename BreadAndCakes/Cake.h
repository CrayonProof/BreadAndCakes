#pragma once
#include "BakedGood.h"
class Cake :
	public BakedGood
{
public:
	Cake();
	Cake(string cakeFlavor, string frostingType);
	~Cake();
protected:
	string cakeFlavor;
	string frostingType;
};

