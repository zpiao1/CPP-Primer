#include "StrVec.h"
using namespace std;

int main()
{
    StrVec svec;
    svec.emplace_back(10, 'c'); // adds cccccccccc as a new last element
    // the call to construct will become 
    // std::forward<int>(10), std::forward<char>('c');
    return 0;
}