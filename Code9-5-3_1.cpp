#include <string>
using namespace std;
int main()
{
  string name("AnnaBelle");
  auto pos1 = name.find("Anna");  // pos1 == 0
  string lowercase("annabelle");
  pos1 = name.find("Anna");       // pos1 == npos
  return 0;
}