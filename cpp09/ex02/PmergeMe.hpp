#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <stdexcept>
#include <ctime>
#include <chrono>




class PmergeMe {
public:
    PmergeMe();
    static bool isValidNumber(const std::string& s);
    static std::vector<size_t> jacobsthal_sequence(size_t n);

    static void mergeInsertSortVector(std::vector<size_t>& data);
    static void mergeInsertSortDeque(std::deque<size_t>& data);
};


void runVector(const std::vector<size_t>& input, const std::string& containerName);
void runDeque(const std::deque<size_t>& input, const std::string& containerName);

#endif // PMERGEME_HPP
