#include <iostream>
#include <functional>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using std::placeholders::_1;
int main()
{
    vector<string> vs(5, "pooh");
    vector<int> vi = {1025,1000,1018,1035,1005};
    vs.push_back("apple");
    // calls greater<int>().operator()(*iterator, 1024);
    // returns *iterator > 1024;
    auto larger = count_if(vi.cbegin(), vi.cend(), bind(greater<int>(), _1, 1024));
    cout << larger << endl;
    // calls not_equal_to<string>().operator()(*iterator, "pooh");
    // returns *iterator == "pooh";
    auto notpooh = find_if(vs.cbegin(), vs.cend(), bind(not_equal_to<string>(), _1, "pooh"));
    cout << *notpooh << endl;
    // calls multiplies<int>().operator()(*iterator, 2);
    // returns *iterator * 2;
    transform(vi.begin(), vi.end(), vi.begin(), bind(multiplies<int>(), _1, 2));
    for (auto i : vi)
        cout << i << endl;
    return 0;
}