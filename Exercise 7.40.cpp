#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    std::string name("N/A");
    std::string author("N/A");
    std::string date("N/A");
    std::string publisher("N/A");
public:
    Book() = default;
    Book(const std::string bookName):
        name(bookName), author("N/A"), date("N/A"), publisher("N/A") {}
    Book(const std::string bookName, const std::string bookAuthor):
        name(bookName), author(bookAuthor), date("N/A"), publisher("N/A") {}
    Book(const std::string bookName, const std::string bookAuthor, const std::string publishDate, const std::string Publisher):
        name(bookName), author(bookAuthor), date(publishDate), publisher(Publisher) {}
}