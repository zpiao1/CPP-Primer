#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
class EqualLength {
public:
    EqualLength(size_t sz):
        length(sz) {}
    bool operator()(const string &s) const {
        return s.size() == length;
    }
    size_t getCount() const {
        return count;
    }
    void incCount() {
        count++;
    }
private:
    size_t length;
    size_t count = 0;
};
int main()
{
    ifstream ifs("words.txt");
    vector<EqualLength> vel;
    for (size_t i = 0; i != 10; ++i)
        vel.push_back(EqualLength(i + 1));
    string word;
    while (ifs >> word)
        for (auto &el : vel)
            if (el(word))
                el.incCount();
    for (const auto &el : vel) 
        cout << el.getCount() << endl;
    return 0;
}