#include <string>
#include <map>
#include <iostream>
#include <functional>
using namespace std;
// ordinary function
int add(int i, int j) { return i + j; }
// lambda, which generates an unnamed function-object class
auto mod = [](int i, int j) { return i % j; };
// function-object class
struct div {
    int opreator()(int denominator, int divisor) {
        return denominator / divisor;
    }
};
int main()
{
    // maps an operator to a pointer to a function taking two ints and returning an int
    map<string, int(*)(int, int)> binops;
    // ok: add is a pointer to function of the appropriate type
    binops.insert({"+", add});  // {"+", add} is a pair § 11.2.3 (p. 426)
    binops.insert({"%", mod});  // error: mod is not a pointer to function
    function<int(int, int)> f1 = add; // function pointer
    function<int(int, int)> f2 = div(); // object of a function-object class
    function<int(int, int)> f3 = [](int i, int j)   // lambda
                                 { return i * j; };
    cout << f1(4, 2) << endl;   // prints 6
    cout << f2(4, 2) << endl;   // prints 2
    cout << f3(4, 2) << endl;   // prints 8
    // table of callable objects corresponding to each library operator
    // all the callables must take two ints and return an int
    // an element can be a function pointer, function object, or lambda
    map<string, function<int(int, int)>> binops;
    return 0;
}