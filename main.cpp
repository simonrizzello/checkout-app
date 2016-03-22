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

	// Create promotions list and add offer for chocolate cake.
	using offer_t = pair<int,double>;
	using product_code_t = int;
	using promotions_list_t = map<product_code_t, offer_t>;
	promotions_list_t promotions_list;
	offer_t offer(2, 8.50);
	promotions_list.insert(pair<product_code_t, offer_t>(1, offer));

	const double discount_threshold = 60.0;

	// The function to add up the basket is implemented here as a lambda function.
	// In this way it is easy to configure the application to change the promotional rules.
	function<double(map<int, pair<string, double>>, vector<int>)> promotional_rules =
		[&promotions_list, discount_threshold]
		(map<int, pair<string, double>> prods, vector<int> bskt) {
			promotions_list_t::iterator it;
			double result = 0;
			for (auto item : bskt) {
				// Check item against promotions list.
				it = promotions_list.find(item);
				if (it != promotions_list.end() &&
				    count(bskt.begin(), bskt.end(), item) >= it->second.first)
					result += it->second.second;
				 else 
					result += prods.find(item)->second.second;
			}

			if (result >= discount_threshold)
				result = result * 0.9;

			return result;
		};

	Checkout* co = new Checkout(promotional_rules);
	co->scan(1);
	co->scan(2);
	co->scan(3);
	co->scan(42);

	double price = co->total();

	cout << "Basket total " << price << endl;
	co->empty_basket();

	co->scan(1);
	co->scan(3);
	co->scan(1);

	price = co->total();

	cout << "Basket total " << price << endl;
	co->empty_basket();

	co->scan(1);
	co->scan(2);
	co->scan(1);
	co->scan(3);

	price = co->total();

	cout << "Basket total " << price << endl;

	return 0;
}

