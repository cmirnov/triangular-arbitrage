#include <string>
#include <vector>

/*
 * Synopsis: Class that implements converter between name of currency and number that is assigned to it
 *
 * Purpose: To deal with names of currencies essier we convert all names to numbers
 */

class Converter {
private:
	std::vector<std::string> currencies;
public:
	Converter(std::vector<std::string> currencyList);
	std::string intToName(int num);
	int nameToInt(std::string name);
	void addNewCurrency(std::string newCurrency);
};

