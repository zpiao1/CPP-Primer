#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> strints{"1", "3", "5", "7", "9"};
    vector<string> strfloats{"1.0", "3.2", "5.4", "7.6", "9.8"};
    int sumints = 0;
    double sumfloats = 0.0;
    for (const auto &s : strints)
        sumints += stoi(s);
    cout << "sumints: " << sumints << endl;
    for (const auto &s : strfloats)
        sumfloats += stod(s);
    cout << "sumfloats: " << sumfloats << endl;
    return 0;
}