using namespace std;
template <typename T>
bool compare(const T& v1, const T& v2);
int main()
{
    long lng;
    compare(lng, 1024); // error: template paramters don't match
    compare<long>(lng, 1024);   // ok: instantiates compare(long, long)
    compare<int>(lng, 1024);    // ok: instantiates compare(int, int)
    return 0;
}