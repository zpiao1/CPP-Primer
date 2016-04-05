#include <iostream>
using namespace std;
int main()
{
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];     // 12 uninitialized elements
    // for each row
    for (size_t i = 0; i != rowCnt; ++i) {
        // for each column within the row
        for (size_t j = 0; j != colCnt; ++j) {
            // assign the elements' positional index as its value
            ia[i][j] = i * colCnt + j;
        }
    }
    size_t cnt = 0;
    for (auto &row : ia)        // for every element in the outer array
        for (auto &col : row) { // for every element in the inner array
            col = cnt;          // give the element the next value;
            ++cnt;              // increment cnt
        }
    for (const auto &row : ia)  // for every element in the outer array
        for (auto col : row)    // for every element in the inner array
            cout << col << endl;
    int ia[3][4];           // array of size3; each element is an array of int of size 4
    int (*p)[4] = ia;       // p points to an array of four ints
    p = &ia[2];             // p now points to the last element in ia
    // print the value of each element in ia, with each inner array on its own line
    // p points to an array of four ins
    for (auto p = ia; p != ia + 3; ++p) {
        // q points to the first element of an array of four ints; that is, q points to an int
        for (auto q = *p; q != *p + 4; ++q)
            cout << *q << ' ';
        cout << endl;
    }
    using int_array = int[4];   // new style type alias declaration; see § 2.5.1 (p. 68)
    typedef int int_array[4];   // equivalent typedef declaration; § 2.5.1 (p. 67)
    // print the value of each element in ia, with each inner array on its own line
    for (int_array *p = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) 
            cout << *q << ' ';
        cout << endl;
    }
    return 0;
}