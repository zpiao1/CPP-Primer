#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> vec;    // empty vector
    // disaster: attempts to write to ten (nonexistent) elements in vec
    fill_n(vec.begin(), 10, 0);
    return 0;
}