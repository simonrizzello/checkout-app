#include <utility>
#include <regex>
#include <vector>

class Checkout {
	public:
		Checkout(std::function<void()> f);
		~Checkout() {}


		void scan(const double item);
		double total();


		// File name for the product list (used on constructor.)
		const static std::string PRICES;
		// Check the prive for the item in the product list.
		double findItemPrice(int item);
		// Get an iterator to the next item in the basket.
		const std::vector<int>::iterator& getBasketIterator();

		// Method to test lambda functionality.
		void lambdaTest();

	private:
		std::map<int, std::pair<std::string, double>> products;
		std::vector<int> basket;

		// Maintain this iterator to allow us to add up items
		// easily.
		std::vector<int>::iterator basket_it;

		std::function<void()> sumup;

};
