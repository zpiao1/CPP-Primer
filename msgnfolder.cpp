#include "msgnfolder.h"
using namespace std;
void Message::save(Folder &f)
{
    addFld(&f); // add the given Folder to our list of Folders
    f.addMsg(this);     // add this Message to f's set of Messages
}
void Message::remove(Folder &f)
{
    remFld(&f);  // take the given Folder out of our list of Folders
    f.remMsg(this);     // remove this Message to f's set of Messages
}
// add this Message to Folders that point to m
void Message::add_to_Folders(const Message &m)
{
    for (auto f : m.folders)    // for each Folder that holds m
        f->addMsg(this);        // add a pointer to this Message to that Folder
}
Message::Message(const Message &m):
    contents(m.contents), folders(m.folders)
{
    add_to_Folders(m);
}
// remove this Message from the corresponding Folders
void Message::remove_from_Folders()
{
    for (auto f : folders)  // for each pointer in folders
        f->remMsg(this);    // remove this Message from that Folder
}
Message::~Message()
{
    remove_from_Folders();
}
Message &Message::operator=(const Message &rhs)
{
    // handle self-assignment by removing pointers before inserting them
    remove_from_Folders();      // update existing Folders
    contents = rhs.contents;    // copy message contents from rhs
    folders = rhs.folders;      // copy Folder pointers from rhs
    add_to_Folders(rhs);        // add this Message to those Folders
    return *this;
}
void swap(Message &lhs, Message &rhs)
{
    using std::swap;    // not strictly needed in this case, but good habit
    // remove pointers to each Message from their (original) respective Folders
    for (auto f : lhs.folders)
        f->remMsg(&lhs);
    for (auto f : rhs.folders)
        f->remMsg(&rhs);
    // swap the contents and Folder pointer sets
    swap(lhs.folders, rhs.folders);     // uses swap(set &, set &);
    swap(lhs.contents, rhs.contents);   // swap(string &, string &);
    // add pointers to each Message to their (new) respective Folders
    for (auto f : lhs.folders)
        f->addMsg(&lhs);
    for (auto f : rhs.folders)
        f->addMsg(&rhs);
}
void Folder::add_to_Messages(const Folder &f)
{
    for (auto m : f.messages)
        m->addFld(this);
}
void Folder::remove_from_Messages()
{
    for (auto m : messages)
        m->remFld(this);
}
Folder::Folder(const Folder &f):
    messages(f.messages)
{
    add_to_Messages(f);
}
Folder::~Folder()
{
    remove_from_Messages();
}
Folder &Folder::operator=(const Folder &rhs)
{
    remove_from_Messages();

    messages = rhs.messages;
    add_to_Messages(rhs);

    return *this;
}
void swap(Folder &lhs, Folder &rhs)
{
    using std::swap;
    for (auto m : lhs.messages)
        m->remFld(&lhs);
    for (auto m : rhs.messages)
        m->remFld(&rhs);

    swap(lhs.messages, rhs.messages);

    for (auto m : lhs.messages)
        m->addFld(&lhs);
    for (auto m : rhs.messages)
        m->addFld(&rhs);
}

void Message::addFld(Folder *ptrF)
{
    folders.insert(ptrF);
}
void Message::remFld(Folder *ptrF)
{
    folders.erase(ptrF);
}

void Folder::addMsg(Message *ptrM)
{
    messages.insert(ptrM);
}
void Folder::remMsg(Message *ptrM)
{
    messages.erase(ptrM);
}

// move the Folder pointers from m to this Message
void Message::move_Folders(Message *m)
{
    folders = std::move(m->folders);    // uses set move assignment
    for (auto f : folders) {    // for each Folder
        f->remMsg(m);   // remove the old Message from the Folder
        f->addMsg(this);    // add this Message to that Folder
    }
    m->folders.clear(); // ensure that destroying m is harmless
}
Message::Message(Message &&m):
    contents(std::move(m.contents))
{
    move_Folders(&m);   // moves folders and updates the Folder pointers
}
Message& Message::operator=(Message &&rhs)
{
    if (this != &rhs) { // direct check for self-assignment
        remove_from_Folders();
        contents = std::move(rhs.contents); // move assignment
        move_Folders(&rhs); // reset the Folders to point to this Message
    }
    return *this;
}