#ifndef _MSG_N_FOLDER_H
#define _MSG_N_FOLDER_H
#include <string>
#include <set>
class Message;
class Folder;
void swap(Message &lhs, Message &rhs);
void swap(Folder &lhs, Folder &rhs);
class Message {
    friend class Folder;
    friend void swap(Message &lhs, Message &rhs);
    friend void swap(Folder &lhs, Folder &rhs);
public:
    // folders is implicitly initialized to the empty set
    explicit Message(const std::string &str = ""):
        contents(str) {}
    // copy control to manage pointers to this Message
    Message(const Message&);            // copy constructor
    Message& operator=(const Message&); // copy assignment
    ~Message();                         // destructor
    // add/remove this Message from the specified Folder's set of messages
    void save(Folder &);
    void remove(Folder &);
    Message(Message &&m);
    Message& operator=(Message &&);
private:
    std::string contents;               // actual message text
    std::set<Folder *> folders;         // Folders that have this Message
    // utility functions used by copy constructor, assignment, and destructor
    // add this Message to the Folders that point to the parameter
    void add_to_Folders(const Message &);
    // remove this Message from every Folder in folders;
    void remove_from_Folders();
    void addFld(Folder *);
    void remFld(Folder *);
    void move_Folders(Message *m);
};

class Folder {
    friend class Message;
    friend void swap(Folder &lhs, Folder &rhs);
    friend void swap(Message &lhs, Message &rhs);
public:
    Folder() = default;
    Folder(const Folder &);
    Folder &operator=(const Folder &);
    ~Folder();
private:
    std::set<Message *> messages;
    void add_to_Messages(const Folder &);
    void remove_from_Messages();
    void addMsg(Message *);
    void remMsg(Message *);
};
#endif