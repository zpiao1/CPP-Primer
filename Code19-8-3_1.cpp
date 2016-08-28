// illustrative linkage directives that might appear in the C++ header <cstring>
// single-statement linkage directive
extern "C" size_t strlen(const char *);
// compound-statement linkage directive
extern "C" {
    int strcmp(const char*, const char*);
    char *strcat(char*, const char*);
}

// compound-statement linkage directive
extern "C" {
#include <string.h> // C functions that manipulate C-stype strings
}

// f1 is a C function; its parameter is a pointer to a C function
extern "C" void f1(void(*)(int));

// FC is a pointer to a C function
extern "C" typedef void FC(int);
// f2 is a C++ function with a paramter that is a pointer to a C function
void f2(FC *);

// the calc function can be called from C programs
extern "C" double calc(double dparm) { /* ... */ }
int main()
{
    // pf points to a C function that returns void and takes an int
    extern "C" void (*pf)(int);
    void (*pf1)(int);   // points to a C++ function
    extern "C" void (*pf2)(int);    // points to a C function
    pf1 = pf2;  // error: pf1 and pf2 have different types
    return 0;
}