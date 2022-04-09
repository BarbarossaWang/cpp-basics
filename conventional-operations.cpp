// @essential-operations @conventional-operations

// It is wise to conform to them when designing new types for which the operations make sense.
// Comparisons: ==, !=, <, <=, >, and >= 
// Container operations: size(), begin(), and end() 
// Input and output operations: >> and << 
// User-defined literals 
// swap() 
// Hash functions: hash<>

/**********************************
 * @Comparisons
 **********************************/

// The meaning of the equality comparisons (== and !=) is closely related to copying. After a copy, the copies should compare equal:
// When defining ==, also define != and make sure that a!=b means !(a==b).
// Similarly, if you define <, also define <=, >, >=, and make sure that the usual equivalences hold:
// a<=b means (a<b)||(a==b) and !(b<a).
// a>b means b<a.
// a>=b means (a>b)||(a==b) and !(b<a).
X a = something;
X b = a;
assert(a==b);  // if a!=b here, something is very odd.

// To give identical treatment to both operands of a binary operator, such as ==, 
// it is best defined as a free-standing function in the namespace of its class.
namespace NX {
    class X {
        // ...
    };
    bool operator==(const X&, const X&);
    // ...
};

/**********************************
 * @Container-Operations
 **********************************/
// Make the container resource safe by implementing it as a handle with appropriate essential operations.
// The standard-library containers all know their number of elements and we can obtain it by calling size().
for (size_t i = 0; i<c.size(); ++i)    // size_t is the name of the type returned by a standard-library size()
    c[i] = 0;

// However, rather than traversing containers using indices from 0 to size(), the standard algorithms rely on the notion of sequences delimited by pairs of iterators:
// c.begin() is an iterator pointing to the first element of c and c.end() points one-beyond-the-last element of c.
// Like pointers, iterators support ++ to move to the next element and * to access the value of the element pointed to.
for (auto p = c.begin(); p!=c.end(); ++p)
    *p = 0;

// Another way of using the number of elements implicitly is a range-for loop:
// This uses c.begin() and c.end() implicitly and is roughly equivalent to the more explicit loop.
for (auto& x : c)
    x = 0;


/**********************************
 * @Input-and-Output-Operations
 **********************************/
// For pairs of integers, << means left-shift and >> means right-shift.
// However, for iostreams, they are the output and input operator, respectively.


/**********************************
 * @User-Defined-Literals
 **********************************/
// iterals with user-defined suffixes are called user-defined literals or UDLs. Such literals are defined using literal operators. 
// A literal operator converts a literal of its argument type, followed by a subscript, into its return type.

// The operator"" indicates that we are defining a literal operator.
// The i after the “literal indicator” "" is the suffix to which the operator gives a meaning.
// The argument type, long double, indicates that the suffix (i) is being defined for a floating-point literal.
// The return type, complex<double>, specifies the type of the resulting literal.
constexpr complex<double> operator""i(long double arg)     // imaginary literal
{
    return {0,arg};
}

complex<double> z = 2.7182818+6.283185i;

// Standard-Library Suffixes for Literals
// <chrono> std::literals::chrono_literals h, min, s, ms, us, ns
// <string> std::literals::string_literals s
// <string_view> std::literals::string_literals sv
// <complex> std::literals::complex_literals i, il, if


/**********************************
 * @swap()
 **********************************/
// The standard-library provides a std::swap(a,b) implemented as three move operations: (tmp=a, a=b, b=tmp). 
// If you design a type that is expensive to copy and could plausibly be swapped (e.g., by a sort function), then give it move operations or a swap() or both.


/**********************************
 * @hash<>
 **********************************/
// The standard-library unordered_map<K,V> is a hash table with K as the key type and V as the value type.
// To use a type X as a key, we must define hash<X>.
