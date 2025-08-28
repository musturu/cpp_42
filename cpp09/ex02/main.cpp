#include "PmergeMe.hpp"
#include <vector>
#include <deque>
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    std::vector<int> v;
    std::deque<int> d;
    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);
        if (!PmergeMe::isValidNumber(arg)) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        int num = std::stoi(arg);
        if (num <= 0) {
            std::cerr << "Error" << std::endl;
            return 1;
        }
        v.push_back(num);
        d.push_back(num);
    }
    run(v, "std::vector");
    run(d, "std::deque");
    return 0;
}
