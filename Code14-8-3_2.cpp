#include <iostream>
#include <functional>
#include <map>
#include <string>
using namespace std;
int add(int i, int j)
{
    return i + j;
}
struct div {
    int operator()(int i, int j) {
        return i / j;
    }
};
auto mod = [](int i, int j) {
    return i % j;
}
int main()
{
    map<string, function<int(int, int)>> binops = {
        {"+", add},                                 // function pointer
        {"-", std::minus<int>()},                   // library function object
        {"/", div()},                               // user-defined function object
        {"*", [](int i, int j) { return i * j; }},  // unnamed lambda
        {"%", mod}};                                // named lambda object
    binops["+"](10, 5); // calls add(10, 5)
    binops["-"](10, 5); // uses the call operator of the minus<int> object
    binops["/"](10, 5); // uses the call operator of the div object
    binops["*"](10, 5); // calls the lambda function object
    binops["%"](10, 5); // calls the lambda function object
    return 0;
}