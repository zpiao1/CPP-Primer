#include <string>
#include <vector>
using namespace std;
int main()
{
    int *pi = new int(1024);    // object to which pi points has value 1024
    string *ps = new string(10, '9');   // *ps is "9999999999"
    // vector with ten elements with values from 0 to 9
    vector<int> *pv = new vector<int>{0,1,2,3,4,5,6,7,8,9};
    return 0;
}