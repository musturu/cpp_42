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
