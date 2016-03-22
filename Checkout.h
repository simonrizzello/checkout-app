#include <utility>
#include <regex>
#include <vector>

using product_list = std::map<int, std::pair<std::string, double>>;

class Checkout {
	public:
		// Constructor function with takes a lambda function that implments the
		// adding up of items in the checkout as a parameter.
		Checkout(std::function<double(product_list, std::vector<int>)> f);
		~Checkout() {}


		void scan(const double item);
		double total();
		void empty_basket();


		// File name for the product list (used on constructor.)
		const static std::string PRICES;

		product_list products;
		std::vector<int> basket;


	private:
		// Place holder for our lambda function to add up the shopping basket.
		std::function<double(product_list, std::vector<int>)> sumup;

};
