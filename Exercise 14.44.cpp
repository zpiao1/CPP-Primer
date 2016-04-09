#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <functional>
using namespace std;
int main()
{
    string exec;
    istringstream iss;
    map<char, function<int(int, int)>> binops = {
        {'+', [](int i, int j) { return i + j; }},
        {'-', [](int i, int j) { return i - j; }},
        {'*', [](int i, int j) { return i * j; }},
        {'/', [](int i, int j) { return i / j; }},
        {'%', [](int i, int j) { return i % j; }}
    };
    while (getline(cin, exec) && exec != "") {
        iss.clear();
        iss.str(exec);
        int op1, op2;
        char oper;
        iss >> op1 >> oper >> op2;
        if (!iss)
            continue;
        if ((oper == '%' || oper == '/') && op2 == 0) {
            cerr << "Division by zero" << endl;
            continue;
        }
        cout << binops[oper](op1, op2) << endl;
    }
    return 0;
}