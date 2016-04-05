#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Screen {
public:
    typedef std::string::size_type pos;
    Screen() = default; 
    Screen(pos ht, pos wd): height(ht), width(wd), contents(ht * wd, ' ') { }
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }
    char get() const                        
        { return contents[cursor]; }        
    inline char get(pos r, pos c) const;  
    Screen &move(pos r, pos c);             
    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);
    // display overloaded on whether the object is const or not
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }
    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;   
    // function to do the work of displaying a Screen
    void do_display(std::ostream &os) const
    {
        os << contents;
    }           
};
class Window_mgr {
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};
inline                                      
Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;                    
    cursor = row + c;                       
    return *this;                           
}
char Screen::get(pos r, pos c) const
{
    pos row = r * width;
    return contents[row + c];
}
inline Screen &Screen::set(char c)
{
    contents[cursor] = c;   // set the new value at the current cursor location
    return *this;           // return this object as an lvalue
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch; // set specified location to given value
    return *this;                   // return this object as an lvalue
}
int main()
{
    Screen myScreen;
    char ch = myScreen.get();
    ch = myScreen.get(0, 0);
    // move the cursor to a given position, and set that character
    myScreen.move(4, 0).set('#');
    const Screen blank(5, 3);
    myScreen.set('#').display(cout);    // calls non const version
    blank.display(cout);                // calls const version
    return 0;
}