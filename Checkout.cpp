#include "Checkout.h"
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
const string Checkout::PRICES = "products_list.txt";

Checkout::Checkout() 
{
	ifstream infile(PRICES);

	regex price_line(
		"^([0-9]+)\\s+\\|\\s*(\\D+)\\|\\s*£([0-9]+\\.[0-9]+)");
	cout << "Constructor reading input file." << endl;

	string line;
	if (infile.is_open()) {
		while(getline(infile, line)) {
			smatch m;
			if (regex_match(line, m, price_line)) {
				for (auto result : m) {
					cout << "[" << result << "]" << endl;
				}
				pair<const string, 
				     const double> p(m[2], stod(m[3]));
				products.insert(pair<int, 
				     pair<string, double>>(stoi(m[1]),p));
			}
		}

	}

}
