#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> map_a_b;
    for (int i = 0; i < 10; ++i)
        map_a_b[i] = 0;
    for (auto map_it = map_a_b.begin(); map_it != map_a_b.end(); ++map_it)
        map_it->second = 3;
    for (const auto &p : map_a_b)
        cout << p.first << ' ' << p.second << endl;
    return 0;
}