#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> vec;    // empty vector
    // use vec giving it various values
    fill_n(vec.begin(), vec.size(), 0); // reset all the elements of vec to 0
    return 0;
}