using namespace std;
// template that takes a callable and two parameters
// and calls the given callable with the parameter ''flipped''
// flip1 is an incomplete implementation: top-level const and references are lost
template <typename F, typename T1, typename T2>
void flip1(F f, T1 t1, T2 t2)
{
    f(t2, t1);
}
void f(int v1, int& v2) // note v2 is a reference
{
    cout << v1 << " " << ++v2 << endl;
}
template <typename F, typename T1, typename T2>
void flip2(F f, T1 &&t1, T2 &&t2)
{
    f(t2, t1);
}
void g(int &&i, int &j)
{
    cout << i << " " << j << endl;
}
int main()
{
    f(42, i);   // f changes its argument i
    flip1(f, j, 42);    // f called through flip1 leaves j unchanged
    // instantiates:
    // void flip1(void(*fcn)(int, int&), int t1, int t2);
    flip2(f, j, 42);
}
