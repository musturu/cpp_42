#include "BitcoinExchange.hpp"
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>


BitcoinExchange::BitcoinExchange(const std::string& dbFile) {
    loadDatabase(dbFile);
}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");
    std::string line;
    bool firstLine = true;
    while (getline(file, line)) {
        if (firstLine) {
            std::string lower = line;
            for (size_t i = 0; i < lower.size(); ++i) lower[i] = tolower(lower[i]);
            if (lower.find("date") != std::string::npos && lower.find("exchange_rate") != std::string::npos)
            {
                firstLine = false;
                continue;
            }
            firstLine = false;
        }
        std::istringstream iss(line);
        std::string date, priceStr;
        if (getline(iss, date, ',') && getline(iss, priceStr)) {
            float price = std::atof(priceStr.c_str());
            priceMap[date] = price;
        }
    }
}

float BitcoinExchange::getRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = priceMap.find(date);
    if (it != priceMap.end())
        return it->second;
    // If not found, find closest previous date
    it = priceMap.lower_bound(date);
    if (it == priceMap.begin())
        throw std::runtime_error("Error: no price available for this date.");
    --it;
    return it->second;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Check format: YYYY-MM-DD
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);
    // Check all digits
    for (size_t i = 0; i < 4; ++i) if (!isdigit(yearStr[i])) return false;
    for (size_t i = 0; i < 2; ++i) if (!isdigit(monthStr[i])) return false;
    for (size_t i = 0; i < 2; ++i) if (!isdigit(dayStr[i])) return false;
    int year = std::atoi(yearStr.c_str());
    int month = std::atoi(monthStr.c_str());
    int day = std::atoi(dayStr.c_str());
    // Year range
    int currentYear = 2025;
    if (year < 1990 || year > currentYear) return false;
    // Month range
    if (month < 1 || month > 12) return false;
    // Day range
    if (day < 1 || day > 31) return false;
    // Days per month
    static const int daysInMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int maxDay = daysInMonth[month - 1];
    // Leap year for February
    if (month == 2) {
        bool leap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (leap) maxDay = 29;
    }
    if (day > maxDay) return false;
    return true;
}

bool BitcoinExchange::isValidValue(const std::string& value) const {
    if (value.empty() || value.size() > 9)
        return false;

    bool hasDigit = false, hasDot = false, hasSign = false;
    for (size_t i = 0; i < value.size(); ++i) {
        char c = value[i];
        if (isdigit(c)) {
            hasDigit = true;
        } else if (c == '.' || c == ',') {
            if (hasDot) return false;
            hasDot = true;
        } else if (( c == '+') && i == 0) {
            hasSign = true;
        } else {
            return false;
        }
    }
    if (!hasDigit) return false;
    return true;
}
