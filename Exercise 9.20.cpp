#include <deque>
#include <list>
#include <iostream>
using namespace std;
int main()
{
    list<int> intList = {1,2,3,4,5,6,7,8,9,10};
    deque<int> oddQueue, evenQueue;
    size_t i = 1;
    for (auto iter = intList.begin(); iter != intList.end(); ++iter, ++i)
        if (i % 2 == 0)
            evenQueue.push_back(*iter);
        else
            oddQueue.push_back(*iter);
    cout << "oddQueue: ";
    for (auto num : oddQueue)
        cout << num << ' ';
    cout << endl;
    cout << "evenQueue: ";
    for (auto num : evenQueue)
        cout << num << ' ';
    cout << endl;
    return 0;
}