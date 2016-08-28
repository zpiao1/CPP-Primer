using namespace std;
enum class open_modes {input, output, append};
enum color {red, yellow, green};    // unscoped enumeration
enum stoplight {red, yellow, green};    // error: redefines enumerators
enum class peppers {red, yellow, green};    // ok: enumerators are hidden
enum class intTypes {
    charTyp = 8, shortTyp = 16, intTyp = 16,
    longTyp = 32, long_longTyp = 64
};
enum intValues : unsigned long long {
    charTyp = 255, shortTyp = 65535, intTyp = 65535,
    longTyp = 4294967295UL,
    long_longTyp = 18446744073709551615ULL 
};
int main()
{
    color eyes = green; // ok: enumerators are in scope for an unscoped enumeration
    peppers p = green;  // error: enumerators from peppers are not in scope
                        // color::green is in scope but has the wrong type
    color hair = color::red;    // ok: we can explicitly access the enumerators
    peppers p2 = peppers::red;  // ok: using red from peppers
    constexpr intTypes charbits = intTypes::charTyp;
    open_modes om = 2;  // error: 2 is not of type open_modes
    om = open_modes::input; // ok: input is an enumerator of open_modes
    int i = color::red; // ok: unscoped enumerator implicitly converted to int
    int j = peppers::red;   // error: scoped enumerations are not implicitly converted
    return 0;
}