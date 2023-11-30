
#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <fstream>
#include <cassert>
#include <sstream>

unsigned int
getAccountID() {
	static unsigned int id{};
	return id++;
}

struct Transaction {
	unsigned int transactionID{};
	unsigned int senderID{};
	unsigned int recieverID{};
	unsigned int sum{};
	/*
	date, time - defined in <chrono> header
	*/
};

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
	void showAccountInfo();
};

Account::Account() :
	accountID{ getAccountID() }, balance{}
{};

void
Account::increaseBalance(int money) {
	assert((money > 0) && "NEGATIVE MONEY COUNT");
	balance += money;
}

void
Account::decreaseBalance(int money) {
	assert((money > 0) && "NEGATIVE MONEY COUNT");
	balance -= money;
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
Account::showAccountInfo() {
	std::cout << "BALANCE: " << this->balance   << '\n';
	std::cout << "ID:      " << this->accountID << '\n';
	showHistory();
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

int
main() {
	Account* account{ new Account() };

	std::fstream in{ "input.txt" };
	std::string  str{};

	while (in >> str) {
		Transaction* transaction{ getTransaction(str) };
	}
	return 0;
}