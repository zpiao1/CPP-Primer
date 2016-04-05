#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;
int main()
{
    vector<string> text;
    string para1("Hello world\n");
    string emptystr;
    string para2("Welcome to C++\n");
    text.push_back(para1);
    text.push_back(emptystr);
    text.push_back(para2);
    for (auto it1 = text.begin(); it1 != text.end() && !(it1->empty()); it1++)
        for (auto it2 = it1->begin(); it2 != it1->end(); it2++)
            *it2 = toupper(*it2);

    for (auto it1 = text.begin(); it1 != text.end(); it1++)
        cout << *it1 << endl;
    return 0;
}
