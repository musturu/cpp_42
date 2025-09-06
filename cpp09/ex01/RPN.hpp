#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <list>

class RPN {
public:
    RPN();
    int evaluate(const std::string& expr);
};

#endif // RPN_HPP
