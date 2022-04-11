// @strings @string-implementation

// The standard library provides a string type to complement the string literals.
// It provides a Regular type for owning and manipulating a sequence of characters of various character types.

// The standard string has a move constructor, so returning even long strings by value is efficient.

string compose(const string& name, const string& domain)
{
    // “Addition” of strings means concatenation. You can concatenate a string, a string literal, a C-style string, or a character to a string.
    return name + '@' + domain;
}

// addr is initialized to the character sequence dmr@bell−labs.com.
auto addr = compose("dmr","bell−labs.com");

void m2(string& s1, string& s2)
{
     s1 = s1 + '\n';  // append newline
     s2 += '\n';      // append newline
}

// A string is mutable. In addition to = and +=, subscripting (using [ ]) and substring operations are supported.
string name = "Niels Stroustrup";

void m3()
{
    // The substr() operation returns a string that is a copy of the substring indicated by its arguments. 
    // The first argument is an index into the string (a position), and 
    // the second is the length of the desired substring.
    string s = name.substr(6,10);      // s = "Stroustrup"
    // The replace() operation replaces a substring with a value.
    // Note that the replacement string need not be the same size as the substring that it is replacing.
    name.replace(0,5,"nicholas");      // name becomes "nicholas Stroustrup"
    name[0] = toupper(name[0]);        // name becomes "Nicholas Stroustrup"
}

// strings can be compared against each other, against C-style strings, and against string literals.
string incantation;

void respond(const string& answer)
{
     if (answer == incantation) {
          // perform magic
     }
     else if (answer == "yes") {
          // ...
     }
     // ...
}

// If you need a C-style string (a zero-terminated array of char), string offers read-only access to its contained characters.
void print(const string& s)
{
    printf("For people who like printf: %s\n",s.c_str());     // s.c_str() returns a pointer to s' characters
    cout << "For people who like streams: " << s << '\n';
}

// A string literal is by definition a const char*. To get a literal of type std::string use a s suffix.
// To use the s suffix, you need to use the namespace std::literals::string_literals.
auto s = "Cat"s; // a std::string
auto p = "Dog"; // a C-style string: a const char*

/******************
 * @string-implementation
 ******************/

// These days, string is usually implemented using the short-string optimization. 
// That is, short string values are kept in the string object itself and only longer strings are placed on free store.
// When a string’s value changes from a short to a long string (and vice versa) its representation adjusts appropriately.
// How many characters can a “short” string have? That’s implementation defined, but “about 14 characters” isn’t a bad guess.
string s1 {"Annemarie"};               // short string
string s2 {"Annemarie Stroustrup"};    // long string

// To handle multiple character sets, string is really an alias for a general template basic_string with the character type char:
template<typename Char>
class basic_string {
     // ... string of Char ...
};

using string = basic_string<char>

// A user can define strings of arbitrary character types.
// For example, assuming we have a Japanese character type Jchar, we can write:
using string = basic_string<Jchar>
