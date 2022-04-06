// @error-handling @exceptions @try @throw @RAII @noexcept

// The exception handling mechanism will exit scopes and functions as needed to
// get back to a caller that has expressed interest in handling that kind of
// exception, invoking destructors along the way as needed.

// The main technique for making error handling simple and systematic (called Resource Acquisition Is Initialization; RAII)
// The basic idea behind RAII is for a constructor to acquire all resources necessary for a class to operate and 
// have the destructor release all resources, thus making resource release guaranteed and implicit.

double& Vector::operator[](int i)
{
    if (i<0 || size()<=i)
        // The throw transfers control to a handler for exceptions of type out_of_range 
        // in some function that directly or indirectly called Vector::operator[]().
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

void f(Vector& v)
{
    // ...
    // Don't overuse try-statements.
    try { // exceptions here are handled by the handler defined below
        v[v.size()] = 7; // try to access beyond the end of v
    }
    // caught the exception by reference to avoid copying
    // The out_of_range type is defined in the standard library (in <stdexcept>)
    catch (out_of_range& err) { // out_of_range error
        // used the what() function to print the error message put into it at the throw-point
        cerr << err.what() << '\n';
    }
    // ...
}

// A function that should never throw an exception can be declared noexcept.
// If all good intent and planning fails, so that user() still throws, 
// std::terminate() is called to immediately terminate the program.
void user(int sz) noexcept
{
    Vector v(sz);
    iota(&v[0], &v[sz], i); // fill v with 1, 2, 3, 4, ...
    // ...
}
