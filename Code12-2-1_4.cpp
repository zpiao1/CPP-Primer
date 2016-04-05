using namespace std;
int main()
{
    delete p;   // p must point to a dynamically allocated object or be null
    delete [] pa;   // pa must point to a dynamically allocated array or be null;
    typedef int arrT[42];   // arraT names the type array of 42 ints
    int *p = new arrT;  // allocates an array of 42 ints; p points to the first one
    delete [] p;    // brackets are necessary because we allocated an array
    return 0;
}