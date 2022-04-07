// @functions @basics

// Defining a function is the way you specify how an operation is to be done. 
// A function cannot be called unless it has been previously declared.

// A function declaration gives 
// the name of the function, 
// the type of the value returned (if any), and 
// the number and types of the arguments that must be supplied in a call. 
// In a function declaration, the return type comes before the name of the function and 
// the argument types come after the name enclosed in parentheses.
Elem* next_elem();      // no argument; return a pointer to Elem (an Elem*)
void exit(int);         // int argument; return nothing
double sqrt(double);    // double argument; return a double

// The semantics of argument passing are identical to the semantics of initialization. 
// That is, argument types are checked and implicit argument type conversion takes place when necessary.
double s2 = sqrt(2);           // call sqrt() with the argument double{2}
double s3 = sqrt("three");     // error: sqrt() requires an argument of type double

// A function declaration may contain argument names. This can be a help to the reader of a program, 
// but unless the declaration is also a function definition, the compiler simply ignores such names.
double sqrt(double d);  // return the square root of d
double square(double);  // return the square of the argument

// The type of a function consists of its return type and the sequence of its argument types.
double get(const vector<double>& vec, int index);     // type: double(const vector<double>&,int)

// A function can be the member of a class. For such a member function, the name of its class is also part of the function type.
char& String::operator[](int index); // type: char& String::(int)

// If two functions are defined with the same name, but with different argument types, the compiler will choose the most appropriate function to invoke for each call.
// Defining multiple functions with the same name is known as function overloading. 
// When a function is overloaded, each function of the same name should implement the same semantics.
void print(int);     // takes an integer argument
void print(double);  // takes a floating-point argument
void print(string);  // takes a string argument

void user()
{
     print(42);               // calls print(int)
     print(9.65);             // calls print(double)
     print("Barcelona");      // calls print(string)
}

// If two alternative functions could be called, but neither is better than the other, the call is deemed ambiguous and the compiler gives an error.
void print(int,double);
void print(double,int);

void user2()
{
     print(0,0);     // error: ambiguous
}
