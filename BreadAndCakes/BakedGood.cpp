#include "stdafx.h"
#include "BakedGood.h"
#include <iomanip>
#include <sstream>
using namespace std;

double price;

BakedGood::BakedGood() {
}

BakedGood::~BakedGood() {
}

string BakedGood::ToString() {

	stringstream toString;
	toString << fixed << setprecision(2) << price;

	return "$" + toString.str();
}

bool BakedGood::Equals(BakedGood otherObject) {

	if ((this->ToString()) == (otherObject.ToString())) {
		return true;
	}

	return false;
}

string BakedGood::GetType() {

	return "none";
}
double BakedGood::GetPrice() {

	return (double) INT_MIN;
}