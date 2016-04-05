#include <iostream>
ofstream out1, out2;
out1 = out2;                // error: cannot assign stream objects
ofstream print(ofstream);   // error: cannot initiailize the ofstream parameter
out2 = print(out2);         // error: cannot copy stream objects