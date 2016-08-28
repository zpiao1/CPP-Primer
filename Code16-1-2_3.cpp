#include "Blob.h"
using namespace std;
int main()
{
    // instantiates Blob<int> and the initializer_list<int> constructor
    Blob<int> squares = {1,2,3,4,5,6,7,8,9};
    // instantiates Blob<int>::size() const
    for (size_t i = 0; i != squares.size(); ++i)
        squares[i] = i * i; // instantiates Blob<int>::operator[](size_t)
    return 0;
}