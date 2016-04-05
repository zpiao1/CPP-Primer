#ifndef _CHAPTER6_H_
#define _CHAPTER6_H_
#include <string>
#include <initializer_list>
#include <vector>
using namespace std;
int fact_interact(int num);
int abs_val(int num);
void gen_nums(void);
void swap_int(int *a, int *b);
void swap_ref(int &a, int &b);
bool containCaps(const string &s);
void strToLower(string &s);
int larger(int a, const int *pb);
void swap_ptrs(int *(&pa), int *(&pb));
int sum_list(initializer_list<int> il);
void printVec(const vector<int> &, const vector<int>::iterator &);
string (&func1(void))[10];
typedef string arrS[10];
using arrS2 = string [10];
arrS &func2(void);
arrS2 &func3(void);
auto func4(void) -> string [10];
string arr[10];
decltype(arr) *func5(void);
auto arrRef(int i) -> int (&)[5];
string make_plural(size_t ctr, const string &word, const string &ending = "s");
inline bool isShorter(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
void f();
void f(int);
void f(int, int);
void f(double, double = 3.14);
#endif