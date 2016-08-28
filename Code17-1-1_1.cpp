#include <tuple>
#include <string>
#include <vector>
#include <list>
using namespace std;

int main()
{
    tuple<size_t, size_t, size_t> threeD;   // all three members set to 0
    tuple<string, vector<double>, int, list<int>> someVal("constants", {3.14, 2.718}, 42, {0,1,2,3,4,5});
    tuple<size_t, size_t, size_t> threeD = {1,2,3}; // error
    typle<size_t, size_t, size_t> threeD{1,2,3};    // ok
    return 0;
}