using namespace std;
struct B {
    virtual void f1(int) const;
    virtual void f2();
    void f3();
};
struct D1 : B {
    void f1(int) const override;    // ok: f1 matches f1 in the base
    void f2(int) override;          // error: B has no f2(int) function
    void f3() override;             // error: f3 is not virtual
    void f4() override;             // error: B doesn't have a function named f4
};
struct D2 : B {
    // inherits f2() and f3() from B and overrides f1(int)
    void f1(int) const final;       // subsequent classes can't override f1(int)
};
struct D3 : D2 {
    void f2();                      // ok: overrides f2 inherited from the indirect base, B
    void f1(int) const;             // error: D2 declared f2 as final
}