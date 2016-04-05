typedef double Money;
class Account {
public:
    Money balance() { return bal; } // uses Money from the outer scope
private:
    typedef double Money;   // error: cannot redefine Money
    Money bal;
    // ... 
};