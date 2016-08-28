#include <functional>
class Delete {
public:
    template <typename T>
    void operator()(T* p) const { delete p; }
};

template <typename T> class shared_pointer;
template <typename T> void swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs);
template <typename T>
class shared_pointer {
    friend void swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs);
public:
    // constructors
    shared_pointer(): 
        ptr(nullptr), ref_count(new std::size_t(1)), deleter(Delete()) {}
    explicit shared_pointer(T* raw_ptr):
        ptr(raw_ptr), ref_count(new std::size_t(1)), deleter(Delete()) {}
    shared_pointer(const shared_pointer& sp):
        ptr(sp.ptr), ref_count(sp.ref_count), deleter(sp.deleter) 
    { ++*ref_count; }
    shared_pointer(shared_pointer&& sp) noexcept:
        ptr(sp.ptr), ref_count(sp.ref_count), deleter(std::move(sp.deleter))
    {
        sp.deleter = nullptr;
        sp.ref_count = nullptr;
    }
    
    // assignment operators
    shared_pointer& operator=(const shared_pointer& rhs)
    {
        // increment first to ensure safety for self-assignment
        ++*rhs.ref_count;
        free();
        ptr = rhs.ptr;
        ref_count = rhs.ref_count;
        deleter = rhs.deleter;
        return *this;
    }
    shared_pointer& operator=(shared_pointer&& rhs) noexcept
    {
        swap(*this, rhs);
        rhs.free();
        return *this;
    }
    
    // conversion operator
    operator bool() const { return ptr ? true : false; }
    // dereference
    T& operator*() const { return *ptr; }
    // arrow
    T* operator->() const { return &*ptr; }
    
    // other members
    std::size_t use_count() const { return *ref_count; }
    T* get() const { return ptr; }
    bool unique() const { return *ref_count == 1; }
    void swap(shared_pointer& rhs) { swap(*this, rhs); }
    
    // reset
    void reset() { free(); }
    void reset(T* pointer)
    {
        if (ptr != pointer) {
            free();
            ptr = pointer;
            ref_count = new std::size_t(1);
        }
    }
    void reset(T* pointer, const std::function<void(T*)>& d)
    {
        reset(pointer);
        deleter = d;
    }
    
    // destructor
    ~shared_pointer() { free(); }
private:
    T* ptr;
    // common reference count for all shared_pointer<T> objects
    std::size_t* ref_count; 
    // a function object
    std::function<void(T*)> deleter;
    // important auxilary function
    void free()
    {
        if (--*ref_count == 0) {
            delete ref_count;
            if (ptr)
                deleter(ptr);
        }
        ref_count = ptr = nullptr;
    }
};

template <typename T>
swap(shared_pointer<T>& lhs, shared_pointer<T>& rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.ref_count, rhs.ref_count);
    swap(lhs.deleter, rhs.deleter);
}

////////////////////////////////////////////////////////////////////////////////

template <typename T, typename D> class unique_pointer;
template <typename T, typename D>
void swap(unique_pointer<T, D>& lhs, unique_pointer<T, D>& rhs);
template <typename T, typename D = Delete>
class unique_pointer {
    friend void swap(unique_pointer<T, D>& lhs, unique_pointer<T, D>& rhs);
public:
    // constructors, preventing copy constructor
    unique_pointer() = default;
    explicit unique_pointer(T* raw_ptr): ptr(raw_ptr) {}
    unique_pointer(const unique_pointer&) = delete;
    unique_pointer(unique_pointer&& up) noexcept:
        ptr(up.ptr)
    { up.ptr = nullptr; }
    
    // assignment operators, preventing copy assignment
    unique_pointer& operator=(const unique_pointer&) = delete;
    unique_pointer& operator=(unique_pointer&& rhs) noexcept
    {
        // prevent self-assignment
        if (ptr != rhs.ptr) {
            deleter(ptr);
            ptr = nullptr;
            swap(*this, rhs);
        }
        return *this;
    }
    // nullptr_t assignment
    unique_pointer& operator=(std::nullptr_t n) noexcept
    {
        // assign unique_pointer to nullptr
        if (n == nullptr) {
            deleter(ptr);
            ptr = nullptr;
        }
        // else do nothing
        return *this;
    }
    
    // conversion operator
    operator bool() const { return ptr ? true : false; }
    T& operator*() const { return *ptr; }
    T* operator->() const { return &*ptr; }
    
    // other members
    T* get() const noexcept { return ptr; }
    void swap(unique_ptr& rhs) { swap(*this, rhs); }
    
    // reset
    void reset() noexcept
    {
        deleter(ptr);
        ptr = nullptr;
    }
    void reset(T* p) noexcept
    {
        deleter(ptr);
        ptr = p;
    }
    
    // return ptr and make ptr point to nullptr
    T* release() 
    {
        T* ret = ptr;
        ptr = nullptr;
        return ret;
    }
    
    // destructor
    ~unique_pointer() { deleter(ptr); }
private:
    T* ptr = nullptr;
    D deleter = D();
};

template <typename T, typename D>
inline void swap(unique_pointer<T, D>& lhs, unique_pointer<T, D>& rhs)
{
    using std::swap;
    swap(lhs.ptr, rhs.ptr);
    swap(lhs.deleter, rhs.deleter);
}