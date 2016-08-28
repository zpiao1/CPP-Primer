#ifndef _BLOB_H
#define _BLOB_H
#include <memory>
#include <vector>
#include <initializer_list>
#include <string>
#include <stdexcept>
#include <exception>
// forward declarations needed for friend declarations in Blob
template <typename> class BlobPtr;
template <typename> class Blob; // needed for paramenters in operator==
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);
template <typename T> class Blob {
    // each instantiation of Blob grants access to the version of
    // BlobPtr and the equality operator instantiated with the same type
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef T value_type;
    typedef typename std::vector<T>::size_type size_type;
    // constructors
    Blob();
    Blob(std::initializer_list<T> il);
    template <typename It> Blob(It b, It e);
    // number of elements in the Blob
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    // add and remove elements
    void push_back(const T &t) { data->push_back(t); }
    // move version; see § 13.6.3 (p. 548)
    void push_back(T &&t) { data->push_back(std::move(t)); }
    void pop_back();
    // element access
    T& back();
    T& operator[](size_type i); // defined in § 14.5 (p. 566)
    T& front();
    // const overloads
    const T& back() const;
    const T& operator[](size_type i) const;
    const T& front() const;
private:
    std::shared_ptr<std::vector<T>> data;
    // throws msg if data[i] isn't valid
    void check(size_type i,const std::string &msg) const;
};

template <typename T>
Blob<T>::Blob(): data(std::make_shared<std::vector<T>>()) {}

// template <typename T>
// Blob<T>::Blob(std::initializer_list<T> il):
//     data(std::make_shared<std::vector<T>>(il)) {}
template <typename T>
Blob<T>::Blob(std::initializer_list<T> il) try :
    data(std::make_shared<std::vector<T>>(il)) {
        /* empty body */
} catch(const std::bad_alloc &e) { handle_out_of_memory(e); }

template <typename T>   // type paramenter for the class
template <typename It>  // type paramenter for the constructor
Blob<T>::Blob(It b, It e):
    data(std::make_shared<std::vector<T>>(b, e)) {}

template <typename T>
void Blob<T>::check(size_type i, const std::string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

template <typename T>
void Blob<T>::pop_back()
{
    check(0, "pop_back on empty Blob");
    data->pop_back();
}

template <typename T>
T &Blob<T>::back()
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
T &Blob<T>::operator[](size_type i)
{
    check(i, "subscript out of range");
    return (*data)[n];
}

template <typename T>
T &Blob<T>::front()
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
const T &Blob<T>::back() const
{
    check(0, "back on empty Blob");
    return data->back();
}

template <typename T>
const T &Blob<T>::operator[](size_type i) const
{
    check(i, "subscript out of range");
    return (*data)[n];
}

template <typename T>
const T &Blob<T>::front() const
{
    check(0, "front on empty Blob");
    return data->front();
}

template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs)
{
    return lhs->data == rhs->data;
}
#endif