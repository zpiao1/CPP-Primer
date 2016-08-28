using namespace std;
void recoup(int) noexcept;
void alloc(int);
int main()
{
    // both recoup and pf1 promise not to throw
    void (*pf1)(int) noexcept = recoup;
    // ok: recoup won't throw; it doesn't matter that pf2 might
    void (*pf2)(int) = recoup;
    pf1 = alloc;    // error: alloc might throw but pf1 said it wouldn't
    pf2 = alloc;    // ok: both pf2 and alloc might throw
    return 0;
}