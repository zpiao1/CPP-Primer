class Screen {
public:
    // bkground refers to the static member
    // declared later in the class definition
    Screen &clear(char = bkground);
private:
    static const char bkground;
};