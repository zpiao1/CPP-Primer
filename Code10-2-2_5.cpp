#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
    vector<int> vec;    // empty vector
    // ok: back_inserter creates an insert iterator that adds elements to vec
    fill_n(back_inserter(vec), 10, 0);  // appends ten elements to vec
    return 0;
}