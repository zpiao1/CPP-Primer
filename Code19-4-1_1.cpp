#include <string>
using namespace std;
class Screen {
public:
    // data is a static member that returns a pointer to member
    static const std::string Screen::*data()
    { return &Screen::contents; }
    // other members as before
};
int main()
{
    // pdata can point to a string member of a const (or non const) Screen object
    const string Screen::*pdata;
    pdata = &Screen::contents;
    auto pdata = &Screen::contents;
    Screen myScreen, *pScreen = &myScreen;
    // .* dereferences pdata to fetch the contents member from the object myScreen
    auto s = myScreen.*pdata;
    // ->* dereferences pdata to fetch contents from the object to which pScreen points
    s = pScreen->*data;
    // data() returns a pointer to the contents member of class Screen
    const string Screen::*pdata = Screen::data();
    // fetch the contents of the object named myScreen
    auto s = myScreen.*pdata;
    return 0;
}