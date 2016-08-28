#ifndef _VECTOR_H
#define _VECTOR_H
#include <memory>
#include <utility>
#include <initializer_list>
class Vector;
template <typename T> bool operator==(const Vector<T>&, const Vector<T>&);
template <typename T> bool operator!=(const Vector<T>&, const Vector<T>&);
template <typename T> bool operator<(const Vector<T>&, const Vector<T>&);
template <typename T> bool operator>(const Vector<T>&, const Vector<T>&);
template <typename T> bool operator>=(const Vector<T>&, const Vector<T>&);
template <typename T> bool operator<=(const Vector<T>&, const Vector<T>&);
template <typename T>
class Vector {
public:
    Vector():
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    Vector(const Vector&);
    Vector &operator=(const Vector&);
    Vector(Vector&&) noexcept;
    Vector(std::initializer_list<T>);
    Vector& operator=(Vector&&) noexcept;
    Vector& operator=(std::initializer_list<T>);
    ~Vector();
    T& operator[](std::size_t n) { return elements[n]; }
    const T& operator[](std::size_t n) const { return elements[n]; }
    void push_back(const T&);
    void push_back(T&&);
    std::size_t size() const { return first_free - elements; }
    std::size_t capacity() const { return cap - elements; }
    T*       begin()        { return elements; }
    const T* begin() const  { return elements; }
    const T* cbegin() const { return elements; }
    T*       end()          { return first_free; }
    const T* end() const    { return first_free; }
    const T* cend() const   { return first_free; }
    T&       front()        { return *elements; }
    const T& front() const  { return *elements; }
    T&       back()         { return *(first_free - 1); }
    const T& back() const   { return *(first_free - 1); }
    template <typename Args...>
    void emplace_back(Args&&... args) {
        chk_n_alloc();
        alloc.construct(first_free++, std::forward<Args>(args)...);
    }
private:
    std::allocator<T> alloc;
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    T* elements;
    T* first_free;
    T* cap;
};
template <typename T>
void Vector<T>::push_back(const T& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}
template <typename T>
void Vector<T>::push_back(T&& s)
{
    chk_n_alloc();
    alloc.construct(first_free++, std::move(s));
}
template <typename T>
std::pair<T*, T*> Vector<T>::alloc_n_copy(const T* b, const T* e)
{
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}
template <typename T>
void Vector<T>::free()
{
    if (elements) {
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}
template <typename T>
Vector<T>::Vector(const Vector& s)
{
    auto newdata = alloc_n_copy(s.begin(), s.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}
template <typename T>
Vector<T>::~Vector()
{
    free();
}
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector& rhs)
{
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}
template <typename T>
void Vector<T>::reallocate() 
{
    auto newcapacity = size() ? 2 * size() : 1;
    auto first = alloc.allocate(newcapacity);
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}
template <typename T>
Vector<T>::Vector(Vector&& s) noexcept
    : elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}
template <typename T>
Vector<T>& Vector<T>::operator=(Vector&& rhs) noexcept
{
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}
template <typename T>
Vector<T>::Vector(std::initializer_list<T> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    element = data.first();
    first_free = cap = data.second;
}
template <typename T>
Vector<T>& Vector<T>::operator=(std::initializer_list<T> il)
{
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first();
    first_free = cap = data.second;
    return *this;
}
template <typename T>
bool operator==(const Vector<T>& lhs, const Vector<T>& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    else {
        auto iter1 = lhs.begin();
        auto iter2 = rhs.begin();
        while (iter1 != lhs.end() && iter2 != rhs.end()) {
            if (*iter1 != *iter2)
                return false;
            ++iter1;
            ++iter2;
        }
        return true;
    }
}
template <typename T>
bool operator!=(const Vector<T>& lhs, const Vector<T>& rhs)
{
    return !(lhs == rhs);
}
template <typename T>
bool operator<(const Vector<T>& lhs, const Vector<T>& rhs)
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
            ++iter1;
            ++iter2;
        }
        return false;
    }
}
template <typename T>
bool operator>(const Vector<T>& lhs, const Vector<T>& rhs)
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
            ++iter1;
            ++iter2;
        }
        return false;
    }
}
template <typename T>
bool operator<=(const Vector<T>& lhs, const Vector<T>& rhs)
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
            ++iter1;
            ++iter2;
        }
        return true;
    }
}
template <typename T>
bool operator>=(const Vector<T>& lhs, const Vector<T>& rhs)
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
            ++iter1;
            ++iter2;
        }
        return true;
    }
}
#endif