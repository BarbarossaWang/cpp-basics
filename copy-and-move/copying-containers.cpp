// @copy @containers @move

// When a class is a resource handle – that is, when the class is responsible for an object accessed through a pointer – 
// the default memberwise copy is typically a disaster. Memberwise copy would violate the resource handle’s invariant 
// the fact that Vector has a destructor is a strong hint that the default (memberwise) copy semantics is wrong and 
// the compiler should at least warn against this example.
void bad_copy(Vector v1)
{
    Vector v2 = v1;    // copy v1's representation into v2
    v1[0] = 2;         // v2[0] is now also 2!
    v2[1] = 3;         // v1[1] is now also 3!
}

// Copying of an object of a class is defined by two members: 
// a copy constructor and a copy assignment:
class Vector {
private:
    double* elem; // elem points to an array of sz doubles
    int sz;
public:
    Vector(int s);                         // constructor: establish invariant, acquire resources
    ~Vector() { delete[] elem; }           // destructor: release resources

    Vector(const Vector& a);               // copy constructor
    Vector& operator=(const Vector& a);    // copy assignment

    double& operator[](int i);
    const double& operator[](int i) const;

    int size() const;
};

// A suitable definition of a copy constructor for Vector allocates the space for the required number of elements and 
// then copies the elements into it so that after a copy each Vector has its own copy of the elements:
Vector::Vector(const Vector& a) // copy constructor
    :elem{new double[a.sz]}, // allocate space for elements
    sz{a.sz}
{
    for (int i=0; i!=sz; ++i) // copy elements
        elem[i] = a.elem[i];
}

// we need a copy assignment in addition to the copy constructor:
Vector& Vector::operator=(const Vector& a)     // copy assignment
{
     double* p = new double[a.sz];
     for (int i=0; i!=a.sz; ++i)
           p[i] = a.elem[i];
     delete[] elem;         // delete old elements
     elem = p;
     sz = a.sz;
     // The name this is predefined in a member function and points to the object for which the member function is called.
     return *this;
}

