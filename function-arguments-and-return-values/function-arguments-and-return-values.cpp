// @function-arguments
// The primary and recommended way of passing information from one part of a program to another is through a function call. 
// Information needed to perform a task is passed as arguments to a function and 
// the results produced are passed back as return values.

// There are other paths through which information can be passed between functions, such as 
// global variables, 
// pointer and 
// reference parameters, and 
// shared state in a class object.

// Global variables are strongly discouraged as a known source of errors, and 
// state should typically be shared only between functions jointly implementing a well-defined abstraction (e.g., member functions of a class).

// key concerns about  passing information to and from funcitons:
// Is an object copied or shared?
// If an object is shared, is it mutable?
// Is an object moved, leaving an “empty object” behind?
// The default behavior for both argument passing and value return is “copy”, but some copies can implicitly be optimized to moves.

// the resulting int is copied out of sum() but it would be inefficient and pointless to copy the potentially very large vector into sum(), 
// so the argument is passed by reference (indicated by the &.)
// The sum() has no reason to modify its argument. This immutability is indicated by declaring the vector argument const,
// so the vector is passed by const-reference.
int sum (const vector<int>& v)
{
     int s = 0;
     for (const int i : v)
          s += i;
     return s;
}

vector fib = {1,2,3,5,8,13,21};

int x = sum(fib);          // x becomes 53

