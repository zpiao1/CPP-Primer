using namespace std;
void foo()
{
    class Bar {
    public:
        // ...
        class Nested;   // declares class Nested
    };
    // definition of Nested
    class Bar::Nested {
        // ...
    };
}