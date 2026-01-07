#include "BitcoinExchange.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <cstdlib>
#include <cctype>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &databaseFile)
{
    loadDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) : _rates(copy._rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy)
{
    if (this != &copy)
        _rates = copy._rates;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// ========== Helpers ==========

bool BitcoinExchange::isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

std::string BitcoinExchange::trim(const std::string &s)
{
    std::string::size_type start = 0;
    std::string::size_type end   = s.size();

    while (start < s.size() &&
           std::isspace(static_cast<unsigned char>(s[start])))
        ++start;
    while (end > start &&
           std::isspace(static_cast<unsigned char>(s[end - 1])))
        --end;
    return s.substr(start, end - start);
}

bool BitcoinExchange::parseValue(const std::string &input, double &value)
{
    int  nbr_digits = 0;
    bool started    = false;

    for (std::size_t i = 0; i < input.size(); ++i)
    {
        char c = input[i];

        if (std::isdigit(static_cast<unsigned char>(c)))
        {
            if (c != '0' || started)
            {
                started = true;
                ++nbr_digits;
            }
        }
        else if (c == '.')
            continue;
        else
            return false;
    }

    // simple protection against absurdly large values
    if (nbr_digits > 16)
        return false;
    std::stringstream ss(input);
    char              stray;
    ss >> value;
    if (ss.fail())
        return false;
    if (ss >> stray) // extra non-space garbage
        return false;

    return true;
}

bool BitcoinExchange::isValidDateFormat(const std::string &date)
{
    if (date.size() != 10)
        return false;

    for (int i = 0; i < 10; ++i)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return false;
        }
        else
        {
            if (!std::isdigit(static_cast<unsigned char>(date[i])))
                return false;
        }
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string &date)
{
    if (!isValidDateFormat(date))
        return false;

    int year  = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day   = std::atoi(date.substr(8, 2).c_str());

    if (year < 0 || month < 1 || month > 12 || day < 1)
        return false;

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (isLeapYear(year))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}

// ========== CSV database loading ==========

void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file");

    std::string line;
    bool        firstLine = true;

    if (!std::getline(file, line))
        throw std::runtime_error("Error: database file is empty");

    std::string header = trim(line);
    if (header != "date,exchange_rate")
        throw std::runtime_error("Error: invalid database header");

    while (std::getline(file, line))
    {
        if (firstLine)
        {
            firstLine = false;
            continue;
        }
        if (line.empty())
            continue;

        std::string::size_type commaPos = line.find(',');
        if (commaPos == std::string::npos)
            continue;

        std::string date    = trim(line.substr(0, commaPos));
        std::string rateStr = trim(line.substr(commaPos + 1));

        if (!isValidDate(date))
            continue;

        double rate = 0.0;
        if (!parseValue(rateStr, rate))
            continue;

        _rates[date] = rate;
    }

    if (_rates.empty())
        throw std::runtime_error("Error: database is empty or invalid");
}

// ========== Finding closest lower-or-equal date ==========

double BitcoinExchange::getRateForDate(const std::string &date) const
{
    std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);

    if (it != _rates.end() && it->first == date)
        return it->second;

    if (it == _rates.begin())
        throw std::runtime_error("Error: no price available for this date");

    --it; // closest lower date
    return it->second;
}

// ========== Processing input file ==========

void BitcoinExchange::processInputFile(const std::string &inputFile) const
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file");

    std::string line;
    bool        firstLine = true;

    while (std::getline(file, line))
    {
        if (line.empty())
        {
            std::cerr << "Error: line empty " << line << std::endl;
            continue;
        }

        if (firstLine)
        {
            firstLine = false;
            std::string header = trim(line);
            if (header != "date | value")
            {
                std::cerr << "Error: invalid header => " << line << std::endl;
                return;
            }
            continue;
        }

        std::size_t pipePos = line.find('|');
        if (pipePos == std::string::npos)
        {
            std::cerr << "Error: invalid format => " << line << std::endl;
            continue;
        }

        if (pipePos == 0 || pipePos >= line.size() - 1 || line[pipePos - 1] != ' ' || line[pipePos + 1] != ' ')
        {
            std::cerr << "Error: bad input format (missing spaces around '|') => " << line << std::endl;
            continue;
        }

        std::string date     = trim(line.substr(0, pipePos));
        std::string valueStr = trim(line.substr(pipePos + 1));

        // ---- Date checks ----
        if (!isValidDateFormat(date))
        {
            std::cerr << "Error: invalid date format => " << date << std::endl;
            continue;
        }

        int  year  = std::atoi(date.substr(0, 4).c_str());
        int  month = std::atoi(date.substr(5, 2).c_str());
        int  day   = std::atoi(date.substr(8, 2).c_str());
        bool leap  = isLeapYear(year);

        if (!isValidDate(date))
        {
            if (month == 2 && day == 29 && !leap)
                std::cerr << "not a Leap year so...., Error: invalid date format => "
                          << date << std::endl;
            else
                std::cerr << "Error: invalid date format => " << date << std::endl;
            continue;
        }

        // ---- Value checks ----
        double value = 0.0;
        if (!parseValue(valueStr, value))
        {
            std::cerr << "Error: invalid value format => " << valueStr << std::endl;
            continue;
        }

        if (value < 0.0)
        {
            std::cerr << "Error: negative value => " << valueStr << std::endl;
            continue;
        }

        if (value > 1000.0)
        {
            std::cerr << "Error: number too large => " << valueStr << std::endl;
            continue;
        }

        try
        {
            double rate   = getRateForDate(date);
            double result = value * rate;

            std::cout.setf(std::ios::fixed);
            std::cout.precision(2);
            std::cout << date << " => " << valueStr << " = " << result << std::endl;
        }
        catch (...)
        {
            std::cerr << "Error: no data for date => " << date << std::endl;
        }
    }
}
