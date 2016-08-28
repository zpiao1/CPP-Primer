#include <bitset>
#include <iostream>
using namespace std;
template <size_t N>
class Quiz {
public:
    Quiz(): bitvec() {}
    Quiz(const char* str): bitvec(str) {}
    void grade(const Quiz& correct);
    void update(size_t i, bool ans) {
        bitvec.set(bitvec.size() - i + 1, ans);
    }
private:
    bitset<N> bitvec;
};

template <size_t N>
void Quiz<N>::grade(const Quiz& correct)
{
    for (size_t i = 0; i != N; i++) {
        cout << "Question " << i + 1 << ": ";
        bitvec[i] == correct.bitvec[i] ? cout << "Correct" : cout << "Incorrect";
        cout << endl;
    }
}

int main()
{
    Quiz<5> q;
    Quiz<5> correct("01101");
    q.update(2, true);
    q.update(4, true);
    q.grade(correct);
    return 0;
}