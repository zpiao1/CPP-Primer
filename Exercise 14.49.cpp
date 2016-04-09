#include <iostream>
#include <string>
using namespace std;
class Book;
istream &operator>>(istream &is, Book &b);
ostream &operator<<(ostream &os, const Book &b);
bool operator==(const Book &lhs, const Book &rhs);
bool operator!=(const Book &lhs, const Book &rhs);
class Book {
    friend istream &operator>>(istream &is, Book &b);
    friend ostream &operator<<(ostream &os, const Book &b);
    friend bool operator==(const Book &lhs, const Book &rhs);
    friend bool operator!=(const Book &lhs, const Book &rhs);
private:
    std::string name = "N/A";
    std::string author = "N/A";
    std::string date = "N/A";
    std::string publisher = "N/A";
public:
    Book() = default;
    Book(const std::string bookName):
        name(bookName), author("N/A"), date("N/A"), publisher("N/A") {}
    Book(const std::string bookName, const std::string bookAuthor):
        name(bookName), author(bookAuthor), date("N/A"), publisher("N/A") {}
    Book(const std::string bookName, const std::string bookAuthor, const std::string publishDate, const std::string Publisher):
        name(bookName), author(bookAuthor), date(publishDate), publisher(Publisher) {}
    Book(const Book &bk):
        name(bk.name), author(bk.author), date(bk.date), publisher(bk.publisher) {}
    Book &operator=(const Book &rhs);
    explicit operator bool() const {
        return name != "N/A" && author != "N/A" && date != "N/A" && publisher != "N/A";
    }
};
ostream &operator<<(ostream &os, const Book &b)
{
    os << b.name << ' ' << b.author << ' ' << b.date << ' ' << b.publisher;
    return os;
}
istream &operator>>(istream &is, Book &b)
{
    is >> b.name >> b.author >> b.date >> b.publisher;
    if (!is)
        b = Book();
    return is;
}

bool operator==(const Book &lhs, const Book &rhs)
{
    return lhs.name == rhs.name &&
           lhs.author == rhs.author &&
           lhs.date == rhs.date &&
           lhs.publisher == rhs.publisher;
}
bool operator!=(const Book &lhs, const Book &rhs)
{
    return !(lhs == rhs);
}

Book &Book::operator=(const Book &rhs)
{
    name = rhs.name;
    author = rhs.author;
    date = rhs.date;
    publisher = rhs.publisher;
    return *this;
}
