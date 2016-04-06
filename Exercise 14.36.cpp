#include <iostream>
#include <string>
#include <vector>
using namespace std;
class ReadString {
private:
    istream &is;
public:
    ReadString(istream &i = cin):
        is(i) {}
    string operator()() const {
        string ret;
        getline(is, ret);
        return ret;
    }
};
int main()
{
    ReadString reader;
    vector<string> vs;
    string line;
    while (cin) {
        line = reader();
        vs.push_back(line);
    }
    for (const auto &s : vs)
        cout << s << endl;
    return 0;
}