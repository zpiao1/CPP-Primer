#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void biggies(vector<string> &words, vector<string>::size_type sz);
int main()
{
    return 0;
}
void biggies(vector<string> &words, vector<string>::size_type sz)
{
    [sz](const string &a)
        { return a.size() >= sz; };
    // error: sz not captured
    [](const string &a)
      { return a.size() >= sz; };
}