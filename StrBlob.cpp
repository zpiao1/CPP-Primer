#include "StrBlob.h"
using namespace std;
StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob(initializer_list<string> il):
    data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw out_of_range(msg);
}

string &StrBlob::front()
{
    // if the vector is empty, check whill throw
    check(0, "front on empty StrBlob");
    return data->front();
}
string &StrBlob::back()
{
    check(0, "back on empty StrBlob");
    return data->back();
}
void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

const string &StrBlob::front() const
{
    check(0, "front on empty StrBlob");
    return data->front();
}
const string &StrBlob::back() const
{
    check(0, "back on empty StrBlob");
    return data->back();
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs)
{
    return *(lhs.data) == *(rhs.data);
}
bool operator!=(const StrBlob &lhs, const StrBlob &rhs)
{
    return !(lhs == rhs);
}
bool operator<(const StrBlob &lhs, const StrBlob &rhs)
{
    return *(lhs.data) < *(rhs.data);
}
bool operator>(const StrBlob &lhs, const StrBlob &rhs)
{
    return rhs < lhs;
}
bool operator<=(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs < rhs || lhs == rhs;
}
bool operator>=(const StrBlob &lhs, const StrBlob &rhs)
{
    return lhs > rhs || lhs == rhs;
}