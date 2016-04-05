#include <vector>
#include <set>
using namespace std;
int main()
{
    vector<int> ivec = {2,4,6,8,2,4,6,8};   // ivec has eight elements
    set<int> set2;                          // empty set
    set2.insert(ivec.cbegin(), ivec.cend());    // set2 has four elements
    set2.insert({1,3,5,7,1,3,5,7});         // set2 now has eight elements
    return 0;
}