// BreadAndCakes.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "BakedGood.h"
#include "Bread.h"
#include "CupCake.h"
#include "LayerCake.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


string orderType;
string orderBreadVariety;
string orderCakeFlavor;
string orderFrostingType;
string orderSprinkleColor;
string orderStringQuantity;
int orderIntQuantity;
string orderStringLayerCount;
int orderIntLayerCount;
vector<BakedGood*> orders;

string latestStringInput;
int totalQuantity = 0;
double totalCost = 0;

int BREAD_DISCOUNT_FREQ = 3;
int CCAKE_DISCOUNT_LOWER_POINT = 2;
int CCAKE_DISCOUNT_UPPER_POINT = 4;
int LCAKE_DISCOUNT_POINT = 3;
double CCAKE_DISCOUNT_LOWER_VAL = 0.30;
double CCAKE_DISCOUNT_UPPER_VAL = 0.40;
double LCAKE_DISCOUNT_VAL = 2.00;

double FindTotalCost(BakedGood* item, int quantity) {

	double totalItemPrice;
	double itemPrice = (*item).GetPrice();

	if ((*item).GetType() == "Bread") {
		totalItemPrice = ((double)(quantity - ((quantity - (quantity % BREAD_DISCOUNT_FREQ)) / BREAD_DISCOUNT_FREQ))) * itemPrice;
	}
	else if ((*item).GetType() == "CupCake") {

		if (quantity >= CCAKE_DISCOUNT_UPPER_POINT) {

			totalItemPrice = (((double) quantity) * itemPrice) - (((double) quantity) * CCAKE_DISCOUNT_UPPER_VAL);
		}
		else if (quantity >= CCAKE_DISCOUNT_LOWER_POINT) {

			totalItemPrice = (((double) quantity) * itemPrice) - (((double) quantity) * CCAKE_DISCOUNT_LOWER_VAL);
		}
		else {

			totalItemPrice = itemPrice * ((double) quantity);
		}
	}
	else if ((*item).GetType() == "LayerCake") {
		if (quantity >= LCAKE_DISCOUNT_POINT) {
			totalItemPrice = (((double) quantity) * itemPrice) - (((double) quantity) * LCAKE_DISCOUNT_VAL);
		}
		else {
			totalItemPrice = itemPrice * ((double) quantity);
		}
	}

	totalQuantity += quantity;
	totalCost += totalItemPrice;

	return totalItemPrice;
}

void GetLineNotWS(string& inpString) {

	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos) {
		getline(cin, inpString);
	}
}

bool AreTheSameGood(BakedGood* goodOne, BakedGood* goodTwo) {

	return (*goodOne).ToString() == (*goodTwo).ToString();
}

int main()
{
	cout << "**Bread and Cakes Bakery**" << endl << endl;
	cout << "Enter sub-order (enter \"done\" to finish)" << endl;

	while (latestStringInput != "done") {

		cout << "Sub-order: ";
		GetLineNotWS(latestStringInput);

		istringstream iss(latestStringInput);
		getline(iss, orderType, ' ');

		if (orderType == "Bread") {

			getline(iss, orderBreadVariety, ' ');
			getline(iss, orderStringQuantity, ' ');

			stringstream QuantityToInt(orderStringQuantity);
			QuantityToInt >> orderIntQuantity;

			for (int i = 0; i < orderIntQuantity; i++) {

				orders.resize(orders.size() + 1);
				orders.at(orders.size() - 1) = new Bread(orderBreadVariety);
			}
		}
		else if (orderType == "Cupcake") {

			getline(iss, orderCakeFlavor, ' ');
			getline(iss, orderFrostingType, ' ');
			getline(iss, orderSprinkleColor, ' ');
			getline(iss, orderStringQuantity, ' ');

			stringstream QuantityToInt(orderStringQuantity);
			QuantityToInt >> orderIntQuantity;

			for (int i = 0; i < orderIntQuantity; i++) {

				orders.resize(orders.size() + 1);
				orders.at(orders.size() - 1) = new CupCake(orderCakeFlavor, orderFrostingType, orderSprinkleColor);
			}
		}
		else if (orderType == "Layer-cake") {

			getline(iss, orderCakeFlavor, ' ');
			getline(iss, orderFrostingType, ' ');
			getline(iss, orderStringLayerCount, ' ');
			getline(iss, orderStringQuantity, ' ');

			stringstream countToInt(orderStringLayerCount);
			countToInt >> orderIntLayerCount;

			stringstream QuantityToInt(orderStringQuantity);
			QuantityToInt >> orderIntQuantity;

			for (int i = 0; i < orderIntQuantity; i++) {

				orders.resize(orders.size() + 1);
				orders.at(orders.size() - 1) = new LayerCake(orderCakeFlavor, orderFrostingType, orderIntLayerCount);
			}
		}

		cout << endl;
	}

	cout << "Order Confirmations: " << endl;

	for (BakedGood* good : orders) {

		cout << ((*good).ToString()) << endl;
	}

	cout << endl;

	vector<BakedGood*> orders_temporary = orders;

	int indexOfOrderToLookAt = 0;

	cout << "Invoice:" << endl;
	cout << "Baked Good                         Quantity    Total" << endl;

	while (((int) orders_temporary.size()) - 1 > indexOfOrderToLookAt) {

		int ordersCount = 0;

		for (int i = ((int) indexOfOrderToLookAt + 1); i < (int) orders_temporary.size(); i++) {

			//if the ToString returns of the two BakedGoods are the same...
			if (((*(orders_temporary.at(indexOfOrderToLookAt))).ToString()) == ((*(orders_temporary.at(i))).ToString())) {

				orders_temporary.erase(orders_temporary.begin() + (i));
				i--;
				ordersCount++;
			}
		}

		ordersCount++;

		cout << (*(orders_temporary.at(indexOfOrderToLookAt))).ToString() << "      ";
		cout  << ordersCount;
		cout << std::fixed << setprecision(2) << "   " << FindTotalCost((orders_temporary.at(indexOfOrderToLookAt)), ordersCount) << endl;

		indexOfOrderToLookAt++;
	}
	cout << "Totals            " << totalQuantity << "  " << totalCost << endl;

	cout << "Good Bye";

    return 0;
}

