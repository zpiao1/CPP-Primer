#include <iostream>
#include <string>
struct Data {
    int ival;
    string s;
};
// val1.ival = 0, vall.s = string("Anna");
Data val1 = {0, "Anna"};
// error: can't use "Anna" to initialize ival, or 1024 to initialize s
Data val2 = {"Anna", 1024};