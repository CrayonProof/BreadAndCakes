//#include "stdafx.h"
#include "CupCake.h"

double ccPRICE = 1.95;
double ccCREAM_CHEESE_PRICE = 0.20;

CupCake::CupCake() : Cake() {

	sprinkleColor = "none";

	price = ccPRICE;
}

CupCake::CupCake(string cakeFlavor, string frostingType, string sprinkleColor)
	: Cake(cakeFlavor, frostingType) {

	this->sprinkleColor = sprinkleColor;

	price = ccPRICE;
	if (frostingType == "cream-cheese") {
		price += ccCREAM_CHEESE_PRICE;
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