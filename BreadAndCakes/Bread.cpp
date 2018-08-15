#include "stdafx.h"
#include "Bread.h"
#include <string>
using namespace std;

string breadVariety;

Bread::Bread() {
}

Bread::Bread(string breadVariety) {

	this->breadVariety = breadVariety;

	price = 4.50;
}

Bread::~Bread() {
}

string Bread::ToString() {

	return breadVariety + " bread (" + BakedGood::ToString() +")";
}