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
    Book(const std::string bookName, const std::string bookAuthor, const std::string publishDate, const std::string Publisher):
        name(bookName), author(bookAuthor), date(publishDate), publisher(Publisher) {}
    Book(): Book("N/A", "N/A", "N/A", "N/A") {}
    Book(const std::string bookName):
        Book(bookName, "N/A", "N/A", "N/A") {}
    Book(const std::string bookName, const std::string bookAuthor):
        Book(bookName, bookAuthor, "N/A", "N/A") {}
}