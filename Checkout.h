#include <utility>
#include <regex>
#include <vector>

class Checkout {
	public:
		Checkout();
		~Checkout() {}


		void scan(const double item);
		double total();


		const static std::string PRICES;


	private:
		std::map<int, std::pair<std::string, double>> products;
		std::vector<int> basket;

	

};
