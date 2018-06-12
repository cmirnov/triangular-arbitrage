#include <vector>
#include <random>
#include <string>
#include <algorithm>

/*
 * Synopsis: Structure that implements column of orderbook. It looks more understandable than pair <long double, long doble> 
 */

struct Column {
	long double amount;
	long double price;
	Column(long double a, long double p) {
		amount = a;
		price = p;
	}
};

/*
 * Synosis: Class that implements orderbook logic
 *
 * Purpose: This class stores all informations about orderbook.
 * 
 * Function: update() - get orderbook by API
 * 
 * Function: get() - return column by index
 */
class Orderbook {
private:
	std::vector<Column*> table;
	int buyCurrency;
	int sellCurrency;
	std::string Url; //unused now, but necessary for internet connection
public:
	Orderbook(int buy, int sell, std::string url);
	void update();
	Column *get(int idx);
};
