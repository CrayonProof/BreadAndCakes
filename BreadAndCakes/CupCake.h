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
	string ToString();
	string GetType();
	double GetPrice();
	//Declared in CupCake to keep CupCake from being abstract
	void CakeIsAbstract();
private:
	string sprinkleColor;
	double CCPRICE = 1.95;
	double CCCREAM_CHEESE_PRICE = 0.20;
};

