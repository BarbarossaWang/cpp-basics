// @containers @concrete-type @initializing-containers @static_cast

// A container exists to hold elements, so obviously we need convenient ways of getting elements into a container. 
// We can create a Vector with an appropriate number of elements and then assign to them, but typically other ways are more elegant.

// Initializer-list constructor: Initialize with a list of elements.
// push_back(): Add a new element at the end of (at the back of) the sequence.

class Vector {
    public:
        Vector (std::Initializer_list<double>); // initialize with a list of doubles
        // ...
        void push_back(double); // add element at end, increasing the size by one
        // ...
};

Vector read(istream& is)
{
    Vector v;
    // I used a for-statement rather than the more conventional while-statement to keep the scope of d limited to the loop.
    for (double d; is>>d;) // read floating-point values into d
        // The push_back() is useful for input of arbitrary numbers of elements.
        v.push_back(d); // add d to v
    return v;
}

Vector v = read(cin); // no copy of Vector elements here

// The std::initializer_list used to define the initializer-list constructor is a standard-library type known to the compiler
// when we use a {}-list, the compiler will create an object of type initializer_list to give to the program.
Vector v1 = {1,2,3,4,5};              // v1 has 5 elements
Vector v2 = {1.23, 3.45, 6.7, 8};     // v2 has 4 elements

// Vector’s initializer-list constructor might be defined like this
Vector::Vector(std::initializer_list<double> lst) // initialize with a list
    // the standard-library uses unsigned integers for sizes and subscripts, 
    // so I need to use the ugly static_cast to explicitly convert the size of the initializer list to an int.
    // A static_cast does not check the value it is converting; the programmer is trusted to use it correctly.
    // This is not always a good assumption, so if in doubt, check the value.
    // Explicit type conversions (often called casts to remind you that they are used to prop up something broken) are best avoided.
    // Try to use unchecked casts only for at the lowest level of a system. They are error-prone.
    :elem{new double[lst.size()]}, sz{static_cast<int>(lst.size())}
{
    copy(lst.begin(),lst.end(),elem); // copy from lst into elem
}

// Other casts are reinterpret_cast for threating an object as simply a sequence of bytes and 
// const_cast for “casting away const.”
