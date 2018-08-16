#pragma once
#include <string>
using namespace std;


class BakedGood
{
public:
	BakedGood();
	~BakedGood();
	virtual string ToString();
	bool Equals(BakedGood otherObject);
	virtual string GetType();
	virtual double GetPrice();
protected:
	double price;
};

