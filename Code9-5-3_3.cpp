#include <string>
using namespace std;
int main()
{
  string::size_type pos = 0;
  // each iteratioon finds the next number in name
  while ((pos = nam.find_first_of(numbers, pos)) != string::npos) {
    cout << "found number at index: " << pos
         << " element is " << name[pos] << endl;
    ++pos;  // move to the next character
  }
}