#include <iostream>
#include "Chapter6.h"
using namespace std;
void gen_nums(void)
{
    static int cnt = 0;
    for (int i = 0; i <= cnt; i++)
        cout << i << ' ';
    cnt++;
    cout << endl;
}
int main()
{
    for (int i = 0; i != 10; i++)
        gen_nums();
    return 0;
}