using namespace std;
template <typename T>
int compare(const T& a, const T& b)
{
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}
// argument types can differ but must be compatible
template <typename A, typename B>
int flexibleCompare(const A& v1, const B& v2)
{
    if (v1 < v2) return -1;
    if (v1 > v2) return 1;
    return 0;
}
int main()
{
    long lng;
    compare(lng, 1024); // error: cannot instantiate compare(long, int)
    flexibleCompare(lng, 1024); // ok: calls flexibleCompare(long, int)
    return 0;
}