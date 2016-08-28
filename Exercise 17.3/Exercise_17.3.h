#ifndef EXERCISE_17_3_H
#define EXERCISE_17_3_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <memory>
#include <tuple>

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;
    using query_result = std::tuple<std::string, 
                                   std::shared_ptr<std::set<line_no>>,
                                   std::shared_ptr<std::vector<std::string>>>;
    TextQuery(std::ifstream&);
    query_result query(const std::string&) 
               const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

using QueryResult = TextQuery::query_result;

std::ostream& print(std::ostream&, const QueryResult&);
std::string make_plural(std::set<TextQuery::line_no>::size_type, const std::string&, 
                        const std::string&);
#endif  // EXERCISE_17_3_H