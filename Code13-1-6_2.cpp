using namespace std;
struct NoDtor {
    NoDtor() = default; // use the synthesized default constructor
    ~NoDtor() = delete; // we can't destroy objects of type NoDtor
};
int main()
{
    NoDtor nd;  // error: NoDtor destructor is deleted
    NoDtor *p = new NoDtor();   // ok: but we can't delete p
    delete p;   // error: NoDtor destructor is deleted
    return 0;
}