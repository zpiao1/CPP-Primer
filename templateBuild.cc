#include "Blob.h"
#include <string>
using namespace std;
// templateBuild.cc
// instantiation file must provide a (nonextern) definition for every
// type and function that other files declare as extern
template int compare(const int&, const int&);
template class Blob<string>;    // instantiates all members of class template