#include <vector>
#include <string>
using namespace std;
int main()
{
    vector<string> svec;    // empty vector
    cout << svec[0];        // run-time error: there are no elements in svec!
    cout << svec.at[0];     // throws an out_of_range exception
    return 0;
}