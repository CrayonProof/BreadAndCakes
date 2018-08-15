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
private:
	string sprinkleColor;
};

