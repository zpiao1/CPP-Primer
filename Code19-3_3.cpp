using namespace std;
// forward declaration of unscoped enum named intValues
enum intValues : unsigned long long;    // unscoped, must specify a type
enum class open_modes;  // scoped enums can use int by default
// error: declarations and definition must agree whether the enum is scoped or unscoped
enum class intValues;
enum intValues; // error: intValues previously declared as scoped enum
enum intValues : long;  // error: intValues previously declared as int
// unscoped enumeration; the underlying type is machine dependent
enum Tokens {INLINE = 128, VIRTUAL = 129};
void ff(Tokens);
void ff(int);
void newf(unsigned char);
void newf(int);

int main() {
    Tokens curTok = INLINE;
    ff(128);    // exactly matches ff(int)
    ff(INLINE); // exactly matches ff(Tokens)
    ff(curTok); // exactly matches ff(Tokens)
    unsigned char uc = VIRTUAL;
    newf(VIRTUAL);  // calls newf(int)
    newf(uc);   // calls newf(unsigned char);
    return 0;
}