#include <string>
using namespace std;
class Screen {
public:
    // other interface and implementation members as before
    Screen& home(); // cursor movement functions
    Screen& forward(); 
    Screen& back();
    Screen& up();
    Screen& down();
    // Action is a pointer that can be assigned any of the cursor movement members
    using Action = Screen& (Screen::*)();
    // specify which direction to move; enum see § 19.3 (p. 832)
    enum Directions { HOME, FORWARD, BACK, UP, DOWN };
    Screen& move(Directions);
private:
    static Action Menu[];   // function table
};

Screen& Screen::move(Directions cm)
{
    // run the element indexed by cm on this object
    return (this->*Menu[cm])(); // Menu[cm] points to a member function
}

Screen::Action Screen::Menu[] = { &Screen::home,
                                  &Screen::forward,
                                  &Screen::back,
                                  &Screen::up,
                                  &Screen::down,
};
int main()
{
    Screen myScreen;
    myScreen.move(Screen::HOME);    // invokes myScreen.home
    myScreen.move(Screen::DOWN);    // invokes myScreen.down
    return 0;
}