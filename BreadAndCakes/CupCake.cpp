//#include "stdafx.h"
#include "CupCake.h"

double CCPRICE = 1.95;
double CCREAM_CHEESE_PRICE = 0.20;

CupCake::CupCake() : Cake() {

	sprinkleColor = "none";

	price = CCPRICE;
}

CupCake::CupCake(string cakeFlavor, string frostingType, string sprinkleColor)
	: Cake(cakeFlavor, frostingType) {

	this->sprinkleColor = sprinkleColor;

	price = CCPRICE;
	if (frostingType == "cream-cheese") {
		price += CCCREAM_CHEESE_PRICE;
	}
}

CupCake::~CupCake() {
}

string CupCake::ToString() {

	return cakeFlavor + " cupcake with " + frostingType + " frosting and " + sprinkleColor + " sprinkles (" + BakedGood::ToString() + ")";
}

string CupCake::GetType() {
	return "CupCake";
}

double CupCake::GetPrice() {

	return price;
}

//Declared in CupCake to keep CupCake from being abstract
void CupCake::CakeIsAbstract() {}