#pragma once
#include <string>
using namespace std;


class BakedGood
{
public:
	BakedGood();
	~BakedGood();
	virtual string ToString();
	virtual string GetType() = 0;
	virtual double GetPrice() = 0;
protected:
	double price;
};

