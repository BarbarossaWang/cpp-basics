// @scope @lifetime @basics @constexpr @const

// C++ supports two notions of immutability:
// const: meaning roughly “I promise not to change this value.” This is used primarily to specify interfaces so that data can be passed to functions using pointers and references without fear of it being modified. The compiler enforces the promise made by const. The value of a const can be calculated at run time.
// constexpr: meaning roughly “to be evaluated at compile time.” This is used primarily to specify constants, to allow placement of data in read-only memory (where it is unlikely to be corrupted), and for performance. The value of a constexpr must be calculated by the compiler.For a function to be usable in a constant expression, that is, in an expression that will be evaluated by the compiler, it must be defined constexpr.

// In a few places, constant expressions are required by language rules (e.g., array bounds, case labels, template value arguments, and constants declared using constexpr).
// In other cases, compile-time evaluation is important for performance. Independently of performance issues, the notion of immutability (an object with an unchangeable state) is an important design concern.

const int dmv = 17; // dmv is a named constant
int var = 17; // var is not a constant
const double sqv = sqrt(var);       // sqv is a named constant, possibly computed at run time

double sum(const vector<double>&); // sum will not modify its argument

vector<double> v {1.2, 3.4, 4.5}; // v is not a constant
const double s1 = sum(v); // OK: evaluated at run time
constexpr double s2 = sum(v); // error : sum(v) not constant expression   

// For a function to be usable in a constant expression, that is, in an expression that will be evaluated by the compiler, it must be defined constexpr.
constexpr double square(double x) { return x*x; }
constexpr double max1 = 1.4*square(dmv); // OK if square(17) is a constant expression
constexpr double max2 = 1.4*square(var); // error : var is not a constant expression
// A constexpr function can be used for non-constant arguments, but when that is done the result is not a constant expression.
// We allow a constexpr function to be called with non-constant-expression arguments in contexts that do not require constant expressions.
const double max3 = 1.4*square(var); // OK, may be evaluated at run time

// To be constexpr, a function must be rather simple and cannot have side effects and can only use information passed to it as arguments. 
// In particular, it cannot modify non-local variables, but it can have loops and use its own local variables.
constexpr double nth(double x, int n) // assume 0<=n
{
    double res = 1;
    int i = 0;
    while (i<n) {
        res*+x;
        ++i;
    }
    return res;
}
