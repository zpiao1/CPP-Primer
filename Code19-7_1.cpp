using namespace std;
int a, val;
void foo(int val)
{
    static int si;
    enum Loc { a = 1024, b };
    // Bar is local to foo
    struct Bar {
        Loc locVal; // ok: uses a local type name
        int barVal;
        void fooBar(Loc l = a)  // ok: default argument is Loc::a
        {
            barVal = val;   // error: val is local to foo
            balVal = ::val; // ok: uses a global object
            barVal = si;    // ok: uses a static local object
            locVal = b;     // ok: uses a enumerator
        }
    };
    // ...
}