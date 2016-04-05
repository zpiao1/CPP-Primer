#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <utility>
#include <initializer_list>
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
        if (n > capacity()) {
            auto newcapacity = n;
            auto newdata = alloc.allocate(newcapacity);
            auto dest = newdata;
            auto elem = elements;
            // copy the original copy
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            for (size_t i = size(); i != n; ++i)
                alloc.construct(dest++, std::string());
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        } else {
            for (size_t i = size(); i != n; ++i)
                alloc.construct(first_free++, std::string());
        }
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
        if (n > capacity()) {
            auto newcapacity = n;
            auto newdata = alloc.allocate(newcapacity);
            auto dest = newdata;
            auto elem = elements;
            // copy the original copy
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            for (size_t i = size(); i != n; ++i)
                alloc.construct(dest++, s);
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + newcapacity;
        } else {
            for (size_t i = size(); i != n; ++i)
                alloc.construct(first_free++, s);
        }
    } else if (n < size()) {
        // need to shrink the vector
        for (size_t i = size(); i != n; i--)
            alloc.destroy(--first_free);
    }
}

class QueryResult;  // declaration needed for return type in the query function
std::ostream &print(std::ostream &, const QueryResult&);
class TextQuery {
public:
    using line_no = size_t;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<StrVec> file; // input file
    // map of each word to the set of lines in which that word appears
    std::map<std::string,
             std::shared_ptr<std::set<line_no>>> wm;
};
class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<StrVec> f):
        sought(s), lines(p), file(f) { }
private:
    std::string sought; // word this query represents
    std::shared_ptr<std::set<TextQuery::line_no>> lines;    // lines it's on
    std::shared_ptr<StrVec> file; // input file
};
std::string make_plural(std::set<TextQuery::line_no>::size_type, const std::string &, const std::string &);
using namespace std;
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is): file(new StrVec)
{
    string text;
    while (getline(is, text)) {         // for each line in the file
        file->push_back(text);      // remember this line of text
        int n = file->size() - 1;       // the current line number
        istringstream line(text);       // separate the line into words
        string word;
        while (line >> word) {
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word]; // lines is a shared_ptr
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new set<line_no>);  // allocate a new set
            lines->insert(n);   // insert this line number
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // use find and not a subscript to avoid addign words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);   // not found
    else
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " " 
       << make_plural(qr.lines->size(), "time", "s") << endl;
    // print each line in which the word appeared
    for (auto num : *qr.lines)  // for every element in the set
        // don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    return os;
}

string make_plural(set<TextQuery::line_no>::size_type size, const string &base, const string &suffix)
{
    return (size == 1 ? base : base + suffix);
}

int main()
{
    ifstream ifs("text.txt");
    TextQuery tq(ifs);
    string s("will");
    print(cout, tq.query(s));
    return 0;
}