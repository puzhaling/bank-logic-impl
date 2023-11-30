
#ifndef ACCOUNT
#define ACCOUNT

#include <vector>
#include <iostream>
#include <string_view>

#include "transaction.h"
#include "accountHelpers.h"

class Account {
private:
	int balance{};
	unsigned int accountID{};
	std::vector<Transaction*> transactions{};

public:
	Account();

	void increaseBalance(int money);
	void decreaseBalance(int money);
	void sendMoney(std::string_view senderID, int money);
	void updateHistory(Transaction* transaction);
	void showHistory();
	void showFullInfo();
};

#endif // ACCOUNT