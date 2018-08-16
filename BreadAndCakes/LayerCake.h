#pragma once
#include "Cake.h"
#include <string>
using namespace std;

class LayerCake :
	public Cake
{
public:
	LayerCake();
	LayerCake(string cakeFlavor, string frostingType, int layerCount);
	~LayerCake();
	virtual string ToString();
	virtual string GetType();
	double GetPrice();
private:
	int layerCount;
	double lcPRICE = 9.00;
	double lcLAYER_PRICE = 3.00;
	double lcCREAM_CHEESE_PRICE = 1.00;
};

