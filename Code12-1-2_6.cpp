using namespace std;
int main()
{
    delete p;   // p must point to a dynamically allocated object or be null
    int i, *pi1 = &i, *pi2 = nullptr;
    double *pd = new double(33), *pd2 = pd;
    delete i;   // error: i is not a pointer
    delete pi1; // undefined: pi1 refers to a local
    delete pd;  // ok
    delete pd2; // undefined: the memory pointed to by pd2 was already freed
    delete pi2; // ok: it is always ok to delete a null pointer
    const int *pci = new const int(1024);
    delete pci; // ok: deletes a const object
    return 0;
}