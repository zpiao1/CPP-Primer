using namespace std;
class Task;
class Screen;
int main()
{
    volatile int display_register;  // int value that might change
    volatile Task *curr_task;       // curr_task points to a volatile object
    volatile int iax[max_size];     // each element in iax is volatile
    volatile Screen bitmapBuf;      // each member of bitmapBuf is volatile
    volatile int v; // v is a volatile int
    int *volatile vip;  // vip is a volatile pointer to int
    volatile int *ivp;  // ivp is a pointer to volatile int
    // vivp is a volatile pointer to volatile int
    volatile int *volatile vivp;
    int *ip = &v;   // error: must use a pointer to volatile
    ivp = &v;       // ok: ivp is a pointer to volatile
    vivp = &v;      // ok: vivp is a volatile pointer to volatile
    return 0;
}