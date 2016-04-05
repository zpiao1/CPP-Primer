struct NoDefault {
    NoDefault(int val);
    int a;
};
struct C {
    NoDefault c;
    C(): c(0) {}
};