// @concrete-types @classes @inline @overloaded-operators

// This is a slightly simplified version of the standard-library complex. The class definition itself contains only the operations requiring access to the representation.
// In addition to the logical demands, complex must be efficient or it will remain unused. This implies that simple operations must be inlined.
// simple operations (such as constructors, +=, and imag()) must be implemented without function calls in the generated machine code.
// Functions defined in a class are inlined by default. It is possible to explicitly request inlining by preceding a function declaration with the keyword inline.
class complex {
    double re, im; // representation: two doubles
public:
    complex(double r, double i) :re{r}, im{i} {}    // construct complex from two scalars
    complex(double r) :re{r}, im{0} {}              // construct complex from one scalar
    // A constructor that can be invoked without an argument is called a default constructor.
    // By defining a default constructor you eliminate the possibility of uninitialized variables of that type.
    complex() :re{0}, im{0} {}                      // default complex: {0,0}

    // The const specifiers on the functions returning the real and imaginary parts indicate that these functions do not modify the object for which they are called.
    // A const member function can be invoked for both const and non-const objects,
    // but a non-const member function can only be invoked for non-const objects.
    // complex z = {1,0};
    // const complex cz {1,3};
    // z = cz;                  // OK: assigning to a non-const variable
    // cz = z;                  // error: complex::operator=() is a non-const member function
    // double x = z.real();     // OK: complex::real() is a const member function
    double real() const { return re; }
    void real(double d) { re=d; }
    double imag() const { return im; }
    void imag(double d) { im=d; }

    complex& operator+=(complex z)
    {
     re+=z.re;         // add to re and im
     im+=z.im;
     return *this;     // and return the result
    }

    complex& operator−=(complex z)
    {
     re−=z.re;
     im−=z.im;
     return *this;
    }
}

// Many useful operations do not require direct access to the representation of complex, so they can be defined separately from the class definition:
complex operator+(complex a, complex b) { return a+=b; }
complex operator−(complex a, complex b) { return a−=b; }
complex operator−(complex a) { return {−a.real(), −a.imag()}; }    // unary minus
complex operator*(complex a, complex b) { return a*=b; }
complex operator/(complex a, complex b) { return a/=b; }

// The fact that an argument passed by value is copied so that I can modify an argument without affecting the caller’s copy and use the result as the return value.
bool operator==(complex a, complex b)     // equal
{
     return a.real()==b.real() && a.imag()==b.imag();
}

bool operator!=(complex a, complex b)     // not equal
{
     return !(a==b);
}

complex sqrt(complex);     // the definition is elsewhere

// ...

// Class complex can be used like this:
void f(complex z)
{
     complex a {2.3};       // construct {2.3,0.0} from 2.3
     complex b {1/a};
     // The compiler converts operators involving complex numbers into appropriate function calls.
     // User-defined operators (“overloaded operators”) should be used cautiously and conventionally.
     // The syntax is fixed by the language, so you can’t define a unary /. 
     // Also, it is not possible to change the meaning of an operator for built-in types, so you can’t redefine + to subtract ints.
     complex c {a+z*complex{1,2.3}};
     // ...
     if (c != b)
            c = −(b/a)+2*b;
}
