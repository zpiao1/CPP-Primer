#include "Exercise_17.3.h"
using namespace std;
TextQuery::TextQuery(ifstream& is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);   // Construct the line using text (a line)
        string word;
        while (line >> word) {
            auto& lines = wm[word]; // lines is a shared_ptr
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new set<line_no>);
            lines->insert(n);   // insert this line number
        }
    }
}

QueryResult TextQuery::query(const string& sought) const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);   // not found
    else
        return QueryResult(sought, loc->second, file);
}

ostream& print(ostream& os, const QueryResult& qr)
{
    auto lines = get<1>(qr);
    os << get<0>(qr) << " occurs " << lines->size() << " " 
       << make_plural(lines->size(), "time", "s") << endl;
    for (auto num : *lines)
        os << "\t(line " << num + 1 << ") "
           << *(get<2>(qr)->begin() + num) << endl;
    return os;
}

string make_plural(set<TextQuery::line_no>::size_type size, const string& base, const 
    string& suffix)
{
    return (size == 1 ? base : base + suffix);
}