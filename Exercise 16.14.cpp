#include <iostream>
#include <string>
using namespace std;
template <unsigned H, unsigned W>
class Screen {
public:
    typedef std::string::size_type pos;
    Screen(): height(H), width(W), contents(H * W, ' ') {}
    Screen(char c): height(H), width(W), contents(H * W, c) {}
    char get() const {
        return contents[cursor];
    }
    char get(pos row, pos col) const {
        return contents[row * width + col];
    }
    Screen move(pos row, pos col);
    Screen set(char);
    Screen set(pos, pos, char);
    Screen display(ostream &os);
    const Screen display(ostream &os) const;
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    void do_display(ostream &os) const;
};
template <unsigned H, unsigned W>
Screen<H, W> Screen<H, W>::move(pos row, pos col)
{
    cursor = row * width + col;
    return *this;
}
template <unsigned H, unsigned W>
Screen<H, W> Screen<H, W>::set(char c)
{
    contents[cursor] = c;
    return *this;
}
template <unsigned H, unsigned W>
Screen<H, W> Screen<H, W>::set(pos row, pos col, char c)
{
    contents[row * width + col] = c;
    return *this;
}
template <unsigned H, unsigned W>
Screen<H, W> Screen<H, W>::display(ostream &os)
{
    do_display(os);
    return *this;
}
template <unsigned H, unsigned W>
const Screen<H, W> Screen<H, W>::display(ostream &os) const
{
    do_display(os);
    return *this;
}
template <unsigned H, unsigned W>
void Screen<H, W>::do_display(ostream &os) const
{
    for (pos i = 0; i != contents.size(); i++) {
        os << contents[i];
        if (i % width == width - 1)
            os << endl;
    }
}
int main()
{
    Screen<5, 5> myScreen('X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << '\n';
    myScreen.display(cout);
    cout << '\n';
    return 0;
}