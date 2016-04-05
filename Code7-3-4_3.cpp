struct X {
    friend void f() { /* friend function can be defined in the class body */ }
    X() { f(); }    // error: no declaration for f
    void g();
    void h();
};
void X::g() { return f(); }     // error: f hasn't been declared
void f();                       // declares the function defined inside X
void X::h() { return f(); }     // ok: declarations for f is now in scope