#include "exchange.h"

Exchange::Exchange(std::string url, std::vector<std::string> currency) {
	converter = new Converter(currency);

	matrix.resize(currency.size());
	for (int i = 0; i < currency.size(); ++i) {
		for (int j = 0; j < currency.size(); ++j) {
			if (i != j) {
				matrix[i].push_back(new Orderbook(converter->nameToInt(currency[i]), converter->nameToInt(currency[j]), url));
				matrix[i].back()->update();
			} else {
				matrix[i].push_back(NULL);
			}
		}
	}

	sellFee.resize(currency.size());
	buyFee.resize(currency.size());
	for (int i = 0; i < currency.size(); ++i) {
		sellFee[i] = 1.5;
		buyFee[i] = 2.5;
	}
}

void Exchange::updateOrderbook(std::string currency) {
	return;
}

void Exchange::updateFees() { 
	return;
}

std::vector<bool> used;

/*
 * Function: arbitrage
 *
 * Purpose: Let's think about currencies ecxhange like a edges in directed graph. 
 * Each currency is a node in a graph. Our goal is find a loop that has positiv income.
 * As far as classic algorithm is looking for loop with lenght equal 3 it may be impelemnted by loops.
 * But my approach is more general. You can choose lenght of loop like a parametr (level).
 */

void Exchange::arbitrage(int begin, int prev, long double tempPrice, int level, std::vector<int> stack, long double fees) {
	if (level == 0) {
		tempPrice *= (matrix[prev][begin]->get(0))->price;
		if (tempPrice - fees > 1) {
			std::cout << "there is a new arbitrage: ";
			for (int i = 0; i < stack.size(); ++i) {
				std::cout << converter->intToName(stack[i]) << " ";
			}
			std::cout << std::endl << "with a profit = " << tempPrice - fees - 1 << std::endl;
		}
		return;
	}
	if (prev == -1) {
		for (int i = 0; i < matrix.size(); ++i) {
			used[i] = true;
			arbitrage(i, i, 1, level - 1, {i}, buyFee[i]);
			used[i] = false;
		}
	} else {
		for (int i = 0; i < matrix.size(); ++i) {
			if (i != prev && matrix[prev][i] != NULL && !used[i]) {
				used[i] = true;
				stack.push_back(i);
				arbitrage(begin, i, tempPrice * (matrix[prev][i]->get(0))->price, level - 1, stack, fees + sellFee[prev] + buyFee[i]);
				stack.pop_back();
				used[i] = false;
			}
		}
	}
}

void Exchange::runArbitrage() {
	used.resize(matrix.size(), false);
	arbitrage(-1, -1, 1, 3, {}, 0);
}
