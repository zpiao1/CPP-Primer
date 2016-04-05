#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default; // needed because Screen has another constructor
    // cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    char get() const                        // get the character at the cursor
        { return contents[cursor]; }        // implicitly inline
    inline char get(pos r, pos c) const;  // explicitly inline
    Screen &move(pos r, pos c);             // can be made inline later
    void some_member() const;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;              // may change even in a const object
};
class Window_mgr {
private:
    // Screens this Window_mgr is tracking
    // by default, a Window_mgr has one standard sized blank Screen
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};
inline                                      // we can specify inline on the definition
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;                    // compute the row location
    cursor = row + c;                       // move cursor to the column within that row
    return *this;                           // return this object as an lvalue
}
char Screen::get(pos r, pos c) const        // declared as inline in the class
{
    pos row = r * width;                    // compute row location
    return contents[row + c];               // return character at the given column
}
int main()
{
    Screen myscreen;
    char ch = myscreen.get();   // calls Screen::get()
    ch = myscreen.get(0, 0);    // calls Screen::get(pos, pos)
    return 0;
}
void Screen::some_member() const
{
    ++access_ctr;       // keep a count of the calls to any member function
    // whatever other work this member needs to do
}