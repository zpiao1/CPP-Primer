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
    for (const auto &rec : people) {
        cout << "Name: " << rec.name << endl;
        cout << "Phone: " << endl;
        for (const auto &phone : rec.phones)
            cout << phone << endl;
    }
    return 0;
}