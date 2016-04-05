class Account {
public:
    static double rate() {
        return interestRate;
    }
    static void rate(double);
private:
    static constexpr int period = 30;   // period is a constant expression
    double daily_tbl[period];
};
// definition of a static member with no initializer
constexpr int Account::period;  // initializer provided in the class definition