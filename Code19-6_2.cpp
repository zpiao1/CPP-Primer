#include <string>
#include "Sales_data.h"
#include <functional>

class Token {
public:
    // copy control needed because our class has a union with a string member
    // definition the move constructor and move-assignment operator is left as an exercise
    Token(): tok(INT), ival(0) {}
    Token(const Token &t): tok(t.tok) { copyUnion(t); }
    Token &operator=(const Token&);
    // if the union holdes a string, we must destroy it; see § 19.1.2 (p. 824)
    ~Token()
    {
        if (tok == STR) sval.std::string::~string();
        else if (tok == SD) sdval.~Sales_data();
    }
    // assignment operators to set the differing members of the union
    Token &operator=(const std::string&);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);
    Token &operator=(const Sales_data&);

    // move operations
    Token(Token&& t) noexcept: tok(std::move(t.tok)) { moveUnion(std::move(t)); }
    Token &operator=(Token&&) noexcept;
    Token &operator=(std::string&&) noexcept;
    Token &operator=(double&&) noexcept;
    Token &operator=(char&&) noexcept;
    Token &operator=(int&&) noexcept;
    Token &operator=(Sales_data&&) noexcept;
private:
    enum {INT, CHAR, DBL, STR, SD} tok; // discriminant
    union {                         // anonymous union
        char cval;
        int ival;
        double dval;
        std::string sval;
        Sales_data sdval;
    };  // each Token object has an unnamed member of this unnamed union type
    // check the discriminant and copy the union member as appropriate
    void copyUnion(const Token&);
    void moveUnion(Token&&) noexcept;
};

using std::string;

Token &Token::operator=(char c)
{
    if (tok == STR) sval.~string();
    else if (tok == SD) sdval.~Sales_data();
    cval = c;
    tok = CHAR;
    return *this;

}

Token &Token::operator=(int i)
{
    if (tok == STR) sval.~string(); // if we have a string, free it
    else if (tok == SD) sdval.~Sales_data();
    ival = i;   // assign to the appropriate member
    tok = INT;
    return *this;
}

Token &Token::operator=(double d)
{
    if (tok == STR) sval.~string(); // if we have a string, free it
    else if (tok == SD) sdval.~Sales_data();
    dval = d;
    tok = DBL;
    return *this;
}

Token &Token::operator=(const std::string &s)
{
    if (tok == STR) // if we already hold a string, just do an assignment
        sval = s;
    else {
        if (tok == SD)
            sdval.~Sales_data();
        new(&sval) string(s);   // otherwise construct a string
    }
    tok = STR;  // update the discriminant
    return *this;
}

Token &Token::operator=(const Sales_data &sd)
{
    if (tok == SD)
        sdval = sd;
    else {
        if (tok == STR)
            sval.~string();
        new(&sdval) Sales_data(sd);
    }
    return *this;
}

void Token::copyUnion(const Token &t)
{
    switch (t.tok) {
        case Token::INT: ival = t.ival; break;
        case Token::CHAR: cval = t.cval; break;
        case Token::DBL: dval = t.dval; break;
        // to copy a string, construct it using placement new; see (§ 19.1.2 (p. 824))
        case Token::STR: new(&sval) string(t.sval); break;
        case Token::SD: new(&sdval) Sales_data(t.sdval); break;
    }
}

Token &Token::operator=(const Token &t)
{
    // if this object holds a string and t doesn't, we have to free the old string
    if (tok == STR && t.tok != STR) sval.~string();
    else if (tok == SD && t.tok != SD) sdval.~Sales_data();
    if (tok == STR && t.tok == STR)
        sval = t.sval;  // no need to construct a new string
    else if (tok == SD && t.tok == SD)
        sdval = t.sdval;
    else
        copyUnion(t);   // will construct a string if t.tok is STR
    tok = t.tok;
    return *this;
}

Token &Token::operator=(char&& c) noexcept
{
    if (tok == STR) sval.~string();
    else if (tok == SD) sdval.~Sales_data();
    cval = std::move(c);
    tok = CHAR;
    return *this;
}

Token &Token::operator=(int&& i) noexcept
{
    if (tok == STR) sval.~string();
    else if (tok == SD) sdval.~Sales_data();
    ival = std::move(i);
    tok = INT;
    return *this;
}

Token &Token::operator=(double&& d) noexcept
{
    if (tok == STR) sval.~string();
    else if (tok == SD) sdval.~Sales_data();
    dval = std::move(d);
    tok = DBL;
    return *this;
}

Token &Token::operator=(std::string&& s) noexcept
{
    if (tok == STR)
        sval = std::move(s);
    else {
        if (tok == SD)
            sdval.~Sales_data();
        new(&sval) string(std::move(s));
    }
    tok = STR;
    return *this;
}

Token &Token::operator=(Sales_data &&sd) noexcept
{
    if (tok == SD)
        sdval = std::move(sd);
    else {
        if (tok == STR)
            sval.~string();
        new(&sdval) Sales_data(std::move(sd));
    }
    tok = SD;
    return *this;
}

void Token::moveUnion(Token&& t) noexcept
{
    switch (t.tok) {
        case Token::INT: ival = std::move(t.ival); break;
        case Token::CHAR: cval = std::move(t.cval); break;
        case Token::DBL: dval = std::move(t.dval); break;
        case Token::STR: new(&sval) string(std::move(t.sval)); break;
        case Token::SD: new(&sdval) Sales_data(std::move(t.sdval)); break;
    }
}

Token& Token::operator=(Token&& t) noexcept
{
    if (this != &t) {
        if (tok == STR && t.tok != STR)
            sval.~string();
        else if (tok == SD && t.tok != SD)
            sdval.~Sales_data();
        if (tok == STR && t.tok == STR)
            sval = std::move(t.sval);
        else if (tok == SD && t.tok == SD)
            sdval = std::move(t.sdval);
        else
            moveUnion(std::move(t));
        tok = std::move(t.tok);
    }
    return *this;
}