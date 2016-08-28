#include <iostream>
#include <memory>
// function-object class that calls delete on a given pointer
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr): os(s) {}
    // as with any function template, the type of T is deduced by the compiler
    template <typename T> void operator()(T* p) const {
        os << "deleting unique_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};
// // sample instantiations for member templates of DebugDelete
// void DebugDelete::operator()(int *p) const { delete p; }
// void DebugDelete::operator()(string *p) const { delete p; }
using namespace std;
int main()
{
    double* p = new double;
    DebugDelete d;  // an object that can act like a delete expression
    d(p);   // calls DebugDelete::operator()(double*), which delete p
    int* ip = new int;
    // calls operator()(int*) on a temporary DebugDelete object
    DebugDelete()(ip);
    // destroying the object to which p points
    // instantiates DebugDelete::operator()<int>(int *)
    unique_ptr<int, DebugDelete> ip2(new int, DebugDelete());
    // destroying the object to which sp points
    // instantiates DebugDelete::operator()<string>(string*)
    unique_ptr<string, DebugDelete> sp(new string, DebugDelete());
    return 0;
}