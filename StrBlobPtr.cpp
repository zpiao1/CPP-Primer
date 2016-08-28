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

std::string &operator[](std::size_t n)
{
    auto p = check(n, "dereference past end");
    return (*p)[n];
}

const std::string &operator[](std::size_t n) const
{
    auto p = check(n, "dereference past end");
    return (*p)[n];
}
// prefix: return a reference to the incremented/decremented object
StrBlobPtr &StrBlobPtr::operator++()
{
    // if curr already points past the end of the container, can't increment it
    check(curr, "increment past end of StrBlobPtr");
    ++curr; // advance the current state
    return *this;
}
StrBlobPtr &StrBlobPtr::operator--()
{
    // if curr is zero, decrementing it will yield an invalid subscript
    --curr; // move the current state back one element
    check(-1, "decrement past begin of StrBlobPtr");
    return *this;
}

// postfix: increment/decrement the object but return the unchanged value
StrBlobPtr StrBlobPtr::operator++(int)
{
    // no check needed here; the call to prefix increment will do the check
    StrBlobPtr ret = *this; // save the current value
    ++*this;    // advance one element; prefix ++ checks the increment
    return ret;
}

StrBlobPtr StrBlobPtr::operator--(int)
{
    // no check needed here; the call to prefix decrement will do the check
    StrBlobPtr ret = *this; // save the current value
    --*this;    // move backward one element; prefix -- checks the decrement
    return ret; // return the saved state
}

StrBlobPtr &StrBlobPtr::operator+=(size_t n)
{
    check(curr + n, "increment pass end of StrBlobPtr");
    curr += n;
    return *this;
}

StrBlobPtr &StrBlobPtr::operator-=(size_t n)
{
    check(curr - n, "decrement pass end of StrBlobPtr");
    curr -= n;
    return *this;
}

StrBlobPtr operator+(const StrBlobPtr &lhs, std::size_t n)
{
    StrBlobPtr ret = lhs;
    ret += n;
    return ret;
}
StrBlobPtr operator-(const StrBlobPtr &lhs, std::size_t n)
{
    StrBlobPtr ret = lhs;
    ret -= n;
    return ret;
}