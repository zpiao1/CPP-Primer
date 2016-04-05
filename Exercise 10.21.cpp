#include <iostream>
using namespace std;
int main()
{
    int i = 5;
    auto f = [&i]() -> bool {
        while (i != 0)
            --i;
        return i == 0;
    };
    cout << f() << ' ' << i << endl;
    return 0;
}