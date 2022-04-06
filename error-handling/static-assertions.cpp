// @errors-handling @assertions
// we can also perform simple checks on most properties that are known at compile time and report failures to meet our expectations as compiler error messages.

// This will write integers are too small if 4<=sizeof(int) does not hold; that is, 
// if an int on this system does not have at least 4 bytes. 
// We call such statements of expectations assertions.
static_assert(4<=sizeof(int), "integers are too small"); // check integer size

// The static_assert mechanism can be used for anything that can be expressed in terms of constant expressions
constexpr double C = 299792.458; // km/s

void f(double speed)
{
    constexpr double local_mal = 160.0/(60*60); // 160 km/h == 160.0/(60*60) km/s
    
    // static_assert(A,S) prints S as a compiler error message if A is not true. 
    // If you don’t want a specific message printed, leave out the S and the compiler will supply a default message:
    // The default message is typically the source location of the static_assert plus a character representation of the asserted predicate.
    static_assert(speed<C, "can't go that fast"); // error: speed must be a constant
    static_assert(local_max<C, "can't go that fast");
}
