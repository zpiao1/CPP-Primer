#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
class LengthInRange {
public:
    LengthInRange(size_t lower_bound, size_t upper_bound):
        lower(lower_bound), upper(upper_bound) {}
    bool operator()(const string &s) const {
        return s.size() >= lower && s.size() <= upper;
    }
private:
    size_t lower, upper;
};
int main()
{
    ifstream ifs("words.txt");
    int count = 0;
    LengthInRange lir(1, 10);
    string word;
    while (ifs >> word) {
        if (lir(word))
            count++;
    }
    cout << count << endl;
    return 0;
}