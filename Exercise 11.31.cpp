#include <iostream>
#include <map>
#include <string>
using namespace std;
int main()
{
    multimap<string, string> authors = {
        {"J.K. Rowling", "Harry Potter I"},
        {"J.K. Rowling", "Harry Potter II"},
        {"J.K. Rowling", "Harry Potter III"},
        {"J.K. Rowling", "Harry Potter IV"},
        {"J.K. Rowling", "Harry Potter V"}};
    string author1 = "J.K. Rowling", author2 = "Stephen Hawking";
    auto iter = authors.find(author1);
    if (iter != authors.end()) {
        authors.erase(iter);
        cout << "Erased successfully!" << endl;
    } else 
        cout << "The element does not exist!" << endl;
    cout << "No of items remaining: " << authors.size() << endl;
    iter = authors.find(author2);
    if (iter != authors.end()) {
        authors.erase(iter);
        cout << "Erased successfully!" << endl;
    } else 
        cout << "The element does not exist!" << endl;
    return 0;
}