#pragma once
#ifndef	_TEXT_QUERY_H
#define _TEXT_QUERY_H
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
		std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f) { }
	std::set<TextQuery::line_no>::iterator begin() {
		return lines->begin();
	}
	const std::set<TextQuery::line_no>::const_iterator begin() const {
		return lines->cbegin();
	}
	std::set<TextQuery::line_no>::iterator end() {
		return lines->end();
	}
	const std::set<TextQuery::line_no>::const_iterator end() const {
		return lines->cend();
	}
	std::shared_ptr<std::vector<std::string>> get_file() {
		return file;
	}
private:
	std::string sought; // word this query represents
	std::shared_ptr<std::set<TextQuery::line_no>> lines;    // lines it's on
	std::shared_ptr<std::vector<std::string>> file; // input file
};
std::string make_plural(std::set<TextQuery::line_no>::size_type, const std::string &, const std::string &);
#endif