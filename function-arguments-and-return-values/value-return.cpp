// @return

// the default for value return is to copy and for small objects that’s ideal.
// We return “by reference” only when we want to grant a caller access to something that is not local to the function.

// a local variable disappears when the function returns, so we should not return a pointer or reference to it
// Fortunately, all major C++ compilers will catch the obvious error.
int& bad()
{
    int x;
    // ...
    return x; // bad: return a reference to the local variable x
}

// If a function cannot perform its required task, it can throw an exception.

// how do we pass large amounts of information out of a function?
// we don’t copy, we give Matrix a move constructor and very cheaply move the Matrix out of operator+()
Matrix operator+(const Matrix& x, const Matrix& y)
{
     Matrix res;
     // ... for all res[i,j], res[i,j] = x[i,j]+y[i,j] ...
     return res;
}

Matrix m1, m2;
// ...
Matrix m3 = m1+m2;     // no copy

// Returning large objects by returning a pointer to it is common in older code and a major source of hard-to-find errors.
// Don't write such code
// Matrix* add(const Matrix& x, const Matrix& y)     // complicated and error-prone 20th century style
// {
     // Matrix* p = new Matrix;
     // // ... for all *p[i,j], *p[i,j] = x[i,j]+y[i,j] ...
     // return p;
// }
// 
// Matrix m1, m2;
// // ...
// Matrix* m3 = add(m1,m2);     // just copy a pointer
// // ...
// delete m3;                   // easily forgotten

// The return type of a function can be deduced from its return value.
// This can be convenient, especially for generic functions and lambdas,
// but should be used carefully because a deduced type does not offer a stable interface:
// a change to the implementation of the function (or lambda) can change the type.
auto mul(int i, double d) { return i*d; } // here, "auto" means "deduce the return type"
