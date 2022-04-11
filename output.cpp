// @I/O @output

// In <ostream>, the I/O stream library defines output for every built-in type.
// The operator << (“put to”) is used as an output operator on objects of type ostream;
// cout is the standard output stream and cerr is the standard stream for reporting errors.
// By default, values written to cout are converted to a sequence of characters.
// Output of different types can be combined in the obvious way
// The result of an output expression can itself be used for further output.
// A character constant is a character enclosed in single quotes. 
// Note that a character is output as a character rather than as a numerical value.
void k()
{
    int b = 'b';     // note: char implicitly converted to int
    char c = 'c';
    cout << 'a' << b << c;
}
// The integer value of the character 'b' is 98 (in the ASCII encoding used on the C++ implementation that I used), 
// so this will output a98c.
