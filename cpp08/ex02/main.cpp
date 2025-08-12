#include <iostream>
#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;

    std::cout << "--- Testing MutantStack ---" << std::endl;
    
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top:"  << mstack.top() << std::endl;

    
    mstack.pop();
    std::cout << "Size:" mstack.size() << std::endl;

    mstack.push(1);
    mstack.push(2);
    mstack.push(123);
    mstack.push(0);
    mstack.push(5);
    mstack.push(3712);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator end = mstack.end();

    while (it != end)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "--- Testing with std::list ---" << std::endl;

    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);

    std::cout << "Back:" << lst.back() << std::endl;

    lst.pop_back();

    std::cout << "Size:" << lst.size() << std::endl;

    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(123);
    lst.push_back(0);
    lst.push_back(5);
    lst.push_back(3712);

    std::list<int>::iterator lit = lst.begin();
    std::list<int>::iterator lite = lst.end();

    ++lit;
    --lit;
    while (lit != lite)
    {
        std::cout << *lit << std::endl;
        ++lit;
    }

    std::cout << "--- Additional tests ---" << std::endl;

    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("!");

    for (MutantStack<std::string>::iterator it = strStack.begin(); it != strStack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    MutantStack<int> mstack2;
    mstack2.push(1);
    mstack2.push(2);
    mstack2.push(3);

    std::cout << "Reverse iteration test: " << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack2.rbegin(); rit != mstack2.rend(); ++rit) {
        std::cout << *rit << " ";
    }
    std::cout << std::endl;

    const MutantStack<int> constStack(mstack);
    std::cout << "Const Stack Tests iteration: " << std::endl;
    for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit) {
        std::cout << *cit << " ";
    }
    std::cout << std::endl;

    return 0;
}