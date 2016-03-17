#include <iostream>
#include <fstream>
#include <utility>
#include <map>
#include <regex>
#include "Item.h"

using namespace std;

//const string PRODUCT_LIST = "products_list.txt";

int main() {

	cout	<< "Hello, World!" << endl;

	cout << "Reading " << "products_list.txt" << endl;

	map<const int, pair<const string, const double>> products;

	regex price_line("^([0-9]+)\\s+\\|\\s*(\\D+)\\|\\s*£([0-9]+\\.[0-9]+)");
	string line;
	ifstream infile("products_list.txt");
	if (infile.is_open()) {
		while (getline(infile,line)) {
			smatch m;
			// cout << line << endl; 
			if (regex_match(line, m, price_line)) {
			for (auto result : m) {
				cout << "[" << result << "]" << endl;
				pair<const string, const double> 
					p(m[2], stod(m[3]));
				products.insert(pair<int, pair<string, double>>(stoi(m[1]),p));
			}} else { cout << "no match" << endl; }

		}
		infile.close();
	}
	
	return 0;
}

