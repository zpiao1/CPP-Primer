#include <string>
#include <iostream>
using namespace std;
class Screen {
public:
    typedef string::size_type pos;
    char get_cursor() const { return contents[cursor]; }
    char get() const;
    char get(pos ht, pos wd) const;
    static const pos Screen::*pcur() 
    { return &Screen::cursor; }
private:
    string contents;
    pos cursor;
    pos height, width;
};
int main()
{
    auto curptr = Screen::pcur();
    Screen s;
    auto c = s.*curptr;
    cout << c << endl;
    return 0;
}