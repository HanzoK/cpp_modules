#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
public:
	BitcoinExchange();
    BitcoinExchange(const std::string &databaseFile);
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void processInputFile(const std::string &inputFile) const;

private:
    std::map<std::string, double> _rates; // date -> exchange_rate

    void   loadDatabase(const std::string &filename);
    double getRateForDate(const std::string &date) const;

    static bool        isLeapYear(int year);
    static std::string trim(const std::string &s);
    static bool        parseValue(const std::string &input, double &value);
    static bool        isValidDateFormat(const std::string &date);
    static bool        isValidDate(const std::string &date);
};
