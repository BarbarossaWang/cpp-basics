// @essential-operations

// Constructors, destructors, and copy and move operations for a type are not logically separate. 
// We must define them as a matched set or suffer logical or performance problems. 
// If a class X has a destructor that performs a nontrivial task, such as free-store deallocation or lock release, the class is likely to need the full complement of functions:
class X {
public:
    X(Sometype);            // "ordinary constructor": create an object
    X();                    // default constructor
    X(const X&);            // copy constructor
    X(X&&);                 // move constructor
    X& operator=(const X&); // copy assignment: clean up target and copy
    X& operator=(X&&);      // move assignment: clean up target and move
    ~X();                   // destructor: clean up
    // ...
};

// There are five situations in which an object can be copied or moved:
// As the source of an assignment
// As an object initializer
// As a function argument
// As a function return value
// As an exception
