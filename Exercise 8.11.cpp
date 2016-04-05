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
    string line, word;
    vector<PersonInfo> people;
    istringstream record;
    while (getline(cin, line)) {
        record.str(line);
        PersonInfo info;
        record >> info.name;
        while (record >> word)
            info.phones.push_back(word);
        people.push_back(info);
        record.clear();
    }
    for (const auto &rec : people) {
        cout << "Name: " << rec.name << endl;
        cout << "Phone: " << endl;
        for (const auto &phone : rec.phones)
            cout << phone << endl;
    }
    return 0;
}