class Bar {
public:
    // ...
private:
    static Bar mem1;    // ok: static member can have incomplete type
    Bar *mem2;          // ok: pointer member can have incomplete type
    Bar mem3;           // error: data members must have complete type
};