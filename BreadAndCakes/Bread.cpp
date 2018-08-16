//#include "stdafx.h"
#include "Bread.h"
using namespace std;

string breadVariety;
double BREAD_PRICE = 4.50;

Bread::Bread() {

	breadVariety = "none";

	price = BREAD_PRICE;
}

Bread::Bread(string breadVariety) {

	this->breadVariety = breadVariety;

	price = BREAD_PRICE;
}

Bread::~Bread() {
}

string Bread::ToString() {

	return breadVariety + " bread (" + BakedGood::ToString() +")";
}

string Bread::GetType() {
	return "Bread";
}

double Bread::GetPrice() {

	return price;
}