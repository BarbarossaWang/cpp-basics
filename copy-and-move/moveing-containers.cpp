// @move @container @essential-operators @rvalue

// The && means “rvalue reference” and is a reference to which we can bind an rvalue.
// The word “rvalue” is intended to complement “lvalue,” which roughly means “something that can appear on the left-hand side of an assignment.”
// So an rvalue is – to a first approximation – a value that you can’t assign to, such as an integer returned by a function call.
// Thus, an rvalue reference is a reference to something that nobody else can assign to, so we can safely “steal” its value.

// A move operation is applied when an rvalue reference is used as an initializer or as the right-hand side of an assignment.
// After a move, a moved-from object should be in a state that allows a destructor to be run. Typically, we also allow assignment to a moved-from object.

// The compiler is obliged (by the C++ standard) to eliminate most copies associated with initialization, so move constructors are not invoked as often as you might imagine.
// This copy elision eliminates even the very minor overhead of a move. 
// On the other hand, it is typically not possible to implicitly eliminate copy or move operations from assignments, so move assignments can be critical for performance.

// We didn’t really want a copy; we just wanted to get the result out of a function: we wanted to move a Vector rather than copy it.
class Vector {
    // ...

    Vector(const Vector& a);               // copy constructor
    Vector& operator=(const Vector& a);    // copy assignment
    
    // A move constructor does not take a const argument: 
    // after all, a move constructor is supposed to remove the value from its argument. 
    // A move assignment is defined similarly.
    Vector(Vector&& a); // move constructor
    Vector& operator=(Vector&& a); // move assignment
};

// The compiler will choose the move constructor to implement the transfer of the return value out of the function.
Vector::Vector(Vector&& a)
    :elem{a.elem}, // "grab the elements" from a
    sz{a.sz}
{
    a.elem = nullptr; // now a has no elements
    a.sz = 0;
}

// Where the programmer knows that a value will not be used again, 
// but the compiler can’t be expected to be smart enough to figure that out, the programmer can be specific:
Vector f()
{
    Vector x(1000);
    Vector y(2000);
    Vector z(3000);
    z = x;              // we get a copy (x might be used later in f())
    // The standard-library function move() doesn’t actually move anything. 
    // Instead, it returns a reference to its argument from which we may move – an rvalue reference; 
    // it is a kind of cast (_hist.cast_).
    y = std::move(x);   // we get a move (move assignment)
    // ... better not use x here ...
    return z;           // we get a move
    // When we return from f(), z is destroyed after it’s elements has been moved out of f() by the return. 
    // However, y’s destructor will delete[] its elements.
}
