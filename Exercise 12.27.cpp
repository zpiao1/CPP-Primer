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
class TextQuery;
class QueryResult;
typedef shared_ptr<vector<string>> pFile_type;
typedef shared_ptr<set<size_t>> numLines_type;
typedef map<string, numLines_type> lines_type;
ostream &print(ostream &os, QueryResult qr);
class TextQuery {
private:
    pFile_type pFile;
    lines_type lines;
    pFile_type buildVector(ifstream &infile);
    lines_type buildMap();
public:
    TextQuery(ifstream &ifs):
        pFile(buildVector(ifs)), lines(buildMap()) {};
    QueryResult query(const string &s);
};
class QueryResult {
    friend ostream& print(ostream &, QueryResult);
private:
    const string word;
    pFile_type pFile;
    numLines_type numLines;
public:
    QueryResult(const string s, pFile_type pf, numLines_type nl):
        word(s), pFile(pf), numLines(nl) {};
};

pFile_type TextQuery::buildVector(ifstream &infile)
{
    string line;
    pFile_type pFile(make_shared<vector<string>>());
    pFile->push_back(line);
    while (getline(infile, line))
        pFile->push_back(line);
    return pFile;
}

lines_type TextQuery::buildMap()
{
    lines_type lines;
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

QueryResult TextQuery::query(const string &s)
{
    if (lines.find(s) == lines.end())
        return QueryResult(s, pFile, make_shared<set<size_t>>());
    else
        return QueryResult(s, pFile, lines[s]);
}

ostream &print(ostream &os, QueryResult qr)
{
    auto occur = qr.numLines->size();
    os << qr.word << " occurs " << occur << (occur == 1 ? " time" : " times") << endl;
    if (!qr.numLines->empty())
        for (auto iter = qr.numLines->cbegin(); iter != qr.numLines->cend(); ++iter)
            os << "\t(line " << *iter << ") " << (*(qr.pFile))[*iter] << endl;
    return os;
}