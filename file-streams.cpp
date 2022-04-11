// @I/O @file-streams

// In <fstream>, the standard library provides streams to and from a file:
// ifstreams for reading from a file
// ofstreams for writing to a file
// fstreams for reading from and writing to a file

// Testing that a file stream has been properly opened is usually done by checking its state.
// Assuming that the tests succeeded, ofs can be used as an ordinary ostream (just like cout) and ifs can be used as an ordinary istream (just like cin).
ofstream ofs {"target"};               // "o" for "output"
if (!ofs)
       error("couldn't open 'target' for writing");

ifstream ifs {"source"};               // "i" for "input"
if (!ifs)
       error("couldn't open 'source' for reading");
