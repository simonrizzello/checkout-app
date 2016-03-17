#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <regex>
#include "Checkout.h"

using namespace std;

int main() {

	cout	<< "Hello, World!" << endl;

	cout << "Reading " << "products_list.txt" << endl;

	Checkout* co = new Checkout();
	co->scan(1);
	co->scan(2);
	co->scan(3);
	co->scan(42);

	double price = co->total();

	cout << "Basket total " << price << endl;
	return 0;
}

