#include "Checkout.h"
#include <string>
#include <fstream>
#include <iostream>
#include <regex>

using namespace std;
const string Checkout::PRICES = "products_list.txt";

Checkout::Checkout(function<double(map<int, pair<string,double>>, vector<int>)> f) : sumup{f}
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
