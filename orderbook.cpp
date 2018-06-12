#include "orderbook.h"
#include <iostream>

Orderbook::Orderbook(int buy, int sell, std::string url) {
	buyCurrency = buy;
	sellCurrency = sell;
	Url = url;
}


/*
 * Function: update()
 * 
 * Synopsis: It implements API transactions. Dummy now.
 */
void Orderbook::update() { 
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> disPrice(0.03, 30.0);
    std::uniform_real_distribution<> disAmount(100.0, 3000.0);
	for (int i = 0; i < 10; ++i) {
		long double amount = disAmount(gen);
		long double price = disPrice(gen);
		table.push_back(new Column(amount, price));	
	}
	sort(table.begin(), table.end(), [](Column *a, Column *b) {return a->price < b->price;});
}

Column* Orderbook::get(int idx) {
	if (idx >= table.size()) {
		printf("out of range of orderbook\n");
		return NULL;
	}
	return table[idx];
}
