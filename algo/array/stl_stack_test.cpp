#include <iostream>
#include <string>
#include "stl_stack.h"

using namespace stl;

void test_empty()
{
    stack<int> mystack;
    int sum (0);

    for (int i=1;i<=10;i++) mystack.push(i);

    while (!mystack.empty())
    {
        sum += mystack.top();
        mystack.pop();
    }

    std::cout << "total: " << sum << '\n';
}

void test_push_pop()
{
    stack<int> mystack;

    for (int i=0; i<5; ++i) mystack.push(i);

    std::cout << "Popping out elements...";
    while (!mystack.empty())
    {
        std::cout << ' ' << mystack.top();
        mystack.pop();
    }
    std::cout << '\n';
}

void test_size()
{
    stack<int> myints;
    std::cout << "0. size: " << myints.size() << '\n';

    for (int i=0; i<5; i++) myints.push(i);
    std::cout << "1. size: " << myints.size() << '\n';

    myints.pop();
    std::cout << "2. size: " << myints.size() << '\n';
}

void test_top()
{
    stack<int> mystack;

    mystack.push(10);
    mystack.push(20);

    mystack.top() -= 5;

    std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

void test_main(int argc, char *argv[])
{
    using std::string;
    using std::cout;
    using std::endl;

    stack<string> mystack;

    // push front
    for (int i = 1; i < argc; i++) {
        mystack.push(argv[i]);
        cout << argv[i] << " ";
    }
    cout << endl;

    // pop front
    while (!mystack.empty()) {
        cout << mystack.top() << " ";
        mystack.pop();
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    test_empty();
    test_push_pop();
    test_size();
    test_top();
    test_main(argc, argv);

    return 0;
}

