#include <tuple>
#include <string>
using namespace std;
int main()
{
    // tuple that represent a bookstore transaction: ISBN, count, price per book
    auto item = make_tuple("0-999-78345-X", 3, 20.00);
    auto book = get<0>(item);   // returns the first member of item
    auto cnt = get<1>(item);    // returns thr second member of item
    auto price = get<2>(item) / cnt;    // returns the last member of item
    get<2>(item) *= 0.8;    // apply 20% discount
    return 0;
}