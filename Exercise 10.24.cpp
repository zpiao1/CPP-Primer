#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std::placeholders;
using namespace std;
bool check_size(const string &s, string::size_type sz);
int main()
{
    vector<int> ivec;
    string s("aString");
    srand(static_cast<unsigned>(time(nullptr)));
    for (auto i = 0; i < 50; i++)
        ivec.push_back(rand() % 30);
    auto iter = find_if(ivec.begin(), ivec.end(), bind(check_size, ref(s), _1));
    if (iter != ivec.end())
        cout << *iter << endl;
    return 0;
}
bool check_size(const string &s, string::size_type sz)
{
    return s.size() < sz;
}