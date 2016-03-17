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

	regex price_line("^([0-9]+)\\s+\\|\\s*(\\D+)\\|\\s*£([0-9]+\\.[0-9]+)");
	//regex price_line(R"^(\d+)\s+|\s*(\D+)|\s*£(\d+\.\d+)");
	string line;
	ifstream infile("products_list.txt");
	if (infile.is_open()) {
		while (getline(infile,line)) {
			smatch m;
			// cout << line << endl; 
			regex_match(line, m, price_line);
			for (auto result : m) {
				cout << "[" << result << "]" << endl;
			}
		}
		infile.close();
	}

	

	map<const int, pair<const string, const double>> products;
	pair<const string, const double> prod1("Chocolate Cake", 9.25);
	products.insert(pair<const int, pair<const string, const double>>
			(1, prod1));


	return 0;
}

