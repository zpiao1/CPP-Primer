#include <iostream>
using namespace std;
struct IfThenElse {
    int operator()(bool test, int second, int third) const {
        if (test)
            return second;
        else
            return third;
    }
};
int main()
{
    IfThenElse test;
    cout << test(true, 2, 3) << endl;
    cout << test(false, 2, 3) << endl;
}