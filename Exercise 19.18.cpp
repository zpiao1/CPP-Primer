#include <vector>
#include <functional>
#include <string>
#include <algorithm>
using namespace std;
size_t countEmptyStrings(const vector<string>& svec)
{
    auto f = mem_fn(&string::empty);
    return count_if(svec.begin(), svec.end(), f);
}