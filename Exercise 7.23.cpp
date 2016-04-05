#include <iostream>
#include <string>
using namespace std;
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos h, pos w): height(h), width(w), contents(h*w, ' ') {}
    Screen(pos h, pos w, char c): height(h), width(w), contents(h*w, c) {}
    char get() const
    {
        return contents[cursor];
    }
    inline char get(pos r, pos c) const;
    Screen &move(pos r, pos c);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
};
char Screen::get(pos r, pos c) const
{
    return contents[r*width + c];
}
Screen &Screen::move(pos r, pos c)
{
    cur = r * width + c;
    return *this;
}