#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
// members are public by default; see § 7.2 (p.268)
struct PersonInfo {
    string name;
    vector<string> phones;
};
int main()
{
    string line, word;  // will hold a line and word from input, respectively
    vector<PersonInfo> people;  // will hold all the records from the input
    // read the input a line at a time until cin hits end-of-line (or another error)
    while (getline(cin, line)) {
        PersonInfo info;    // create an object to hold this record's data
        istringstream record(line); // bind record to the line we just read
        record >> info.name;    // read the name
        while (record >> word)              // read the phone numbers
            info.phones.push_back(word);    // and store them
        people.push_back(info); // append this record to people
    }
    for (const auto &entry : people) {  // for each entry in people
        ostringstream formatted, badNums;   // objects created on each loop
        for (const auto &nums : entry.phones)   {   // for each number
            if (!valid(nums))   {
                badNums << " " << nums; // string in badNums
            } else
                // "writes" to formatted's string
                formatted << " " << format(nums);
        }
        if (badNums.str().empty())  // there were no bad numbers
            os << entry.name << " " // print the name
               << formatted.str() << endl;  // and reformatted numbers
        else
            cerr << "input error: " << entry.name
                 << " invalid number(s)" << badNums.str()
                 << endl;
    }
    return 0;
}