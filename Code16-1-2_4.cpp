#include "Blob.h"
#include "BlobPtr.h"
using namespace std;
int main()
{
    Blob<char> ca;  // BlobPtr<char> and operator==<char> are friends
    Blob<int> ia;   // BlobPtr<int> and operator==<int> are friends
    return 0;
}