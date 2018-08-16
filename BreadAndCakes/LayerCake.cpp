//#include "stdafx.h"
#include "LayerCake.h"
#include <sstream>

double lcPRICE = 9.00;
double lcLAYER_PRICE = 3.00;
double lcCREAM_CHEESE_PRICE = 1.00;

LayerCake::LayerCake() : Cake() {

	layerCount = 1;
	price = lcPRICE + (lcLAYER_PRICE * ((double)(layerCount - 1)));
}

LayerCake::LayerCake(string cakeFlavor, string frostingType, int layerCount)
	: Cake(cakeFlavor, frostingType) {

	this->layerCount = layerCount;

	price = lcPRICE + (lcLAYER_PRICE * ((double) (layerCount - 1)));
	if (frostingType == "cream-cheese") {
		price +=(lcCREAM_CHEESE_PRICE * ((double) layerCount));
	}
}

LayerCake::~LayerCake() {
}

string LayerCake::ToString() {

	stringstream layerToString;
	layerToString << layerCount;

	return layerToString.str() + "-layer " + cakeFlavor + " cake with " + frostingType + " frosting (" + BakedGood::ToString() + ")";
}

string LayerCake::GetType() {
	return "LayerCake";
}

double LayerCake::GetPrice() {

	return price;
}