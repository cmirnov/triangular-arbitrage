#include "convert.h"

Converter::Converter(std::vector<std::string> currencyList) {
	for (size_t i = 0; i < currencyList.size(); ++i) {
		currencies.push_back(currencyList[i]);
	}
}

std::string Converter::intToName(int num) {
	if (num >= currencies.size()) {
		printf("out of range currency number\n");
		return NULL;
	} else {
		return currencies[num];
	}
}

int Converter::nameToInt(std::string name) {
	for (int i = 0; i < currencies.size(); ++i) {
		if (currencies[i] == name) {
			return i;
		}
	}
	printf("no such currency in the list\n");
	return -1;
}

void Converter::addNewCurrency(std::string newCurrency) {
	currencies.push_back(newCurrency);
}
