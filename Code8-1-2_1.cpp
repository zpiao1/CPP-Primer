#include <iostream>
using namespace std;
int ival;
cin >> ival;
while (cin >> word)
    // ok: read operation successful...
// remember the current state of cin
auto old_state = cin.rdstate(); // remember the current state of cin 
cin.clear();                    // make cin valid
process_input(cin);             // use cin
cin.setstate(old_state);        // now reset cin to its old state
// turns off failbit and badbit but all other bits unchanged
cin.clear(cin.rdstate() & ~cin.failbit() & ~cin.badbit);