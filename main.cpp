#include <iostream>
#include <string>
#include <vector>
#include "exchange.h"

int main() {
	std::string url = "https://www.forex.com/en/";
	std::vector<std::string> currency = {"RUB", "USD", "EUR", "GBD", "JPY", "CNY"};
	Exchange *myExchange = new Exchange(url, currency);
	myExchange->runArbitrage();
}
