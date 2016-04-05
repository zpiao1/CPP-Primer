class ConstRef {
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};
// error: ci and ri must be initialized
ConstRef::ConstRef(int ii)
{               // assignments
    i = ii;     // ok
    ci = ii;    // error: cannot assign to a const
    ri = i;     // error: ri was never initialized
}

// ok: explicitly initialize reference and const members
ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }