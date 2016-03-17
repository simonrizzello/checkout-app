#include <utility>
#include <regex>

class Checkout {
	public:
		Checkout();
		~Checkout() {}


		const static std::string PRICES;


	private:
		std::map<int, std::pair<std::string, double>> products;

	

};
