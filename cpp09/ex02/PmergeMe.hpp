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

    template <typename Iterator>
    static void mergeInsertSort(Iterator begin, Iterator end) {
        size_t n = std::distance(begin, end);
        if (n <= 1) return;
        if (n == 2) {
            if (*(begin + 1) < *begin)
                std::iter_swap(begin, begin + 1);
            return;
        }
        std::vector<typename std::iterator_traits<Iterator>::value_type> main_chain;
        std::vector<typename std::iterator_traits<Iterator>::value_type> pend_chain;
        Iterator it = begin;
        while (it + 1 < end) {
            if (*(it) < *(it + 1)) {
                main_chain.push_back(*(it + 1));
                pend_chain.push_back(*(it));
            } else {
                main_chain.push_back(*(it));
                pend_chain.push_back(*(it + 1));
            }
            it += 2;
        }
        if (it < end)
            pend_chain.push_back(*it);
        PmergeMe::mergeInsertSort(main_chain.begin(), main_chain.end());
        std::vector<size_t> jac_seq = PmergeMe::jacobsthal_sequence(pend_chain.size());
        std::vector<bool> inserted(pend_chain.size(), false);
        for (size_t idx = 0; idx < pend_chain.size(); ++idx) {
            size_t j = (idx < jac_seq.size()) ? jac_seq[idx] - 1 : idx;
            if (j >= pend_chain.size() || inserted[j]) {
                j = 0;
                while (j < pend_chain.size() && inserted[j]) ++j;
                if (j >= pend_chain.size()) break;
            }
            auto pos = std::lower_bound(main_chain.begin(), main_chain.end(), pend_chain[j]);
            main_chain.insert(pos, pend_chain[j]);
            inserted[j] = true;
        }
        std::copy(main_chain.begin(), main_chain.end(), begin);
    }
};


template <typename Container>
void run(const Container& input, const std::string& containerName) {
    Container data = input;
    std::cout << "Before: ";
    for (size_t i = 0; i < data.size(); ++i) std::cout << data[i] << " ";
    std::cout << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    PmergeMe::mergeInsertSort(data.begin(), data.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "After: ";
    for (size_t i = 0; i < data.size(); ++i) std::cout << data[i] << " ";
    std::cout << std::endl;
    double elapsed = std::chrono::duration<double, std::micro>(end - start).count();
    std::cout << "Time to process a range of " << data.size()
              << " elements with " << containerName << " : "
              << elapsed << " us" << std::endl;
}

#endif // PMERGEME_HPP
