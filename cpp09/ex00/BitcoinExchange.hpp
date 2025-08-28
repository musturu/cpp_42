#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <iostream>
#include <iomanip>


class BitcoinExchange {
public:
    BitcoinExchange(const std::string& dbFile);
    float getRate(const std::string& date) const;
    bool isValidDate(const std::string& date) const;
    bool isValidValue(const std::string& value) const;
private:
    std::map<std::string, float> priceMap;
    void loadDatabase(const std::string& dbFile);
};

#endif // BITCOINEXCHANGE_HPP
