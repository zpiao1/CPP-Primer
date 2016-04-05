#include <iostream>
#include <string>
typedef string::size_type sz;   // typedef see § 2.5.1 (p. 67)
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ');
int main()
{
    string window;
    window = screen();              // equivalent to screen(24, 80, ' ')
    window = screen(66);            // equivalent to screen(60, 80, ' ')
    window = screen(66, 256);       // screen(66, 256, ' ')
    window = screen(66, 256, '#');  // screen(66, 256, '#')
    window = screen(, , '?');       // error: can omit only trailing arguments
    window = screen('?');           // calls screen('?', 80, ' ')
    return 0;
}