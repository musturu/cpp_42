
#include "BitcoinExchange.hpp"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

void printError(const std::string& msg, const std::string& detail = "") {
    std::cerr << msg;
    if (!detail.empty())
        std::cerr << " => " << detail;
    std::cerr << std::endl;
}

bool isHeader(const std::string& line) {
    return line == "date | value" || line == "date|value";
}

void processLine(const std::string& line, BitcoinExchange& btc) {

    if (line.empty() || line.find('|') == std::string::npos) {
        printError("Error: bad input", line);
        return;
    }

    std::istringstream iss(line);
    std::string date, value;

    getline(iss, date, '|');
    getline(iss, value);
    date = date.substr(0, date.find_last_not_of(" \t") + 1);
    value = value.substr(value.find_first_not_of(" \t"));

    if (!btc.isValidDate(date)) {
        printError("Error: bad input", date);
        return;
    }
    if (!btc.isValidValue(value)) {
        printError("Error: invalid value", value);
        return;
    }
    
    float v = std::atof(value.c_str());
    try {
        float rate = btc.getRate(date);
        std::cout << date << " => " << value << " = " << rate * v << std::endl;
    } catch (const std::exception& e) {
        printError(e.what());
    }
}

int run(const char* inputFile) {
    
    BitcoinExchange btc("data.csv");
    std::ifstream input(inputFile);
    if (!input.is_open()) {
        printError("Error: could not open file.");
        return 1;
    }

    std::string line;
    bool firstLine = true;
    while (getline(input, line)) {
        if (firstLine && isHeader(line)) {
            firstLine = false;
            continue;
        }
        firstLine = false;
        processLine(line, btc);
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printError("Error: could not open file.");
        return 1;
    }
    try {
        return run(argv[1]);
    } catch (const std::exception& e) {
        printError(e.what());
        return 1;
    }
}
