#pragma once
#ifndef _QUERY_BASE_H
#define _QUERY_BASE_H
#include "TextQuery.h"
#include <algorithm>
#include <iterator>
// abstract class acts as a base class for concrete query types; all members are private
class Query_base {
	friend class Query;
protected:
	using line_no = TextQuery::line_no;	// used in the eval functions
	virtual ~Query_base() = default;
private:
	// eval returns the QueryResult that matches this Query
	virtual QueryResult eval(const TextQuery&) const = 0;
	// rep is a string representation of the query
	virtual std::string rep() const = 0;
};
// interface class to manage the Query_base inheritance hierarchy
class Query {
	// these operators need access to the shared_ptr constructor
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);	// binds a new WordQuery
	// interface functions: call the corresponding Query_base operations
	QueryResult eval(const TextQuery &t) const {
		return q->eval(t);
	}
	std::string rep() const {
		return q->rep();
	}
private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};
class WordQuery : public Query_base {
	friend class Query;	// Query uses the WordQuery constructor
	WordQuery(const std::string &s) : query_word(s) {}
	// concrete class: WordQuery defines all inherited pure virtual functions
	QueryResult eval(const TextQuery &t) const override {
		return t.query(query_word);
	}
	std::string rep() const override {
		return query_word;
	}
	std::string query_word;	// word for which to search
};
inline Query::Query(const std::string &s) : q(new WordQuery(s)) {}
class NotQuery : public Query_base {
	friend Query operator~(const Query &);
	NotQuery(const Query &q) : query(q) {}
	// concrete class: Not Query defines all inherited pure virtual functions
	std::string rep() const override {
		return "~(" + query.rep() + ")";
	}
	QueryResult eval(const TextQuery &) const override;
	Query query;
};
inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));	// automatic type conversion
	// can be disabled by making the constructor explicit
	// allocate a new NotQuery object
	// bind the resulting NotQuery pointer to a shared_ptr<Query_base>
	// shared_ptr<Query_base> tmp(new NotQuery(operand));
	// return Query(tmp);	// use the Query constructor that takes a shared_ptr
}
class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
		lhs(l), rhs(r), opSym(s) {}
	// abstract class: BinaryQuery doesn't define eval
	std::string rep() const override {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;	// right- and left-hand operands
	std::string opSym;	// name of the operator
};
class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "&") {}
	// concrete class: AndQuery inherits rep and defines the remaining pure virtual
	QueryResult eval(const TextQuery&) const override;
};
inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
}
class OrQuery : public BinaryQuery {
	friend Query operator|(const Query &, const Query&);
	OrQuery(const Query &left, const Query &right) :
		BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
};
inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}
#endif // !_QUERY_BASE_H
