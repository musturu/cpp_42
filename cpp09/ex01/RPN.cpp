#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN() {}

int RPN::evaluate(const std::string& expr) {

    std::stack<int> s;
    std::istringstream iss(expr);
    std::string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (s.size() < 2)
                throw std::runtime_error("Error: invalid RPN expression");

            int b = s.top(); s.pop();

            int a = s.top(); s.pop();

            if (token == "+")
                s.push(a + b);
            else if (token == "-")
                s.push(a - b);
            else if (token == "*")
                s.push(a * b);
            else if (token == "/") {
                if (b == 0)
                    throw std::runtime_error("Error: trying division by zero");
                s.push(a / b);
            }
        } else {
            if (token.size() != 1 || token[0] < '0' || token[0] > '9')
                throw std::runtime_error("Error: Token not in subject range");
            s.push(token[0] - '0');
        }
    }
    if (s.size() != 1)
        throw std::runtime_error("Error: invalid RPN expression");
    return s.top();
}
