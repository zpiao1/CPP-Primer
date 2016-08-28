#ifndef _STR_VEC_H
#define _STR_VEC_H
#include <string>
#include <memory>
#include <utility>
#include <initializer_list>
#include <functional>
#include <new>
#include <cstdlib>
void *operator new(size_t);
void operator delete(void*);
// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec;
bool operator==(const StrVec &lhs, const StrVec &rhs);
bool operator!=(const StrVec &lhs, const StrVec &rhs);
bool operator<(const StrVec &lhs, const StrVec &rhs);
bool operator>(const StrVec &lhs, const StrVec &rhs);
bool operator<=(const StrVec &lhs, const StrVec &rhs);
bool operator>=(const StrVec &lhs, const StrVec &rhs);
class StrVec {
    friend bool operator==(const StrVec &lhs, const StrVec &rhs);
    friend bool operator!=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>(const StrVec &lhs, const StrVec &rhs);
    friend bool operator<=(const StrVec &lhs, const StrVec &rhs);
    friend bool operator>=(const StrVec &lhs, const StrVec &rhs);
public:
    StrVec():   // the allocator member is default initialized
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);             // copy constuctor
    StrVec &operator=(const StrVec &);  // copy assignment
    ~StrVec();                          // destructor
    void push_back(const std::string &);    // copy the element
    void push_back(std::string &&);         // move the element
    size_t size() const { return first_free - elements; }
    size_t capacity() const  { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    StrVec(StrVec &&s) noexcept;
    StrVec& operator=(StrVec &&rhs) noexcept;
    StrVec& operator=(std::initializer_list<std::string>);
    std::string &operator[](std::size_t n) {
        return elements[n];
    }
    const std::string &operator[](std::size_t n) const {
        return elements[n];
    }
    template <class... Args> void emplace_back(Args&&...);
    // ...
private:
    std::allocator<std::string> alloc;  // alloates the elements
    // used by the functions that add elements to the StrVec
    void chk_n_alloc() 
        { if (size() == capacity()) reallocate(); }
    // utilities used by copy constructor, assignment operator, and destructor
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string *, const std::string *);
    void free();    // destroy the elements and free the space
    void reallocate();  // get more space and copy the existing elements
    std::string *elements;      // pointer to the first element in the array
    std::string *first_free;    // pointer to the first free element in the array
    std::string *cap;           // pointer to one past the end of the array
};
#endif