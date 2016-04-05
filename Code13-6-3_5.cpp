using namespace std;
class Foo {
public:
    Foo someMem() & const;  // error: const qualifier must come first
    Foo anotherMem() const &;   // ok: const qualifier comes first
}