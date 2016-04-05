#include <string>
class Account {
public:
    void calculate()
    {
        amount += amount *= interestRate;
    }
    static double rate() 
    {
        return interestRate;
    }
    static void rate(double);
private:
    std::string owner;
    double amount;
    static double interestRate;
    static double initRate();
};

double r;
r = Account::rate();    // access a static member using the scope operator
Account ac1;
Account *ac2 = &ac1;
// equivalent ways to call the static member rate function
r = ac1.rate();     // through an Account object or reference
r = ac2->rate();    // through a pointer to an Account object

void Account::rate(double newRate)
{
    interestRate = newRate;
}
// define and initialize a static class member
double Account::interestRate = initRate();