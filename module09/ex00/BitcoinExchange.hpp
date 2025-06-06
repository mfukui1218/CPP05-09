#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>

class BitcoinExchange {
public:
	BitcoinExchange();
	~BitcoinExchange();
	void readData(const std::string& filename);
	void processInput(const std::string& inputFilename);
	void printExchangeRate(const std::string& date) const;
private:
	std::map<std::string, float> exchangeRates;
	void parseLine(const std::string& line);
	bool isValidDate(const std::string& date) const;
	bool isValidValue(const std::string& value) const;
	void printError(const std::string& message) const;
};

#endif // BITCOINEXCHANGE_HPP
