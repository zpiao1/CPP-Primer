#include <string>
#include <memory>
#include <utility>
#include <iostream>
#include <initializer_list>
#include <algorithm>
// simplified implementation of the memory allocation strategy for a vector-like class
class StrVec {
public:
    StrVec():   // the allocator member is default initialized
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec &);             // copy constuctor
    StrVec(std::initializer_list<std::string>);
    StrVec &operator=(const StrVec &);  // copy assignment
    ~StrVec();                          // destructor
    void push_back(const std::string &);    // copy the element
    size_t size() const { return first_free - elements; }
    size_t capacity() const  { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    std::string front() const { return *elements; }
    std::string back() const { return *(first_free - 1); }
    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const std::string &s);
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
using namespace std;
void StrVec::push_back(const string &s)
{
    chk_n_alloc();  // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}
pair<string *, string *> StrVec::alloc_n_copy(const string *b, const string *e)
{
    // allocate space to hold as many elements as are in the range
    auto data = alloc.allocate(e - b);
    // initialize and return a pair constructed from the data and 
    // the value returned by uninitialized_copy
    return {data, uninitialized_copy(b, e, data)};
}
void StrVec::free()
{
    // may not pass deallocated a 0 pointer; if elements is 0, there's no work to do
    if (elements) {
        // destroy the old elements in reverse order
        for_each(elements, first_free, [this](std::string &p){ alloc.destroy(&p); });
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s)
{
    // call alloc_n_copy to allocate exactly as many elements as in s
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec::~StrVec()
{
    free();
}
StrVec::StrVec(initializer_list<string> ils)
{
    auto newdata = alloc_n_copy(ils.begin(), ils.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
StrVec &StrVec::operator=(const StrVec &rhs)
{
    // calls alloc_n_copy to allocate exactly as many elements as in rhs
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::reallocate()
{
    // we'll allocate space for twice as many elements as the current size
    auto newcapacity = size() ? 2 * size() : 1;
    // allocate new memory
    auto newdata = alloc.allocate(newcapacity);
    // move the data from the old memory to the new
    auto dest = newdata;    // points to the next free position in the new array
    auto elem = elements;   // points to the next element in the old array
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));
    free(); // free the old space once we've moved the elements
    // update our data structure to point to the new elements
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n)
{
    if (n > capacity()) {
        auto newcapacity = n;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();

        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }
}

void StrVec::resize(size_t n)
{
    if (n > size()) {
        // need to extend the end
        if (n > capacity())
            reserve(n);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, std::string());
    } else if (n < size()) {
        // need to shrink the vector
        for (size_t i = size(); i != n; i--)
            alloc.destroy(--first_free);
    }
}

void StrVec::resize(size_t n, const string &s)
{
    if (n > size()) {
        // need to extend the end
        if (n > capacity())
            reserve(n);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, s);
    } else if (n < size()) {
        // need to shrink the vector
        for (size_t i = size(); i != n; i--)
            alloc.destroy(--first_free);
    }
}