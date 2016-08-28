#include <tuple>
#include <iostream>
using namespace std;
int main()
{
    tuple<int, int, int> threeI(10, 20, 30);
    cout << get<0>(threeI) << endl;
    cout << get<1>(threeI) << endl;
    cout << get<2>(threeI) << endl;
    return 0;
}