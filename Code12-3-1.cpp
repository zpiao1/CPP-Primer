#include "header12-3.h"
using namespace std;
void runQueries(ifstream &infile);
int main()
{
    ifstream infile("text.txt");
    runQueries(infile);
    return 0;
}
void runQueries(ifstream &infile)
{
    // infile is an ifstream that is the file we want to query
    TextQuery tq(infile);   // store the file and build the query map
    // iterate with the user: prompt for a word to find and print the results
    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        // stop if we hit end-of-file on the input or if a 'q' is entered
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}