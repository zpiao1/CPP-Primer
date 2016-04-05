#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
class QueryResult;  // declaration needed for return type in the query function
std::ostream &print(std::ostream &, const QueryResult&);
class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    // we'll return a pointer to this set if we don't find sought
    static std::shared_ptr<std::set<line_no>> nodata;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // map of each word to the set of lines in which that word appears
    std::map<std::string,
             std::shared_ptr<std::set<line_no>>> wm;
};
class QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<TextQuery::line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
    std::set<TextQuery::line_no>::iterator begin();
    const std::set<TextQuery::line_no>::const_iterator begin() const;
    std::set<TextQuery::line_no>::iterator end();
    const std::set<TextQuery::line_no>::const_iterator end() const;
    std::shared_ptr<std::vector<std::string>> get_file();
private:
    std::string sought; // word this query represents
    std::shared_ptr<std::set<TextQuery::line_no>> lines;    // lines it's on
    std::shared_ptr<std::vector<std::string>> file; // input file
};
std::string make_plural(std::set<TextQuery::line_no>::size_type, const std::string &, const std::string &);

using namespace std;
shared_ptr<set<TextQuery::line_no>> TextQuery::nodata(new set<line_no>);
// read the input file and build the map of lines to line numbers
TextQuery::TextQuery(ifstream &is): file(new vector<string>)
{
    string text;
    while (getline(is, text)) {         // for each line in the file
        file->push_back(text);      // remember this line of text
        int n = file->size() - 1;       // the current line number
        istringstream line(text);       // separate the line into words
        string word;
        while (line >> word) {
            // if word isn't already in wm, subscripting adds a new entry
            auto &lines = wm[word]; // lines is a shared_ptr
            if (!lines) // that pointer is null the first time we see word
                lines.reset(new set<line_no>);  // allocate a new set
            lines->insert(n);   // insert this line number
        }
    }
}

QueryResult TextQuery::query(const string &sought) const
{
    // use find and not a subscript to avoid addign words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);   // not found
    else
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream & os, const QueryResult &qr)
{
    // if the word was found, print the count and all occurrences
    os << qr.sought << " occurs " << qr.lines->size() << " " 
       << make_plural(qr.lines->size(), "time", "s") << endl;
    // print each line in which the word appeared
    for (auto num : *qr.lines)  // for every element in the set
        // don't confound the user with text lines starting at 0
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    return os;
}

string make_plural(set<TextQuery::line_no>::size_type size, const string &base, const string &suffix)
{
    return (size == 1 ? base : base + suffix);
}

set<TextQuery::line_no>::iterator QueryResult::begin()
{
    return lines->begin();
}
const set<TextQuery::line_no>::const_iterator QueryResult::begin() const
{
    return lines->begin();
}
set<TextQuery::line_no>::iterator QueryResult::end()
{
    return lines->end();
}
const set<TextQuery::line_no>::const_iterator QueryResult::end() const
{
    return lines->end();
}
shared_ptr<vector<string>> QueryResult::get_file()
{
    return file;
}