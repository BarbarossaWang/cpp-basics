// @modules @modularity
// this compilation will define a moudle
module;

// The differences between headers and moudles are not just syntastic
// A module is compiled once only (rather than in each translation unit in which it is used).
// Two modules can be imported in either order without changing their meaning.
// If you import something into a module, users of your module do not implicitly gain access to (and are not bothered by) what you imported: import is not transitive.

// ... here we put stuff that Vector might need for its implementation ...

// This defines a module called Vector, which exports the class Vector, 
// all its member functions, and 
// the non-member function size().
export module Vector; // defining the module called "Vector"

export class Vector {
public:
     Vector(int s);
     double& operator[](int i);
     int size();
private:
     double* elem;     // elem points to an array of sz doubles
     int sz;
};

Vector::Vector(int s)
     :elem{new double[s]}, sz{s}        // initialize members
{
}

double& Vector::operator[](int i)
{
     return elem[i];
}

int Vector::size()
{
     return sz;
}

export int size(const Vector& v) { return v.size(); }
