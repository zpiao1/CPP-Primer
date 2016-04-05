#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <cctype>
using namespace std;
map<string, shared_ptr<set<size_t>>> buildMap(shared_ptr<vector<string>> pFile);
shared_ptr<vector<string>> buildVector(ifstream &infile);
void runQueries(ifstream &infile);
int main()
{
    ifstream infile("text.txt");
    runQueries(infile);
    return 0;
}
void runQueries(ifstream &infile)
{
    shared_ptr<vector<string>> pFile = buildVector(infile);
    map<string, shared_ptr<set<size_t>>> lines = buildMap(pFile);
    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q")
            break;
        if (lines.find(s) == lines.end())
            cout << s << " occurs 0 times" << endl;
        else {
            shared_ptr<set<size_t>> plineNums = lines[s];
            auto occur = plineNums->size();
            cout << s << " occurs " << occur << (occur == 1 ? " time" : " times") << endl;
            for (auto iter = plineNums->cbegin(); iter != plineNums->cend(); ++iter)
                cout << "\t(line " << *iter << ") " << (*pFile)[*iter] << endl;
        }
    }
}
shared_ptr<vector<string>> buildVector(ifstream &infile)
{
    vector<string> file{""};
    string line;
    while (getline(infile, line))
        file.push_back(line);
    shared_ptr<vector<string>> pFile(make_shared<vector<string>>(file.cbegin(), file.cend()));
    return pFile;
}
map<string, shared_ptr<set<size_t>>> buildMap(shared_ptr<vector<string>> pFile)
{
    map<string, shared_ptr<set<size_t>>> lines;
    for (size_t lineNum = 1; lineNum != pFile->size(); ++lineNum) {
        istringstream iss((*pFile)[lineNum]);
        string word;
        while (iss >> word) {
            if (isupper(word[0]))
                word[0] = tolower(word[0]);
            if (!isalpha(word.back()))
                word.pop_back();
            if (lines.find(word) == lines.end()) {
                auto il = {lineNum};
                lines.insert(make_pair(word, make_shared<set<size_t>>(il)));
            }
            else
                (lines[word])->insert(lineNum);
        }
    }
    return lines;
}
