#ifndef _BLOB_PTR_H
#define _BLOB_PTR_H
#include "Blob.h"
// BlobPtr throws an exception on attempts to access a nonexistent element
template <typename T> class BlobPtr {
public:
    BlobPtr(): curr(0) {}
    // BlobPtr(Blob<T> &a, size_t sz = 0):
    //     wptr(a.data), curr(sz) {}
    BlobPtr(Blob<T>& a, size_t sz = 0) try :
        wptr(a.data), curr(sz) {
    } catch(const exception& e) { }
    T &operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];  // (*p) is the vector to which this object points
    }
    // increment and decrement
    BlobPtr& operator++();  // prefix operators
    BlobPtr& operator--();
    // equivalent to
    // BlobPtr<T>& operator++();
    // BlobPtr<T>& operator--();
    BlobPtr& operator++(int);   // postfix operators
    BlobPtr& operator--(int);
private:
    // check returns a shared_ptr to the vector if the check succeeds
    std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
    // store a weak_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;   // current position within the array
};
template <typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret)
        throw std::runtime_error("unbound BlobPtr");
    if (i >= ret->size())   // if i is negative, i is a very large positive number and larger than ret->size())
        throw std::out_of_range(msg);
    return ret;
}
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator++()
{
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}
template <typename T>
BlobPtr<T>& BlobPtr<T>::operator--()
{
    --curr;
    check(-1, "decrement past begin of BlobPtr");
    return *this;
}
// postfix: increment/decrement the object but return the unchanged value
template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int)
{
    // no check needed here; the call to prefix increment will do the check
    BlobPtr ret = *this;    // save the current value
    // equivalent to
    // BlobPtr<T> ret = *this;
    ++*this;    // advance one element; prefix ++ checks the increment
    return ret; // return the saved state
}
template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int)
{
    BlobPtr ret = *this;
    --*this;
    return ret;
}
#endif