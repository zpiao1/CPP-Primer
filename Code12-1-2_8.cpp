using namespace std;
int main()
{
    int *p(new int (42));   // p points to a dynamic memory
    auto q = p; // p and q point to the same memory
    delete p;   // invalidates both p and q
    p = nullptr;    // indicates that p is no longer bound to an object
    return 0;
}