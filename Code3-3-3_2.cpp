#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // count the number of grades by clusters of ten: 0--9, 10--19, ... , 90--99, 100
    vector<unsigned> scores(11, 0);     // 11 buckets, all initially 0
    unsigned grade;
    while (cin >> grade) {      // read the grades
        if (grade <= 100)       // handle only valid grades
        ++scores[grade/10];     // increment the counter for the current cluster
    }
    for (auto i : scores)
        cout << i << " ";
    cout << endl;
    return 0;
}
