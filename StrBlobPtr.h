#ifndef _STR_BLOB_PTR_H
#define _STR_BLOB_PTR_H
#include "StrBlob.h"
// StrBlobPtr throws an exception on attempts to access a nonexistent element
class StrBlobPtr;
bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
StrBlobPtr operator+(const StrBlobPtr &lhs, std::size_t n);
StrBlobPtr operator-(const StrBlobPtr &lhs, std::size_t n);
class StrBlobPtr {
    friend bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend bool operator>(const StrBlobPtr &lhs, const StrBlobPtr &rhs);
    friend StrBlobPtr operator+(const StrBlobPtr &lhs, std::size_t n);
    friend StrBlobPtr operator-(const StrBlobPtr &lhs, std::size_t n);
public:
    StrBlobPtr(): curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz);
    std::string &deref() const;
    StrBlobPtr &incr(); // prefix version
    std::string &operator[](std::size_t n);
    const std::string &operator[](std::size_t n) const;
    // increment and decrement
    StrBlobPtr& operator++();   // prefix operators
    StrBlobPtr& operator--();
    // increment and decrement
    StrBlobPtr operator++(int);    // postfix operators
    StrBlobPtr operator--(int);
    StrBlobPtr& operator+=(std::size_t n);
    StrBlobPtr& operator-=(std::size_t n);
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<std::string>> check(std::size_t, const std::string &) const;
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;   // current position within the array
};
#endif