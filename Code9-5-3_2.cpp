#include <string>
using namespace std;
int main()
{
  string numbers("0123456789"), name("r2d2");
  // return 1, i.e., the index of the first digit in name
  auto pos = name.find_first_of(numbers);
  string dept("03714p3");
  // return 5, which is the index to the character 'p'
  auto pos = dept.find_first_not_of(numbers);
  return 0;
}