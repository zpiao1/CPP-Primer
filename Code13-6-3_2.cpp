#include "StrVec.h"
using namespace std;
int main()
{
    StrVec vec; // empty StrVec
    string s = "some string or another";
    vec.push_back(s);       // calls push_back(const string &);
    vec.push_back("done");  // calls push_back(string &&);
    return 0;
}