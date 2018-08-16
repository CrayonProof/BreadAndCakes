#pragma once
#include "Cake.h"
#include <string>
using namespace std;

class CupCake :
	public Cake
{
public:
	CupCake();
	CupCake(string cakeFlavor, string frostingType, string sprinkleColor);
	~CupCake();
	virtual string ToString();
	virtual string GetType();
	double GetPrice();
private:
	string sprinkleColor;
	double ccPRICE = 1.95;
	double ccCREAM_CHEESE_PRICE = 0.20;
};

