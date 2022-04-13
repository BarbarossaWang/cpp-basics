// @containers @utilities @specialized-containers

// T[N] Built-in array: a fixed-size continuously allocated sequence of N elements of type T; implicitly converts to a T*
// array<T,N> A fixed-size continuously allocated sequence of N elements of type T; like the built-in array, but with most problems solved
// bitset<N> A fixed-size sequence of N bits
// vector<bool> A sequence of bits compactly stored in a specialization of vector
// pair<T,U> Two elements of types T and U
// tuple<T...> A sequence of an arbitrary number of elements of arbitrary types
// basic_string<C> A sequence of characters of type C; provides string operations
// valarray<T> An array of numeric values of type T; provides numeric operations

// If the standard library didn’t provide them, many people would have to design and implement their own.
// pair and tuple are heterogeneous; all other containers are homogeneous (all elements are of the same type).
// array, vector, and tuple elements are contiguously allocated; forward_list and map are linked structures.
// itset and vector<bool> hold bits and access them through proxy objects; all other standard-library containers can hold a variety of types and access elements directly.
// basic_string requires its elements to be some form of character and to provide string manipulation, such as concatenation and locale-sensitive operations.
// valarray requires its elements to be numbers and to provide numerical operations.
