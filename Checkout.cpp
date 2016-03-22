#include "Checkout.h"
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
const string Checkout::PRICES = "products_list.txt";

// Constructor.  Reads in the price list and also saves the basket summing up function
// passed in as a lamda expression.
Checkout::Checkout(function<double(product_list, vector<int>)> f) : sumup{f}
{
	// Open the price list file and read it into the products list.
	ifstream infile(PRICES);

	// This regular expression should exract the prices from the input file.
	regex price_line(
		"^([0-9]+)\\s+\\|\\s*(\\D+)\\|\\s*£([0-9]+\\.[0-9]+)");
	cout << "Constructor reading input file." << endl;

	// Step through the file and read price information in to the product list
	// data structure.
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
	product_list::iterator it;
	it = products.find(item);
	if (it != products.end()) {
		basket.push_back(item);
		cout << "Added: " 
		     << it->second.first << " : £" 
		     << it->second.second << endl;
	}
	else
		cout << "unknown item code : " << item << endl;;


}
	
double Checkout::total()
{
	double result = 0;

	result = sumup(products, basket);
	
	return result;
}

void Checkout::lambdaTest()
{
	cout << "Lambda test function has been called." << endl;
}
