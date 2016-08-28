#include <vector>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;
template <typename T>
typename vector<T>::size_type count(const vector<T>& vec, const T t)
{
    typename vector<T>::size_type cnt = 0;
    for (const T& val : vec)
        if (val == t)
            ++cnt;
    return cnt;
}

template <>
typename vector<const char*>::size_type count(const vector<const char*>& vec, const 
    char* t)
{
    typename vector<const char*>::size_type cnt = 0;
    for (const char* const& val : vec)
        if (strcmp(val, t) == 0)
            ++cnt;
    return cnt;
}
int main()
{
    vector<const char*> csvec{"0", "1", "0", "2"};
    cout << count(csvec, "0") << endl;
    return 0;
}