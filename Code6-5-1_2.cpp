#include <iostream>
#include <string>
// no default for the height or width parameters
string screen(sz, sz, char = ' ');
string screen(sz, sz, char = '*');  // error: redeclaration
string screen(sz = 24, sz = 80, char);  // ok: adds default arguments
typedef string::size_type sz;
// the declarations of wd, def, and ht must appear outside a function
sz wd = 80;

char def = ' ';
sz ht();
string screen(sz = ht(), sz = wd, char = def);
string window = screen();   // calls screen(ht(), 80, ' ')
void f2()
{
    def = '*';      // changes the value of a default argument
    sz wd = 100;    // hides the outer definition of wd but does not change the default
    window = screen();  // calls screen(ht(), 80, '*')
}