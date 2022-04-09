// @types @variables @arithmetic @initialization @function-arguments @return-values

// The basic semantics of argument passing and function value return are that of initialization.

// In general, for an assignment to work correctly, the assigned-to object must have a value. 
// On the other hand, the task of initialization is to make an uninitialized piece of memory into a valid object.
// For almost all types, the effect of reading from or writing to an uninitialized variable is undefined.
// We cannot have an uninitialized reference
int x = 7;
int& r {x};    // bind r to x (r refers to x)
r = 7;         // assign to whatever r refers to
// You can use = to initializalize a reference but please don’t let that confuse you.
// This is still initialization and binds r to x, rather than any form of value copy.
int& r = x;     // bind r to x (r refers to x)

int& r2;       // error: uninitialized reference
r2 = 99;       // assign to whatever r2 refers to

// Don’t introduce a name until you have a suitable value for it.

// Conversions that lose information, narrowing conversions, such as double to int and int to char, are allowed and implicitly applied.

// A constant cannot be left uninitialized and a variable should only be left uninitialized in extremely rare circumstances.
// User-defined types (such as string, vector, Matrix, Motor_controller, and Orc_warrior) can be defined to be implicitly initialized.

// Before an object can be used, it must be given a value.
double d1 = 2.3;                 // initialize d1 to 2.3
double d2 {2.3};                 // initialize d2 to 2.3
double d3 = {2.3};               // initialize d3 to 2.3 (the = is optional with { ... })
complex<double> z = 1;           // a complex number with double-precision floating-point scalars
complex<double> z2 {d1,d2};
complex<double> z3 = {d1,d2};    // the = is optional with { ... }
vector<int> v {1,2,3,4,5,6};     // a vector of ints

// Using the general {}-list form, it saves you from conversions that lose information
int i1 = 7.8;        // i1 becomes 7 (surprise?)
int i2 {7.8};        // error: floating-point to integer conversion

// When defining a variable, you don’t need to state its type explicitly when it can be deduced from the initializer:
// With auto, we tend to use the = because there is no potentially troublesome type conversion involved
auto b = true;       // a bool
auto ch = 'x';       // a char
auto i = 123;        // an int
auto d = 1.2;        // a double
auto z = sqrt(y);    // z has the type of whatever sqrt(y) returns
auto bb {true};      // bb is a bool

// We use auto where we don’t have a specific reason to mention the type explicitly. “Specific reasons” include:
// The definition is in a large scope where we want to make the type clearly visible to readers of our code.
// We want to be explicit about a variable’s range or precision (e.g., double rather than float).

