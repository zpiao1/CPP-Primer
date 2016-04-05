#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Screen;
class Window_mgr {
public:
    // location ID for each screen on the window
    using ScreenIndex = std::vector<Screen>::size_type;
    // reset the Screen at te given position to all blanks
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};

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
    friend void Window_mgr::clear(ScreenIndex);
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;   
    void do_display(std::ostream &os) const
    {
        os << contents;
    }           
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
    contents[cursor] = c;
    return *this;
}
inline Screen &Screen::set(pos r, pos col, char ch)
{
    contents[r * width + col] = ch;
    return *this;
}
void Window_mgr::clear(ScreenIndex i)
{
    // s is a reference to the Screen we want to clear
    Screen &s = screens[i];
    // reset the contents of the Screen to all blanks
    s.contents = string(s.height * s.width, ' ');
}
int main()
{
    
    return 0;
}