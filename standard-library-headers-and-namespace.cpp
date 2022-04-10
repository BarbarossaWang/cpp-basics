// @standard-library

// Every standard-library facility is provided through some standard header.
#include<string>
#include<list>

// The standard library is defined in a namespace called std.
std::string sheep {"Four legs Good; two legs Baaad!"};
std::list<std::string> slogans {"War is Peace", "Freedom is Slavery", "Ignorance is Strength"};

// Headers from the C standard library, such as <stdlib.h> are provided. 
// For each such header there is also a version with its name prefixed by c and the .h removed. 
// This version, such as <cstdlib> places its declarations in the std namespace.
