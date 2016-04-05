#include "header12-3.h"
using namespace std;
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);
    cout << "enter word to look for, or q to quit: ";
    string s;
    if (cin >> s && s != q)
        do {
            print(cout, tq.query(s)) << endl;
            cout << "enter word to look for, or q to quit: ";
            string s;
        } while (cin >> s && s != q);
}