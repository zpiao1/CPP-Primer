using namespace std;
class B {
public:
    B();
    B(const B&) = delete;
    // other members, not including a move constructor
};
class D : public B {
    // no constructors;
};
int main() 
{
    D d;        // ok: D's synthesized default constructor uses B's default constructor
    D d2(d);    // error: D's synthesized copy constructor is deleted
    D d3(std::move(d)); // error: implicitly uses D's deleted copy constructor
    return 0;
}