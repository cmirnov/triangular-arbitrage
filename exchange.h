#include <vector>
#include <string>
#include <iostream>
#include "convert.h"
#include "orderbook.h"

/*
 * Synopsis: Class Exchange implements exchange logic
 *
 * Funciton: updateOrderbook - will be used to refresh orderbook data (unused now)
 *
 * Function: updateFees - will be used to refresh fees data (unused now)
 *
 * Function: arbitrage - implements triangle arbitrage logic
 *
 * Function: runArbitrage - wraper over arbitrage function
 */

class Exchange {
private:
	Converter *converter;
	std::vector<long double> sellFee;
	std::vector<long double> buyFee;
	std::vector<std::vector<Orderbook*>> matrix;
public:
	Exchange(std::string url, std::vector<std::string> currency);
	void updateOrderbook(std::string currency);
	void updateFees();
	void arbitrage(int begin, int prev, long double tempPrice, int level, std::vector<int> stack, long double fees);
	void runArbitrage();
};

