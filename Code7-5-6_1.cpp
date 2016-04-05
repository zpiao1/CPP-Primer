using namespace std;
class Debug {
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) {}
    constexpr Debug(bool h, bool i, bool o):
        hw(h), io(i), other(o) {}
    constexpr bool any() { return hw || io || other; }
    void set_io(bool b) { io = b; }
    void set_hw(bool b) { hw = b; }
    void set_other(bool b) { other = b; }
private:
    bool hw;    // hardware errors other than IO errors
    bool io;    // IO errors
    bool other; // other errors
};
constexpr Debug io_sub(false, true, false); // debugging IO
if (io_sub.any())   // equivalent to if(true)
    cerr << "print appropriate error messages" << endl;
constexpr Debug prod(false);                // no debugging during production
if (prod.any())     // equivalent to if (false)
    cerr << "print an error message" << endl;
    