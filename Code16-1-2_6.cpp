using namespace std;
template <typename Type> class Bar {
    friend Type;    // grants access to the type used to instantiate Bar
    // ...
};