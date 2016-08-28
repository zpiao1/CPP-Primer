#include <iostream>
#include <string>
#include <memory>
#include <set>
#include <vector>
class TextQuery {
public:
    class QueryResult;  // nested class to be defined later
    // other members as in § 12.3.2 (p. 487)
};
// We're defining the QueryResult class that is a member of class TextQuery
class TextQuery::QueryResult {
    // in class scope, we don't have to qualify the name of the QueryResult parameters
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    // no need to defind QueryResult::line_no; a nested class can use a member
    // of its enclosing class without needing to qualify the member's name
    QueryResult(std::string, std::shared_ptr<std::set<line_no>>, std::shared_ptr<std::vector<std::string>>);
    // other members as in § 12.3.2 (p. 487)
    static int static_mem;
};
using namespace std;
// defining the member named QueryResult for the class named QueryResult
// that is nested inside the class TextQuery
TextQuery::QueryResult::QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
    sought(s), lines(p), file(f) {}
// defines an int static member of QueryResult
// which is a class nested inside TextQuery
int TextQuery::QueryResult::static_mem = 1024;

// return type must indicate that QueryResult is now a nested class
TextQuery::QueryResult TextQuery::query(const string &sought) const
{
    // we'll return a pointer to this set if we don't find sought
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    // use find and not a subscript to avoid adding words to wm!
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);   // not found
    else
        return QueryResult(sought, loc->second, file);
}
