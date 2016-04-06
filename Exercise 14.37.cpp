#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
class Equal {
public:
    Equal(int A = 0):
        a(A) {}
    bool operator()(int b) const {
        return a == b;
    }
private:
    int a;
};
int main()
{
    vector<int> vi(3, 5);
    replace_if(vi.begin(), vi.end(), Equal(5), 6);
    for (auto i : vi)
        cout << i << endl;
    return 0;
}