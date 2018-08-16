//#include "stdafx.h"
#include "LayerCake.h"
#include <sstream>

double LCPRICE = 9.00;
double LCLAYER_PRICE = 3.00;
double LCCREAM_CHEESE_PRICE = 1.00;

LayerCake::LayerCake() : Cake() {

	layerCount = 1;
	price = LCPRICE + (LCLAYER_PRICE * ((double)(layerCount - 1)));
}

LayerCake::LayerCake(string cakeFlavor, string frostingType, int layerCount)
	: Cake(cakeFlavor, frostingType) {

	this->layerCount = layerCount;

	price = LCPRICE + (LCLAYER_PRICE * ((double) (layerCount - 1)));
	if (frostingType == "cream-cheese") {
		price +=(LCCREAM_CHEESE_PRICE * ((double) layerCount));
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

//Declared in LayerCake to keep LayerCake from being abstract
void LayerCake::CakeIsAbstract() {}