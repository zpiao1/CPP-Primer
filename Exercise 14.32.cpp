#include "StrBlobPtr"
using namespace std;
class StrBlobPtrPtr {
private:
    StrBlobPtr *p;
public:
    StrBlobPtr():
        p(nullptr) {}
    StrBlobPtr *operator->() const
    {
        return p;
    }
}