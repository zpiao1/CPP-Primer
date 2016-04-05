#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<int> ivec;
    cout << "ivec.capacity() = " << ivec.capacity() << endl;
    for (vector<int>::size_type i = 0; i < 50; ++i) {
        ivec.push_back(i);
        cout << "ivec.capacity() = " << ivec.capacity() << endl;
    }
    return 0;
}