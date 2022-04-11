// @I/O @I/O-of-user-defined-types

// In addition to the I/O of built-in types and standard strings, the iostream library allows programmers to define I/O for their own types.
struct Entry {
     string name;
     int number;
};

// A user-defined output operator takes its output stream (by reference) as its first argument and returns it as its result.
ostream& operator<<(ostream& os, const Entry& e)
{
     return os << "{\"" << e.name << "\", " << e.number << "}";
}

// The corresponding input operator is more complicated because it has to check for correct formatting and deal with errors:
// An input operation returns a reference to its istream that can be used to test if the operation succeeded.
istream& operator>>(istream& is, Entry& e)
     // read { "name", number } pair. Note: formatted with { " ", and }
{
     char c, c2;
     // when used as a condition, is>>c means “Did we succeed at reading a char from is into c?”
     if (is>>c && c=='{' && is>>c2 && c2=='"') { // start with a { "
         string name;                   // the default value of a string is the empty string: ""
        // The is>>c skips whitespace by default, but is.get(c) does not, 
        // so this Entry-input operator ignores (skips) whitespace outside the name string, but not within it.
        while (is.get(c) && c!='"')    // anything before a " is part of the name
            name+=c;

        if (is>>c && c==',') {
            int number = 0;
            if (is>>number>>c && c=='}') { // read the number and a }
                e = {name,number};      // assign to the entry
                    return is;
            }
        }
     }
     is.setstate(ios_base::failbit);      // register the failure in the stream
     return is;
}

// We can read such a pair of values from input into an Entry like this:
for (Entryee; cin>>ee; )  // read from cin into ee
    cout << ee << '\n'; // write ee to cout

// Input
// { "John Marwood Cleese", 123456      }
// {"Michael Edward Palin", 987654}

// Output
// {"John Marwood Cleese", 123456}
// {"Michael Edward Palin", 987654}
