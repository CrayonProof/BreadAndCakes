#pragma once
#include "BakedGood.h"
#include <string>
using namespace std;

class Bread :
	public BakedGood
{
public:
	Bread();
	Bread(string breadVariety);
	~Bread();
	string ToString();
	string GetType();
	double GetPrice();
private:
	string breadVariety;
	double BREAD_PRICE = 4.50;
};

