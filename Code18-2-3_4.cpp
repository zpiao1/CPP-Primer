namespace A {
    class C {
        // two friends; neither is declared apart from a friend declaration
        // these functions implicitly are members of namespace A
        friend void f2();   // won't be found, unless otherwise declared
        friend void f(const C&);    // found by argument-dependent lookup
    };
}
int main()
{
    A::C cobj;
    f(cobj);    // ok: finds A::f through the friend declaration in A::C
    f2();   // error: A::f2 not declared
    return 0;
}