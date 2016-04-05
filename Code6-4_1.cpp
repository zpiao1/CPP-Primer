Record lookup(Phone);
Record lookup(const Phone);     // redeclares Record lookup(Phone)

Record lookup(Phone*);
Record lookup(Phone* const);    // redeclares Record lookup(Phone*);

// functions taking const and nonconst references or pointers have different parameters
// declarations for four independent, overloaded functions
Record lookup(Account&);        // function that takes a reference to Account
Record lookup(const Account&);  // new function that takes a const reference
Record lookup(Account*);        // new function, takes a pointer to Account
Record lookup(const Account*);  // new function, takes a pointer to const