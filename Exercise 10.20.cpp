#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    vector<string> words = {"Lambda", "expressions" ,"are", "most", "useful", "for", "simple", "operations", "that", "we", "do", "not", "need", "to", "use"};
    cout << count_if(words.begin(), words.end(), [](const string &s) { return s.size() > 6; }) << endl;
    return 0;
}