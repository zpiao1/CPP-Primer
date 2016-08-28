using namespace std;
template <class T = int> class Numbers {    // by default T is int
public:
    Numbers(T v = 0): val(v) {}
    // various operations on numbers
private:
    T val;
};
int main()
{
    Numbers<long double> lots_of_precision;
    Numbers<> average_precision;    // empty <> says we want the default
    return 0;
}