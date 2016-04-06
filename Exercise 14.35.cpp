#include <iostream>
#include <string>
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
    string s = reader();
    cout << s << endl;
    return 0;
}