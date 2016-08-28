#include <vector>
#include <string>
#include <iostream>
using namespace std;
template <typename T>
typename vector<T>::size_type count(const vector<T>& vec, const T& t)
{
    typename vector<T>::size_type cnt = 0;
    for (const T& val : vec)
        if (val == t)
            ++cnt;
    return cnt;
}

int main()
{
    vector<double> dvec{0.0, 1.0, 0.0, 2.0};
    vector<int> ivec{0, 1, 0, 2};
    vector<string> svec{"0", "1", "0", "2"};
    cout << count(dvec, 0.0) << endl;
    cout << count(ivec, 0) << endl;
    cout << count(svec, string("0")) << endl;
    return 0;
}