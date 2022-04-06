// @error-handling @invariants

// The use of exceptions to signal out-of-range access is an example of a function checking its argument and 
// refusing to act because a basic assumption, a precondition, didn’t hold.

// Such a statement of what is assumed to be true for a class is called a 
// class invariant, or simply an invariant.
// It is the job of a constructor to establish the invariant for 
// its class (so that the member functions can rely on it) and 
// for the member functions to make sure that the invariant holds when they exit.

// The notion of invariants is central to the design of classes, 
// and preconditions serve a similar role in the design of functions.

Vector::Vector(int s)
{
    if (s<0)
        // use the standard-library exception length_error to report a non-positive number
        throw length_error{"Vector constructor: negative size"};
    elem = new double[s];
    sz = s;
}

void test()
{
    // In well-designed code try-blocks are rare. Avoid overuse by systematically using the RAII technique
    try {
        Vector v(-27);
    }
    catch (std::length_error& err) { // do something and rethrow
        cerr << "test failed: length error\n";
        throw; // rethrow
    }
    catch (std::bad_alloc& err) { // this program is not designed to handle memory exhaustion
        std::terminate(); // terminate the program
    }
}
