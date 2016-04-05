#include <memory>
#include <utility>
#include <iostream>
#include <algorithm>
class String;
std::ostream &print(std::ostream &os, const String &s);
std::ostream &operator<<(std::ostream &os, const String &s);
bool operator==(const String &lhs, const String &rhs);
bool operator!=(const String &lhs, const String &rhs);
bool operator<(const String &lhs, const String &rhs);
bool operator>(const String &lhs, const String &rhs);
bool operator<=(const String &lhs, const String &rhs);
bool operator>=(const String &lhs, const String &rhs);
class String {
    friend std::ostream &print(std::ostream &os, const String &s);
    friend std::ostream &operator<<(std::ostream &os, const String &s);
    friend bool operator==(const String &lhs, const String &rhs);
    friend bool operator!=(const String &lhs, const String &rhs);
    friend bool operator<(const String &lhs, const String &rhs);
    friend bool operator>(const String &lhs, const String &rhs);
    friend bool operator<=(const String &lhs, const String &rhs);
    friend bool operator>=(const String &lhs, const String &rhs);
private:
    char *elements;
    char *first_free;
    char *cap;
    std::allocator<char> alloc;
    void check_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    std::pair<char *, char *> alloc_n_copy(const char *, const char *);
    void free();
    void reallocate();
    size_t c_strlen(const char *);
public:
    String():
        elements(nullptr), first_free(nullptr), cap(nullptr) {}
    String(const String &);
    String(const char *);
    String &operator=(const String &);
    String &operator=(const char *);
    ~String();
    void push_back(const char &c);
    void pop_back();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }
    char &front() const { return *elements; }
    char &back() const { return *(first_free - 1); }
    void reserve(size_t n);
    void resize(size_t n, const char &c);
    String(String &&) noexcept;  // move constructor
    String &operator=(String &&) noexcept;   // move assignment operator
    char &operator[](std::size_t n) {
        return elements[n];
    }
    const char &operator[](std::size_t n) const {
        return elements[n];
    }
};

std::pair<char *, char *> String::alloc_n_copy(const char *b, const char *e) 
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free()
{
    if (elements) {
        for (auto p = elements; p != first_free; ++p)
            alloc.destroy(p);
        alloc.deallocate(elements, cap - elements);
    }
}

void String::reallocate()
{
    size_t newcapacity = (size() ? 2 * size() : 1);
    auto newelem = alloc.allocate(newcapacity);
    auto newfirst_free = newelem;
    auto elem = elements;
    for (size_t i = 0; i < size(); ++i)
        alloc.construct(newfirst_free++, std::move(*elem++));
    free();
    elements = newelem;
    first_free = newfirst_free;
    cap = elements + newcapacity;
}

size_t String::c_strlen(const char *c_str)
{
    size_t len = 0;
    while (c_str[len])
        len++;
    return len;
}

String::String(const String &s)
{
    auto pairptr = alloc_n_copy(s.begin(), s.end());
    elements = pairptr.first;
    first_free = cap = pairptr.second;
}

String::String(const char *c_str)
{
    size_t len = c_strlen(c_str);
    auto pairptr = alloc_n_copy(c_str, c_str + len);
    elements = pairptr.first;
    first_free = cap = pairptr.second;
}

String &String::operator=(const String &rhs)
{
    auto pairptr = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = pairptr.first;
    first_free = cap = pairptr.second;
    return *this;
}

String &String::operator=(const char *rhs)
{
    size_t len = c_strlen(rhs);
    auto pairptr = alloc_n_copy(rhs, rhs + len);
    free();
    elements = pairptr.first;
    first_free = cap = pairptr.second;
    return *this;
}

String::~String()
{
    free();
}

void String::push_back(const char &c)
{
    check_n_alloc();
    alloc.construct(first_free++, c);
}

void String::pop_back()
{
    alloc.destroy(--first_free);
}

void String::reserve(size_t n)
{
    if (n > capacity()) {
        auto newcapacity = n;
        auto newelem = alloc.allocate(newcapacity);
        auto newfirst_free = newelem;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(newfirst_free++, std::move(*elem++));
        free();
        elements = newelem;
        first_free = newfirst_free;
        cap = elements + newcapacity;
    }
}
void String::resize(size_t n, const char &c = '\0')
{
    if (n > size()) {
        if (n > capacity())
            reserve(n);
        for (size_t i = size(); i != n; ++i)
            alloc.construct(first_free++, c);
    } else if (n < size())
        for (size_t i = size(); i != n; i--)
            alloc.destroy(--first_free);
}

std::ostream &print(std::ostream &os, const String &s)
{
    for (auto iter = s.begin(); iter != s.end() && *iter; ++iter)
        os << *iter;
    return os;
}
String::String(String &&s) noexcept:
    elements(s.elements), first_free(s.first_free), cap(s.cap)
{
    s.elements = s.first_free = s.cap = nullptr;
}
String& String::operator=(String &&rhs) noexcept
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
std::ostream &operator<<(std::ostream &os, const String &s)
{
    for (auto iter = s.begin(); iter != s.end() && *iter; ++iter)
        os << *iter;
    return os;
}
bool operator==(const String &lhs, const String &rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    else {
        auto iter1 = lhs.begin();
        auto iter2 = rhs.begin();
        while (iter1 != lhs.end() && iter2 != rhs.end()) {
            if (*iter1 != *iter2)
                return false;
            iter1++;
            iter2++;
        }
        return true;
    }
}
bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}

bool operator<(const String &lhs, const String &rhs)
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

bool operator>(const String &lhs, const String &rhs)
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

bool operator>=(const String &lhs, const String &rhs)
{
    return lhs > rhs || lhs == rhs;
}
bool operator<=(const String &lhs, const String &rhs)
{
    return lhs < rhs || lhs == rhs;
}
using namespace std;
int main()
{
    String s1("Hello");
    String s2, s5;
    String s3 = "Helo";
    String s4 = "Hello";
    cout << (s2 < s5) << endl;
    cout << (s3 < s5) << endl;
    cout << (s1 > s2) << endl;
    cout << (s4 >= s1) << endl;
    cout << (s4 <= s1) << endl;
    cout << (s3 < s4) << endl;
    cout << (s4 > s3) << endl;

    return 0;
}