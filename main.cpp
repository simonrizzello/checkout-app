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

	//map<int, pair<int,double>> items_on_promotion;
	//items_on_promotion.insert(1, pair<int, double> p(2, 9.25));

	// The function to add up the basket is implemented here as a lambda function.
	// In this way it is easy to configure the API to change the promotional rules.
	function<double(map<int, pair<string, double>>, vector<int>)> promotional_rules =
		[](map<int, pair<string, double>> prods, vector<int> bskt) {
			double result = 0;
			for (auto item : bskt) {
				result += prods.find(item)->second.second;
			}
			return result;
		};

	Checkout* co = new Checkout(promotional_rules);
	co->scan(1);
	co->scan(2);
	co->scan(3);
	co->scan(42);

	double price = co->total();

	cout << "Basket total " << price << endl;

	return 0;
}

