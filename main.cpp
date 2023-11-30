
#include <string>
#include <fstream>
#include <iostream>

#include "account.h"

int
main() {
	Account* account{ new Account() };

	std::fstream in{ "input.txt" };
	std::string  str{};

	while (std::getline(in, str)) {
		Transaction* transaction{ getTransaction(str) };
		account->updateHistory(transaction);
	}
	account->showFullInfo();
	return 0;
}