// @I/O @input

// istreams take care of memory management and range checking.
// We can do formatting to and from memory using stringsteams.

// The standard strings have the nice property of expanding to hold what you put in them; you don’t have to pre-calculate a maximum size.

// The operator >> (“get from”) is used as an input operator; cin is the standard input stream.
// The type of the right-hand operand of >> determines what input is accepted and what is the target of the input operation.
// Like output operations, input operations can be chained
// By default, >> skips initial whitespace,
// By default, a whitespace character, such as a space or a newline, terminates the read
// You can read a whole line using the getline() function.
void hello_line()
{
    cout << "Please enter your name\n";
    string str;
    getline(cin,str);
    cout << "Hello, " << str << "!\n";
}
// With this program, the input Eric Bloodaxe yields the desired output:
// Hello, Eric Bloodaxe!


