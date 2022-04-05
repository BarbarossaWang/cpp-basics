// @struct
#include <iostream>

// first version of Vector
struct Vector {
    int sz;       // number of elements
    double* elem; // pointer to elements
};

// constructor of Vector
void vector_init(Vector& v, int s)
{
    // The new operator allocated memory from an area called the free store
    // also know as dynamic memory and heap
    // Object allocated on the free store are independent of the scope from
    // which they are created and "live" until they are destroyed using the 
    // delete operator.
    v.elem = new double[s];
    v.sz = s;
}

// a simple use of Vector:
double read_and_sum(int s)
{
    Vector v;
    vector_init(v, s);  // allocate s elements for v
    
    for (int i=0; i!=s; ++i)
        cin>>v.elem[i]; // read into elements
    
    double sum = 0;
    for (int i=0' i!=s; ++i)
        sum+=v.elem[i];
    return sum;
}

// get struct members
void f(Vector v, Vector& rv, Vector* pv)
{
    int i1 = v.sz;   // access through name
    int i2 = rv.sz;  // access through reference
    int i3 = pv->sz; // access through pointer
}
