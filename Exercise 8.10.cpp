#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    vector<string> strs;
    ifstream ifs("vectorIn.txt");
    string line;
    while (getline(ifs, line)) 
        strs.push_back(line);

    for (const auto &str : strs) {
        istringstream iss(str);
        string word;
        while (iss >> word)
            cout << word << endl;
    }

    return 0;
}