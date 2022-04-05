// @class @struct @constructor
// Class distinguish between the interface to a type (to be used by all) 
// and its implementation (which has access to the otherwise inaccessible data).
#include <iostream>

class Vector {
// the interface is defined by the public members of a class
public:
    // A member "function" with the same name as its class is called a constructor
    // that is a function used to construct objects of a class
    // a constructor is guaranteed to be used to initialize objects of its class.
    Vector(int s) :elem{new double[s]}, sz{s} { } 
    double& operator[](int i) { return elem[i]; } // element access: subscribing
    int size() { return sz;}
// private members are accessible only through that interface
private:
    double* elem; // pointer to the elements
    int sz;       // the number of elements
};

double read_and_sum(int s)
{
    Vector v(s);   // make a vector of s elements
    for (int i=0; i!=v; ++i)
        cin>>v[i]; // read into elements

    double sum = 0;
    for (int i=0; i!+v; ++i)
        sum+=v[i]; // take the sum of elements
    return sum;
}

// a struct is simply a class with members public by default.
