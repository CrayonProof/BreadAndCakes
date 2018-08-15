#pragma once
#include "Cake.h"
#include <String>
using namespace std;

class LayerCake :
	public Cake
{
public:
	LayerCake();
	LayerCake(string cakeFlavor, string frostingType, int layerCount);
	~LayerCake();
	virtual string ToString();
private:
	int layerCount;
};

