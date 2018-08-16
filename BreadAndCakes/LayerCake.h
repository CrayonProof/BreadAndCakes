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
	string ToString();
	string GetType();
	double GetPrice();
	//Declared in LayerCake to keep LayerCake from being abstract
	void CakeIsAbstract();
private:
	int layerCount;
	double LCPRICE = 9.00;
	double LCLAYER_PRICE = 3.00;
	double LCREAM_CHEESE_PRICE = 1.00;
};

