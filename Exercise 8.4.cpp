#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<string> &readIntoVec(vector<string> &vec, istream& is);
int main()
{
    string filename("vectorIn.txt");
    ifstream input(filename);
    vector<string> strs;
    readIntoVec(strs, input);
    for (const auto &s : strs) 
        cout << s << endl;
    return 0;
}
vector<string> &readIntoVec(vector<string> &vec, istream& is)
{
    string s;
    while (getline(is, s))
        vec.push_back(s);
    return vec;
}