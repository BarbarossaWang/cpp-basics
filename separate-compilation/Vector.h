// @compilation @practical @modularity
// The best approach to program organization is to think of the program as a set of modules with well-defined dependencies, 
// represent that modularity logically through language features, 
// and then exploit the modularity physically through files for effective separate compilation.

// This declaration would be placed in a file Vector.h. 
// Users then include that file, called a header file, to access that interface.
class Vector {
public:
    Vector(int s);
    double& operator[](int i);
    int size();

private:
    double* elem; // elem points to an array of sz doubles
    int sz;
};

// The code in user.cpp and Vector.cpp shares the Vector interface information presented in Vector.h, 
// but the two files are otherwise independent and can be separately compiled.
