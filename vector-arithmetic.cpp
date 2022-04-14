// @numberic @vecotr
#include <valarray>

// the standard library provides (in <valarray>) a vector-like template, called valarray, that is less general and more amenable to optimization for numerical computation:
template<typename T>
class valarray {
     // ...
};

// The usual arithmetic operations and the most common mathematical functions are supported for valarrays.
// valarray offers stride access to help implement multidimensional computations.
void f(valarray<double>& a1, valarray<double>& a2)
{
     valarray<double> a = a1*3.14+a2/a1;       // numeric array operators *, +, /, and =
     a2 += a1*3.14;
     a = abs(a);
     double d = a2[7];
     // ...
}

