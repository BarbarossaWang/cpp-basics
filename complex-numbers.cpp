// @numeric @complex

// The sqrt() and pow() (exponentiation) functions are among the usual mathematical functions defined in <complex>.

// To support complex numbers where the scalars are single-precision floating-point numbers (floats), double-precision floating-point numbers (doubles), etc., 
// the standard library complex is a template:
template<typename Scalar>
class complex {
public:
     complex(const Scalar& re ={}, const Scalar& im ={});   // default function arguments;
     // ...
};

// The usual arithmetic operations and the most common mathematical functions are supported for complex numbers.
void f(complex<float> fl, complex<double> db)
{
     complex<long double> ld {fl+sqrt(db)};
     db += fl*3;
     fl = pow(1/fl,2);
     // ...
}
