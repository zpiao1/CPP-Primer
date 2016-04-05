using namespace std;
int main()
{
    // call get_size to determine how many ints to allocate
    int *pia = new int[get_size()]; // pia points to the first of these ints
    typedef int arrT[42];   // arrT names the type array of 42 ints
    int *p = new arrT;  // allocates an array of 42 ints; p points to the first one
    return 0;
}