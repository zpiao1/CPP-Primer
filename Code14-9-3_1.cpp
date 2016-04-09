using namespace std;
class SmallInt {
    friend SmallInt operator+(const SmallInt&, const SmallInt&);
public:
    SmallInt(int = 0);  // conversion from int
    operator int() const { return val; }    // conversion to int
private:
    std::size_t val;
};
int main()
{
    SmallInt s1, s2;
    SmallInt s3 = s1 + s2;  // uses overloaded operator+
    int i = s3 + 0;         // error: ambiguous
    return 0;
}