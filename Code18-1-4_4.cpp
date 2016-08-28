using namespace std;
void recoup(int) noexcept(true);    // recoup won't throw
void alloc(int) noexcept(false);    // alloc can throw
int main()
{
    noexcept(recoup(i));    // true if calling recoup can't throw, false otherwise
}