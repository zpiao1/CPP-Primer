#include <vector>
#include <string>
#include <utility>
using namespace std;
pair<string, int> process(vector<string> &v)
{
    // process v
    if (!v.empty())
        return {v.back(), v.back().size()}; // list initialize
    else
        return pair<string, int>(); // explicitly constructed return value
    if (!v.empty())
        return pair<string, int>(v.back, v.back().size());
    if (!v.empty())
        return make_pair(v.back(), v.back().size());
}