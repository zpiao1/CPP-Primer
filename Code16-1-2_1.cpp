#include "Blob.h"
using namespace std;
int main()
{
    Blob<int> ia;   // empty Blob<int>
    Blob<int> ia2 = {0,1,2,3,4};    // Blob<int> with five elements
    // these definitions instantiate two distinct Blob types
    Blob<string> names; // Blob that holds strings
    Blob<double> prices;    // different element type
    return 0;
}
// compiler instantiates the template to
// template <> class Blob<int> {
// public:
//     typedef typename std::vector<int>::size_type size_type;
//     Blob();
//     Blob(std::initializer_list> il);
//     // ...
//     int& operator[](size_type i);
// private:
//     std::shared_ptr<std::vector<int>> data;
//     void check(size_type i, const std::string &msg) const;
// };