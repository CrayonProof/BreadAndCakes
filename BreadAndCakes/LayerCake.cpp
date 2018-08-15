#include "stdafx.h"
#include "LayerCake.h"
#include <sstream>

double PRICE = 9.00;
double LAYER_PRICE = 3.00;
double CREAM_CHEESE_PRICE = 1.00;

LayerCake::LayerCake() {
}

LayerCake::LayerCake(string cakeFlavor, string frostingType, int layerCount)
	: Cake(cakeFlavor, frostingType) {

	this->layerCount = layerCount;

	price = PRICE + (LAYER_PRICE * ((double) (layerCount - 1)));
	if (frostingType == "cream-cheese") {
		price +=(CREAM_CHEESE_PRICE * ((double) layerCount));
	}
}

LayerCake::~LayerCake() {
}

string LayerCake::ToString() {

	stringstream layerToString;
	layerToString << layerCount;

	return layerToString.str() + "-layer " + cakeFlavor + " cake with " + frostingType + " frosting (" + BakedGood::ToString() + ")";
}
