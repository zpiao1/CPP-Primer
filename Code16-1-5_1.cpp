#include "Blob.h"
#include <string>
using namespace std;
// instantiation declaration and definition
extern template class Blob<string>;             // declaration
template int compare(const int&, const int&);   // definition