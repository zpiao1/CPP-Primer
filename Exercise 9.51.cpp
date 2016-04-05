#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Date {
    friend void printDate(const Date &);
private:
    unsigned year = 1900;
    unsigned month = 1;
    unsigned day = 1;
    const vector<string> months = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    const vector<string> mabbr = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
public:
    Date() = default;
    Date(const string &s);
};
Date::Date(const string &s)
{
    string::size_type pos = 0;
    // "January 1, 1900"
    for (decltype(months.size()) i = 0; i < months.size(); ++i) {
        if ((pos = s.find(months[i]), pos) != string::npos) {
            month = i + 1;
            pos += months[i].size() + 1;
            day = stoi(s.substr(pos));
            pos += (day > 9 ? 4 : 3);
            year = stoi(s.substr(pos));
            return;
        }
    }
    // "Jan 1, 1900"
    for (decltype(mabbr.size()) i = 0; i < mabbr.size(); ++i) {
        if ((pos = s.find(mabbr[i]), pos) != string::npos) {
            month = i + 1;
            pos += mabbr[i].size() + 1;
            day = stoi(s.substr(pos));
            pos += (day > 9 ? 4 : 3);
            year = stoi(s.substr(pos));
            return;
        }
    }
    // "1/1/1900"
    pos = 0;
    month = stoi(s);
    pos += (month > 9 ? 3 : 2);
    day = stoi(s.substr(pos));
    pos += (day > 9 ? 3 : 2);
    year = stoi(s.substr(pos));
}
void printDate(const Date &d)
{
    cout << d.month << '/' << d.day << '/' << d.year << endl;
}
int main()
{
    Date d1("January 1, 1900"), d2("1/1/1900"), d3("Jan 1, 1900");
    printDate(d1);
    printDate(d2);
    printDate(d3);
    return 0;
}
