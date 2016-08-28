namespace A {
    int i;
    int k;

    class C1 {
    public:
        C1(): i(0), j(0) { }    // ok: initializes C1::i and C1::j
        int f1() { return k; }  // returns A::k
        int f2() { return h; }  // error: h is not defined
        int f3();
    private:
        int i;                  // hides A::i within C1
        int j;
    };
    int h = i;                  // initialized from A::i
}
// member f3 is defined outside class C1 and outside namespace A
int A::C1::f3() { return h; }   // ok: returns A::h
