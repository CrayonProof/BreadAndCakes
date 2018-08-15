#pragma once
#include <string>
using namespace std;


class BakedGood
{
public:
	BakedGood();
	~BakedGood();
	virtual string ToString();
protected:
	double price;
};

