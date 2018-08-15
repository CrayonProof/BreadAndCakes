#include "stdafx.h"
#include "CupCake.h"

double PRICE = 1.95;
double CREAM_CHEESE_PRICE = 0.20;

CupCake::CupCake() {
}

CupCake::CupCake(string cakeFlavor, string frostingType, string sprinkleColor)
	: Cake(cakeFlavor, frostingType) {

	this->sprinkleColor = sprinkleColor;

	price = PRICE;
	if (frostingType == "cream-cheese") {
		price += CREAM_CHEESE_PRICE;
	}
}

CupCake::~CupCake() {
}

string CupCake::ToString() {

	return cakeFlavor + " cupcake with " + frostingType + " frosting and " + sprinkleColor + " sprinkles (" + BakedGood::ToString() + ")";
}