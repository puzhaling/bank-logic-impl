
#include <string>
#include <sstream>
#include "transaction.h"

unsigned int
getAccountID() {
	static unsigned int id{};
	return id++;
}

Transaction*
getTransaction(const std::string& string) {
	Transaction* transaction{ new Transaction() };
    /* \--> transactionID senderID recieverID sum*/

	std::stringstream sstream(string);

	unsigned short index{ 0 };
	std::string single_word{};
	while (sstream >> single_word) {
		switch (index++) {
		case 0:
			transaction->transactionID = stoi(single_word);
			break;
		case 1:
			transaction->senderID = stoi(single_word);
			break;
		case 2:
			transaction->recieverID = stoi(single_word);
			break;
		case 3:
			transaction->sum = stoi(single_word);
			break;
		}
	}
	return transaction;
}