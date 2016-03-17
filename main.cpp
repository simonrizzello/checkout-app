#include <iostream>
#include <utility>
#include <map>
#include "Item.h"

using namespace std;

const string PRODUCT_LIST = "products_list.txt";

int main() {

	cout	<< "Hello, World!" << endl;

	cout << "Reading " << PRODUCT_LIST << endl;

	map<const int, pair<const string, const double>> products;
	pair<const string, const double> prod1("Chocolate Cake", 9.25);
	products.insert(pair<const int, pair<const string, const double>>
			(1, prod1));


	return 0;
}

