#include "StrVec.h"
using namespace std;
void StrVec::push_back(const string &s)
{
    chk_n_alloc();  // ensure that there is room for another element
    // construct a copy of s in the element to which first_free points
    alloc.construct(first_free++, s);
}
void StrVec::push_back(string &&s)
{
    chk_n_alloc();  // reallocates the StrVec if necessary
    alloc.construct(first_free++, std::move(s));
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
        for (auto p = first_free; p != elements; /*empty */)
            alloc.destroy(--p);
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
    /* Copying the memory
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
    cap = elements + newcapacity; */
    // Moving the memory
    // allocate space for twice as many elements as the current size
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    // move the elements
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free(); // free the old space
    elements = first;   // update the pointers
    first_free = last;
    cap = elements + newcapacity;
}

StrVec::StrVec(StrVec &&s) noexcept // move won't throw any exceptions
// member initializers take over the resources in s
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    // leave s in a state in which it is safe to run the destructor
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec &StrVec::operator=(StrVec &&rhs) noexcept
{
    // direct test for self-assignment
    if (this != &rhs) {
        free();                     // free existing elements
        elements = rhs.elements;    // take over resources from rhs
        first_free = rhs.first_free;
        cap = rhs.cap;
        // leave rhs in a destructible state
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    else {
        auto iter1 = lhs.begin();
        auto iter2 = rhs.begin();
        while (iter1 != lhs.begin() && iter2 != rhs.begin()) {
            if (*iter1 != *iter2)
                return false;
            iter1++;
            iter2++;
        }
        return true;
    }
}
bool operator!=(const StrVec &lhs, const StrVec &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs)
{
    if (!rhs.size())
        return false;
    else if (!lhs.size())
        return true;
    else {
        auto iter1 = lhs.begin();
        auto iter2 = rhs.begin();
        while (iter1 != lhs.end() && iter2 != rhs.end()) {
            if (*iter1 < *iter2)
                return true;
            else if (*iter1 > *iter2)
                return false;
            iter1++;
            iter2++;
        }
        return false;
    }
}

bool operator>(const StrVec &lhs, const StrVec &rhs)
{
    if (!lhs.size())
        return false;
    else if (!rhs.size())
        return true;
    else {
        auto iter1 = lhs.begin();
        auto iter2 = rhs.begin();
        while (iter1 != lhs.end() && iter2 != rhs.end()) {
            if (*iter1 > *iter2)
                return true;
            else if (*iter1 < *iter2)
                return false;
            iter1++;
            iter2++;
        }
        return false;
    }
}

bool operator<=(const StrVec &lhs, const StrVec &rhs)
{
    return lhs < rhs || lhs == rhs;
}

bool operator>=(const StrVec &lhs, const StrVec &rhs)
{
    return lhs > rhs || lhs == rhs;
}

StrVec &StrVec::operator=(initializer_list<string> il)
{
    // alloc_n_copy allocates space and copies elements from the given range
    auto data = alloc_n_copy(il.begin(), il.end());
    free(); // destroy the elements in this object and free the space
    elements = data.first;  // update data members to point to the new space
    first_free = cap = data.second;
    return *this;
}