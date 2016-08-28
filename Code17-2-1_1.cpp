#include <bitset>
#include <string>
using namespace std;

int main()
{
    bitset<32> bitvec(1U);  // 32 bits; low-order bit is 1, remaining bits are 0
    // bitvec1 is smaller than the initializer; high-order bits from the initializer are discareded
    bitset<13> bitvec1(0xbeef); // bits are 1111011101111
    // bitvec2 is larger than the initializer; high-order bits in bitvec2 are set to zero
    bitset<20> bitvec2(0xbeef); // bits are 00001011111011101111
    // on machines with 64-bit long long 0ULL is 64 bits of 0, so ~0ULL is 64 one
    bitset<128> bitvec3(~0ULL); // bits 0 ... 63 are one; 63 ... 127 are zero
    bitset<32> bitvec4("1100"); // bits 2 and 3 are 1, all others are 0
    string str("1111111000000011001101");
    bitset<32> bitvec5(str, 5, 4);  // four bits starting at str[5], 1100
    bitset<32> bitvec6(str, str.size() - 4);    // use last four characters
    return 0;
}