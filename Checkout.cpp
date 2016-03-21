#include "Checkout.h"
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
const string Checkout::PRICES = "products_list.txt";

Checkout::Checkout(std::function<void()> f) : sumup{f}
{
	// Basket should intiially be empty.
	basket_it = basket.end();

	ifstream infile(PRICES);

	regex price_line(
		"^([0-9]+)\\s+\\|\\s*(\\D+)\\|\\s*£([0-9]+\\.[0-9]+)");
	cout << "Constructor reading input file." << endl;

	string line;
	if (infile.is_open()) {
		while(getline(infile, line)) {
			smatch m;
			if (regex_match(line, m, price_line)) {
				pair<const string, 
				     const double> p(m[2], stod(m[3]));
				products.insert(pair<int, 
				     pair<string, double>>(stoi(m[1]),p));
			}
		}

	}

}

void Checkout::scan(const double item)
{
	map<int, std::pair<std::string, double>>::iterator it;
	it = products.find(item);
	if (it != products.end()) {
		basket.push_back(item);
		cout << "Added: " 
		     << it->second.first << " : £" 
		     << it->second.second << endl;
		// Every time we add  new item, reset the basket
		// iterator -- keeps the code for adding up the
		// basket simpler
		basket_it = basket.begin();
	}
	else
		cout << "unknown item code : " << item << endl;;


}
const vector<int>::iterator& Checkout::getBasketIterator()
{
	return basket_it;
}
	
double Checkout::total()
{
	double result = 0;

	for (auto item : basket) {
		result += products.find(item)->second.second;
		
	}

	// Test calling of lambda function here:
	sumup();

	return result;
}

void Checkout::lambdaTest()
{
	cout << "Lambda test function has been called." << endl;
}
