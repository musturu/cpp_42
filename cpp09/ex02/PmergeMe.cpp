#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

bool PmergeMe::isValidNumber(const std::string& s) {
    if (s.empty()) return false;
    for (size_t i = 0; i < s.size(); ++i) {
        if (!isdigit(s[i])) return false;
    }
    return true;
}


/**
 * Jacobsthal number generator
 *
 * Math background:
 * Jacobsthal numbers are defined by the recurrence:
 *   J(0) = 0
 *   J(1) = 1
 *   J(n) = J(n-1) + 2 * J(n-2) for n >= 2
 * The sequence is: 0, 1, 1, 3, 5, 11, 21, ...
 *
 * In the Ford-Johnson (merge-insertion) sorting algorithm, Jacobsthal numbers
 * are used to determine the order in which the 'pending' elements are inserted
 * into the main sorted chain. This order minimizes the number of comparisons
 * required for sorting, making the algorithm more efficient than standard merge sort.
 *
 * Function:
 * Generates the first n Jacobsthal numbers (starting from J(1)).
 * Returns a vector of size n, where each element is the corresponding Jacobsthal number.
 */
std::vector<size_t> PmergeMe::jacobsthal_sequence(size_t n) {
    std::vector<size_t> seq;
    seq.reserve(n);
    size_t j0 = 0, j1 = 1;
    seq.push_back(j1);
    while (seq.size() < n) {
        size_t next = seq.back() + 2 * (seq.size() > 1 ? seq[seq.size() - 2] : 0);
        seq.push_back(next);
    }
    return seq;
}

void PmergeMe::mergeInsertSortVector(std::vector<size_t>& data) {
    size_t n = data.size();
    if (n <= 1) return;
    if (n == 2) {
        if (data[1] < data[0]) std::swap(data[0], data[1]);
        return;
    }
    std::vector<size_t> main_chain;
    std::vector<size_t> pend_chain;
    size_t i = 0;
    while (i + 1 < n) {
        if (data[i] < data[i + 1]) {
            main_chain.push_back(data[i + 1]);
            pend_chain.push_back(data[i]);
        } else {
            main_chain.push_back(data[i]);
            pend_chain.push_back(data[i + 1]);
        }
        i += 2;
    }
    if (i < n) pend_chain.push_back(data[i]);
    mergeInsertSortVector(main_chain);
    std::vector<size_t> jac_seq = jacobsthal_sequence(pend_chain.size());
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
    data = main_chain;
}

void PmergeMe::mergeInsertSortDeque(std::deque<size_t>& data) {
    size_t n = data.size();
    if (n <= 1) return;
    if (n == 2) {
        if (data[1] < data[0]) std::swap(data[0], data[1]);
        return;
    }
    std::deque<size_t> main_chain;
    std::deque<size_t> pend_chain;
    size_t i = 0;
    while (i + 1 < n) {
        if (data[i] < data[i + 1]) {
            main_chain.push_back(data[i + 1]);
            pend_chain.push_back(data[i]);
        } else {
            main_chain.push_back(data[i]);
            pend_chain.push_back(data[i + 1]);
        }
        i += 2;
    }
    if (i < n) pend_chain.push_back(data[i]);
    mergeInsertSortDeque(main_chain);
    std::vector<size_t> jac_seq = jacobsthal_sequence(pend_chain.size());
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
    data = main_chain;
}

void runVector(const std::vector<size_t>& input, const std::string& containerName) {
    std::vector<size_t> data = input;
    std::cout << "Before: ";
    for (size_t i = 0; i < data.size(); ++i) std::cout << data[i] << " ";
    std::cout << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    PmergeMe::mergeInsertSortVector(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "After: ";
    for (size_t i = 0; i < data.size(); ++i) std::cout << data[i] << " ";
    std::cout << std::endl;
    double elapsed = std::chrono::duration<double, std::micro>(end - start).count();
    std::cout << "Time to process a range of " << data.size()
              << " elements with " << containerName << " : "
              << elapsed << " us" << std::endl;
}

void runDeque(const std::deque<size_t>& input, const std::string& containerName) {
    std::deque<size_t> data = input;
    std::cout << "Before: ";
    for (size_t i = 0; i < data.size(); ++i) std::cout << data[i] << " ";
    std::cout << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    PmergeMe::mergeInsertSortDeque(data);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "After: ";
    for (size_t i = 0; i < data.size(); ++i) std::cout << data[i] << " ";
    std::cout << std::endl;
    double elapsed = std::chrono::duration<double, std::micro>(end - start).count();
    std::cout << "Time to process a range of " << data.size()
              << " elements with " << containerName << " : "
              << elapsed << " us" << std::endl;
}
