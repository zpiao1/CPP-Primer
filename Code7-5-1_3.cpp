class X {
    int i;
    int j;
public:
    // undefined: i is initialzed before j
    X(int val): j(val), i(j) { }
    X(int val): i(val), j(val) { }
};