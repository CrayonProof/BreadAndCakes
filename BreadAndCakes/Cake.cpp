#include "stdafx.h"
#include "Cake.h"


Cake::Cake() {
}

Cake::Cake(string cakeFlavor, string frostingType) {

	this->cakeFlavor = cakeFlavor;
	this->frostingType = frostingType;
}

Cake::~Cake() {
}
