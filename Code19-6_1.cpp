// objects of type Token have a single member, which could be of any of the listed types
union Token {
// members are public by default
    char cval;
    int ival;
    double dval;
};
union { // anonymous union
    char cval;
    int ival;
    double dval;
};  // defines a unnamed object, whose members we can access directly
int main()
{
    Token first_token = {'a'};  // initializes the cval member
    Token last_token;   // uninitialized Token object
    Token *pt = new Token;  // pointer to an uninitialized Token object
    last_token.cval = 'z';
    pt->ival = 42;
    cval = 'c'; // assigns a new value to the unnamed, anonymous union object
    ival = 42;  // that object now holds the value 42
    return 0;
}