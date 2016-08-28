#include "Blob.h"
#include <string>
#include <utility>
using namespace std;
typedef Blob<string> StrBlob;
template <typename T> using twin = pair<T, T>;
template <typename T> using partNo = pair<T, unsigned>;
class Vehicle;
class Student;
int main()
{
    twin<string> authors;   // authors is a pair<string, string>
    twin<int> win_loss;     // win_loss is a prit<int, int>
    twin<double> area;      // area is a pair<double, double>
    partNo<string> books;   // books is a pair<string, unsigned>
    partNo<Vehicle> cars;   // cars is a pair<Vehicle, unsigned>
    partNo<Student> kids;   // kids is a pair<Student, unsigned>
    return 0;
}