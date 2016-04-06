using namespace std;
struct absInt {
    int operator()(int val) const {
        return val < 0 ? -val : val;
    }
};

int main()
{
    int i = -42;
    absInt absObj;  // object that has a function-call operator
    int ui = absObj(i); // passes i to absObj.operator()
    return 0;
}