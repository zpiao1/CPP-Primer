using namespace std;
int main()
{
    size_t n = get_size();  // get_size returns the number of elements needed
    int *p = new int[n];    // allocate an array to hold the elements
    for (int *q = p; q != p + n; ++q)
        /* process the array */ ;
    char arr[0];    // error: cannot define a zero-length array
    char *cp = new char[0]; // ok: but cp can't be deferenced
    return 0;
}