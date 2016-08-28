#include <iostream>
using namespace std;
template <typename ... Args> void g(Args ... args) {
    cout << sizeof...(Args) << endl;    // number of type parameters
    cout << sizeof...(args) << endl;    // number of function parameters
}