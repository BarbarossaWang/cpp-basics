// @numerics @mathematic

// In <cmath>, we find the standard mathematical functions,
// Standard Mathematical Functions
// abs(x) Absolute value
// ceil(x) Smallest integer >= x
// floor(x) Largest integer <= x
// sqrt(x) Square root; x must be non-negative
// cos(x) Cosine
// sin(x) Sine
// tan(x) Tangent
// acos(x) Arccosine; the result is non-negative
// asin(x) Arcsine; the result nearest to 0 is returned
// atan(x) Arctangent
// sinh(x) Hyperbolic sine
// cosh(x) Hyperbolic cosine
// tanh(x) Hyperbolic tangent
// exp(x) Base e exponential
// log(x) Natural logarithm, base e; x must be positive
// log10(x) Base 10 logarithm

// The version for complex are found in <complex>
// For each function, the return type is the same as the argument type.

// Errors are reported by setting errno from <cerrno> to EDOM for a domain error and 
// to ERANGE for a range error.

void f()
{
     errno = 0; // clear old error state
     sqrt(−1);
     if (errno==EDOM)
           cerr << "sqrt() not defined for negative argument";

     errno = 0; // clear old error state
     pow(numeric_limits<double>::max(),2);
     if (errno == ERANGE)
           cerr << "result of pow() too large to represent as a double";
}

// A few more mathematical functions are found in <cstdlib>
// the so-called special mathematical functions, such as beta(), rieman_zeta(), and sph_bessel(), are also in <cmath>.
