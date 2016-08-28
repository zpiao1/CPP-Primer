#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
class DebugDelete {
public:
    DebugDelete(std::ostream &s = std::cerr): os(s) {}
    template <typename T> void operator()(T* p) const
    {
        os << "deleting shared_ptr" << std::endl;
        delete p;
    }
private:
    std::ostream &os;
};

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    class QueryResult;
    TextQuery(std::ifstream&);
    QueryResult query(const std::string&) const;
private:
    std::shared_ptr<std::vector<std::string>> file; // input file
    // map of each word to the set of lines in which that word appears
    std::map<std::string,
             std::shared_ptr<std::set<line_no>>> wm;
};
class TextQuery::QueryResult {
    friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(std::string s,
                std::shared_ptr<std::set<line_no>> p,
                std::shared_ptr<std::vector<std::string>> f):
        sought(s), lines(p), file(f) { }
private:
    std::string sought; // word this query represents
    std::shared_ptr<std::set<line_no>> lines;    // lines it's on
    std::shared_ptr<std::vector<std::string>> file; // input file
};
std::string make_plural(std::set<TextQuery::line_no>::size_type, const std::string &, const std::string &);
#endif