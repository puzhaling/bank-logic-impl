
#ifndef TRANSACTION
#define TRANSACTION 

struct Transaction {
	unsigned int transactionID{};
	unsigned int senderID{};
	unsigned int recieverID{};
	unsigned int sum{};
	/*
	date, time - defined in <chrono> header
	*/
};

#endif // TRANSACTION