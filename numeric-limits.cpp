// @numeric @numeric-limits
#include <limits>

// In <limits>, the standard library provides classes that describe the properties of built-in types
static_assert(numeric_limits<char>::is_signed,"unsigned characters!");
// numeric_limits<int>::max() is a constexpr function
static_assert(100000<numeric_limits<int>::max(),"small ints!");

