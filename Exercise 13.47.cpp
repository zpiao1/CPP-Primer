#include <memory>
#include <utility>
#include <iostream>
#include <algorithm>
class String;
std::ostream &print(std::ostream &os, const String &);
class String {
    friend std::ostream &print(std::ostream &os, const String &);
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
    size_t size() { return first_free - elements; }
    size_t capacity() { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }
    char &front() const { return *elements; }
    char &back() const { return *(first_free - 1); }
    void reserve(size_t n);
    void resize(size_t n, const char &c);
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
    std::cout << "String::String(const String &s)" << std::endl;
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
    std::cout << "String &String::operator=(const String &rhs)" << std::endl;
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
using namespace std;
int main()
{
    String s1("Hello");
    print(cout, s1) << endl;
    cout << s1.size() << ' ' << s1.capacity() << endl;
    String s2(s1);
    print(cout, s2) << endl;
    cout << s2.size() << ' ' << s2.capacity() << endl;
    String s3;
    s3 = s1;
    print(cout, s3) << endl;
    cout << s3.size() << ' ' << s3.capacity() << endl;
    s1.reserve(15);
    print(cout, s1) << endl;
    cout << s1.size() << ' ' << s1.capacity() << endl;
    s1.resize(18, 'a');
    print(cout, s1) << endl;
    cout << s1.size() << ' ' << s1.capacity() << endl;
    s1.resize(13);
    print(cout, s1) << endl;
    cout << s1.size() << ' ' << s1.capacity() << endl;
    return 0;
}