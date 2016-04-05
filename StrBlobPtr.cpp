#include "StrBlobPtr.h"
StrBlobPtr::StrBlobPtr(StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock(); // is the vector still around?
    if (!ret)
        throw std::runtime_error("unbound StrBlobPtr");
    if (i >= ret->size())
        throw std::out_of_range(msg);
    return ret; // otherwise, return a shared_ptr to the vector
}
std::string &StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];  // (*p) is the vector to which this object points
}
// prefix: return a reference to the incremented object
StrBlobPtr &StrBlobPtr::incr()
{
    // it curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr;     // advance the current state
    return *this;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return *(lhs.wptr) == *(rhs.wptr) &&
           lhs.curr == rhs.curr;
}
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    if (*(lhs.wptr) != *(rhs.wptr))
        return *(lhs.wptr) < *(rhs.wptr);
    else
        return lhs.curr < rhs.curr;
}

bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
    if (*(lhs.wptr) != *(rhs.wptr))
        return *(lhs.wptr) > *(rhs.wptr);
    else
        return lhs.curr > rhs.curr;
}