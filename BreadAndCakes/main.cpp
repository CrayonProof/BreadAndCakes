// BreadAndCakes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "BakedGood.h"
#include "Bread.h"
#include "CupCake.h"
#include "LayerCake.h"
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

string latestStringInput;
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

void GetLineNotWS(string& inpString) {

	getline(cin, inpString);
	if (inpString.find_first_not_of(" \t") == std::string::npos) {
		getline(cin, inpString);
	}
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

	cout << "Order Conformations: " << endl;

	for (int i = 0; i < orders.size(); i++) {
		cout << (*orders.at(i)).ToString() << endl;
	}

	while (true) {

	}

    return 0;
}

