#include <iostream>
#include <iterator>
using namespace std;
int main()
{
    constexpr size_t rowCnt = 3, colCnt = 4;
    int ia[rowCnt][colCnt];
    for (size_t i = 0; i != rowCnt; ++i)
        for (size_t j = 0; j != colCnt; ++j)
            ia[i][j] = i * colCnt + j;

    for (int row[colCnt] : ia) {
        for (int col : row) 
            cout << col << ' ';
        cout << endl;
    }

    for (size_t i = 0; i != rowCnt; ++i) {
        for (size_t j = 0; j != colCnt; ++j)
            cout << col << ' ';
        cout << endl;
    }

    for (int (*prow)[4] = ia; prow != ia + rowCnt; ++prow) {
        for (int *pcol = *prow; pcol != *prow + colCnt; ++pcol)
            cout << *pcol << endl;
        cout << endl;
    }
    return 0;
}