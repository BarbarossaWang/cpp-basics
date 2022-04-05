// @modularity @declaration

// At the language level, C++ represents interfaces by declarations. 
// A declaration specifies all that’s needed to use a function or a type.

// There can be many declarations for an entity, such as a function, but only one definition.

// the function definitions are "elsewhere."
double sqrt(double); // the square root function takes a double and return a double

class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();

private:
    double* elem; // elem points  to an array of sz doubles
    int sz;
};

// sqrt() is a part of the standard library
// a @library is simply “some other code we happen to use” written with the same language facilities we use.
// the definition of sqrt()
// double sqrt(double d)
// {
// ...
// }

// For Vector, we need to define all three member functions
Vector::Vector(int s)           // definition of the constructor
    :elem{new double[s]}, sz{s} // initialize members
{
}

double& Vector::operator[](int i) // definition of subscripting`
{
    return elem[i];
}

int Vector::size() // definition of size()
{
    return sz;
}

