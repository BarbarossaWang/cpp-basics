// @concepts @definitions-of-concepts

// The value of a concept is always bool.

// A concept is a compile-time predicate specifying how one or more types can be used.
template<typename T>
// Equality_comparable is the concept we use to ensure that we can compare values of a type equal and non-equal.
// We simply say that, given two values of the type, they must be comparable using == and != and the result of those operations must be convertible to bool.
concept Equality_comparable =
    requires (T a, T b) {
         { a == b } −> bool;   // compare Ts with ==
         { a != b } −> bool;   // compare Ts with !=
    };

static_assert(Equality_comparable<int>);   // succeeds

struct S { int a; };
static_assert(Equality_comparable<S>);     // fails because structs don't automatically get == and !=

// The typename T2 =T says that if we don’t specify a second template argument, 
// T2 will be the same as T; T is a default template argument.
template<typename T, typename T2 =T>
concept Equality_comparable =
    requires (T a, T2 b) {
         { a == b } −> bool;  // compare a T to a T2 with ==
         { a != b } −> bool;  // compare a T to a T2 with !=
         { b == a } −> bool;  // compare a T2 to a T with ==
         { b != a } −> bool;  // compare a T2 to a T with !=
    };

static_assert(Equality_comparable<int,double>);  // succeeds
static_assert(Equality_comparable<int>);         // succeeds (T2 is defaulted to int)
static_assert(Equality_comparable<int,string>);  // fails

template<typename S>
concept Sequence = requires(S a) {
    // For a type S to be a Sequence, it must provide a Value_type (the type of its elements) and 
    // an Iterator_type (the type of its iterators;
    typename Value_type<S>;             // S must have a value type.
    typename Iterator_type<S>;          // S must have an iterator type.

    // It must also ensure that there exist begin() and end() functions that return iterators, as is idiomatic for standard-library containers.
    { begin(a) } −> Iterator_type<S>;   // begin(a) must return an iterator
    { end(a) } −> Iterator_type<S>;     // end(a) must return an iterator

    // the Iterator_type really must be an input_iterator with elements of the same type as the elements of S.
    requires Same_type<Value_type<S>,Value_type<Iterator_type<S>>>;
    requires Input_iterator<Iterator_type<S>>;
};

