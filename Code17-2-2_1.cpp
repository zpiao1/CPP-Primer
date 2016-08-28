#include <bitset>
using namespace std;
int main()
{
    bitset<32> bitvec(1U);  // 32 bits; low-order bit is 1, remaining bits are 0
    bool is_set = bitvec.any();         // true, one bit is set
    bool is_not_set = bitvec.none();    // false, one bit is set
    bool all_set = bitvec.all();        // false, only one bit is set
    size_t onBits = bitvec.count();     // return 1
    size_t sz = bitvec.size();          // return 32
    bitvec.flip();                      // reverses the value of all the bits in bitvec
    bitvec.reset();                     // sets all the bits to 0
    bitvec.set();                       // sets all the bits to 1

    bitvec.flip(0);                     // reverses the value of the first bit
    bitvec.set(bitvec.size() - 1);      // turns on the last bit
    bitvec.set(0, 0);                   // turns off the first bit
    bitvec.reset(i);                    // turns off the ith bit
    bitvec.test(0);                     // returns false because the first bit is off

    bitvec[0] = 0;                      // turn off the bit at position 0
    bitvec[31] = bitvec[0];             // set the last bit to the same value as the first bit
    bitvec[0].flip();                   // flip the value of the bit at position 0
    ~bitvec[0];                         // equivalent operation; flips the bit at position 0
    bool b = bitvec[0];                 // convert the value of bitvec[0] to bool
    return 0;
}