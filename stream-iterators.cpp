// @iterators @algorithm @stream-iterators

// To make an ostream_iterator, we need to specify which stream will be used and the type of objects written to it.
// The effect of assigning to *oo is to write the assigned value to cout.
ostream_iterator<string> oo {cout};    // write strings to cout

int main()
{
     *oo = "Hello, ";    // meaning cout<<"Hello, "
    // The ++oo is done to mimic writing into an array through a pointer.
     ++oo;
     *oo = "world!\n";   // meaning cout<<"world!\n"
}

// Similarly, an istream_iterator is something that allows us to treat an input stream as a read-only container.
istream_iterator<string> ii {cin};
// Input iterators are used in pairs representing a sequence, so we must provide an istream_iterator to indicate the end of input. 
// This is the default istream_iterator:
istream_iterator<string> eos {};

// Typically, istream_iterators and ostream_iterators are not used directly. 
// Instead, they are provided as arguments to algorithms.

// A simple program to read a file, sort the words read, eliminate duplicates, and write the result to another file:
int main()
{
     string from, to;
     cin >> from >> to;             // get source and target file names

     // An ifstream is an istream that can be attached to a file, and 
     ifstream is {from};            // input stream for file "from"
     // an ofstream is an ostream that can be attached to a file.
     // The ostream_iterator’s second argument is used to delimit output values
     ofstream os {to};              // output stream for file "to"

     // keeping the strings in a set, which does not keep duplicates and keeps its elements in order
     set<string> b {istream_iterator<string>{is},istream_iterator<string>{}};     // read input
     copy(b.begin(),b.end(),ostream_iterator<string>{os,"\n"});                   // copy to output

     return !is.eof() || !os;           // return error state
}

