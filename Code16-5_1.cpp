#include <string>
#include <cstring>
using namespace std;
// first version; can compare any two types
template <typename T> int compare(const T&, const T&);
// special version of compare to handle pointers to character arrays
template <>
int compare(const char* const &p1, const char* const& p2)
{
    return strcmp(p1, p2);
}
// second version to handle string literals
template <size_t N, size_t M>
int compare(const char (&)[N], const char (&)[M]);

int main()
{
    const char *p1 = "hi", *p2 = "mom";
    compare(p1, p2);    // calls the first template
    compare("hi", "mom");   // calls the template with two nontype parameters
}