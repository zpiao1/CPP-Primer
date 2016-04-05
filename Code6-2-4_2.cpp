#include <iostream>
#include <iterator>
using namespace std;
void print(const char *cp)
{
    if (cp)         // if cp is not a null pointer
        while (*cp) // so long as the character it points to is not a null character
            cout << *cp++;  // print the character and advance the pointer
}
void print(const int *beg, const int *end)
{
    // print every element starting at beg up to but not including end
    while (beg != end)
        cout << *beg++ << endl; // print the current element
                                // and advance the pointer
}
// const int ia[] is equivalent to const int* ia
// size is passed explicitly and used to control access to elements of ia
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i) {
        cout << ia[i] << endl;
    }
}
int main()
{
    int j[2] = {0, 1};
    // j is converted to a pointer to the first element in j
    // the second argument is a pointer to one past the end of j
    print(begin(j), end(j));    // begin and end functions, see § 3.5.3 (p. 118)
    print(j, end(j) - begin(j));
    return 0;
}