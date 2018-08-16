//#include "stdafx.h"
#include "Cake.h"


Cake::Cake() {

	cakeFlavor = "none";
	frostingType = "none";
}

Cake::Cake(string cakeFlavor, string frostingType) {

	this->cakeFlavor = cakeFlavor;
	this->frostingType = frostingType;
}

Cake::~Cake() {
}
