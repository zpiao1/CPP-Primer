#include <iostream>
#include <string>
using namespace std;
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos h, pos w): height(h), width(w), contents(h*w, ' ') {}
    Screen(pos h, pos w, char c): height(h), width(w), contents(h*w, c) {}
    char get() const;
    inline char get(pos row, pos col) const;
    Screen &move(pos row, pos col);
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(ostream &os);
    const Screen &display(ostream &os) const;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
    void do_display(ostream &os) const;
};
char Screen::get() const
{
    return contents[cursor];
}
char Screen::get(pos row, pos col) const
{
    return contents[row * width + col];
} 
Screen &Screen::move(pos row, pos col)
{
    cursor = row * width + col;
    return *this;
}
Screen &Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
Screen &Screen::set(pos row, pos col, char c)
{
    contents[row * width + col] = c;
    return *this;
}
Screen &Screen::display(ostream &os)
{
    do_display(os);
    return *this;
}
const Screen &Screen::display(ostream &os) const
{
    do_display(os);
    return *this;
}
void Screen::do_display(ostream &os) const
{
    for (pos i = 0; i != contents.size(); i++) {
        cout << contents[i];
        if (i % width == width - 1)
            cout << endl;
    }
}
int main()
{
    Screen myScreen(5, 5, 'X');
    myScreen.move(4,0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
    return 0;
}
