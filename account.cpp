
#include <cassert>
#include "account.h"

Account::Account() :
	accountID{ getAccountID() }, balance{}
{};

void
Account::increaseBalance(int money) {
	assert((money > 0) && "NEGATIVE MONEY COUNT");
	this->balance += money;
}

void
Account::decreaseBalance(int money) {
	assert((money > 0) && "NEGATIVE MONEY COUNT");
	this->balance -= money;
}

void
Account::sendMoney(std::string_view senderID, int money) {
	assert((this->balance > 0) && "NOT ENOUGH MONEY ON BALANCE");
	if (this->balance < money) 
		return;
	/*
	find user in telephony book with destinationID
	*/
}

std::ostream& 
operator<<(std::ostream& out, const Transaction* const transaction) {
	return out << '[' << transaction->transactionID << ' ' 
		<< transaction->senderID << ' ' << transaction->recieverID << ' ' << transaction->sum << "]\n";
}

void
Account::showHistory() {
	for (const Transaction* const transaction : transactions) {
		std::cout << transaction;
	}
	std::cout << std::endl;
}

void
Account::updateHistory(Transaction* transaction) {
	transactions.push_back(transaction);
}

void
Account::showFullInfo() {
	std::cout << "BALANCE: " << this->balance   << '\n';
	std::cout << "ID:      " << this->accountID << '\n';
	showHistory();
}