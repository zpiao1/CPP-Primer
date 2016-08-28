#include <string>
class Screen {
public:
    typedef std::string::size_type pos;
    using char (Screen::*)() const = CharVoidConst;
    using char (Screen::*)(pos, pos) const = CharPosPosConst;
    char get_cursor() const { return contents[cursor]; }
    char get() const;
    char get(pos ht, pos wd) const;
private:
    std::string contents;
    pos cursor;
    pos height, width;
};