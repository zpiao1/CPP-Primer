#include <string>
class Screen;
// Action is a type that can point to a member function of Screen
// that returns a char and takes two pos arguments
using Action = char (Screen::*)(Screen::pos, Screen::pos) const;
// action takes a reference to a Screen and a pointer to a Screen member function
Screen& action(Screen&, Action = &Screen::get);
int main()
{
    // pmf is a pointer that can point to a Screen member function that is const
    // that returns a char and takes no arguments
    auto pmf = &Screen::get_cursor;
    char (Screen::*pmf2)(Screen::pos, Screen::pos) const;
    pmf2 = &Screen::get;
    // error: nonmember function p cannot have a const qualifier
    char Screen::*p(Screen::pos, Screen::pos) const;
    // pmf points to a Screen member that takes no arguments and returns char
    pmf = &Screen::get; // must explicitly use the address-of operator
    pmf = Screen::get;  // error: no conversion to pointer for member
    Screen myScreen, *pScreen = &myScreen;
    // call the function to which pmf points on the object to which pScreen points
    char c1 = (pScreen->*pmf)();
    // passes the arguments 0, 0 to the two-parameter version of get on the object myScreen
    char c2 = (myScreen.*pmf2)(0,0);
    Screen myScreen;
    // equivalent calls:
    action(myScreen);   // uses the default argument
    action(myScreen, get);  // uses the variable get that we previously defined
    action(myScreen, &Screen::get); // passes the address explicitly
    return 0;
}