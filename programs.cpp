// @basics @main @string

// C++ is a compiled language. For a program to run, its source text has to be processed by a compiler, producing object files, 
// which are combined by a linker yielding an executable program. 
// A C++ program typically consists of many source code files (usually simply called source files).

// When we talk about portability of C++ programs, we usually mean portability of source code; that is, the source code can be successfully compiled and run on a variety of systems.

// The ISO C++ standard defines two kinds of entities:
// Core language features, such as built-in types.
// Standard-library components, such as containers (e.g., vector and map) and I/O operations (e.g., << and getline())

// C++ is a statically typed language. That is, the type of every entity (e.g., object, value, name, and expression) must be known to the compiler at its point of use. 
// The type of an object determines the set of operations applicable to it.

// This defines a function called main,  which takes no arguments and does nothing.
int main() { } //        the minimal C++ program

// Curly braces, { }, express grouping in C++. Here, they indicate the start and end of the function body. 
// The double slash, //, begins a comment that extends to the end of the line. A comment is for the human reader; the compiler ignores comments.

// Every C++ program must have exactly one global function named main(). The program starts by executing that function. 
// The int value returned by main(), if any, is the program's return value to the system. 
// If no value is returned, the system will receive a value indicating successful completion. A nonzero value from main() indicates failure. 

// The line #include <iostream> instructs the compiler to include the declarations of the standard stream I/O facilities as found in iostream.
#include <iostream>

// Essentially all executable code is placed in functions and called directly or indirectly from main().
int main()
{
    // The operator << writes its second argument onto its first.
    // A string literal is a sequence of characters surrounded by double quotes. 
    // In a string literal, the backslash character \ followed by another character denotes a single special character.
    // The std:: specifies that the name cout is to be found in the standard-library namespace
    std::cout << "Hello, World!\n";
}

// A return type void indicates that a function does not return a value.
