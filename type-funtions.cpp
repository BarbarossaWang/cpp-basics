// @type-functions @functions @metaprogramming @tag-dispatch

// Concepts make some some of these techniques redundant and simplify many of the rest.

// A type function is a function that is evaluated at compile time given a type as its argument or returning a type.
// For numerical types, numeric_limits from <limits> presents a variety of useful information
constexpr float min = numeric_limits<float>::min();     // smallest positive float

// object sizes can be found by the built-in sizeof operator.
constexprint szi = sizeof(int);     // the number of bytes in an int

// Such type functions are part of C++’s mechanisms for compile-time computation that 
// allow tighter type checking and better performance than would otherwise have been possible.
// Use of such features is often called metaprogramming or (when templates are involved) template metaprogramming.

/******************
 * @iterator_traits
 ******************/

// The standard-library sort() takes a pair of iterators supposed to define a sequence.
// those iterators must offer random access to that sequence, that is, they must be random-access iterators.

// such as forward_list, do not offer that. In particular, a forward_list is a singly-linked list so subscripting would be expensive and 
// there is no reasonable way to refer back to a previous element.

// The standard library provides a mechanism, iterator_traits, that allows us to check which kind of iterator is provided.
void test(vector<string>& v, forward_list<int>& lst)
{
     sort(v);   // sort the vector
     sort(lst); // sort the singly-linked list
}

// two helper functions that take an extra argument indicating whether they are to be used for random-access iterators or forward iterators.
template<typename Ran>                                             // for random-access iterators
void sort_helper(Ran beg, Ran end, random_access_iterator_tag)     // we can subscript into [beg:end)
{
     sort(beg,end);     // just sort it
}

// The version for forward iterators simply copies the list into a vector, sorts, and copies back:
template<typename For>                                       // for forward iterators
void sort_helper(For beg, For end, forward_iterator_tag)     // we can traverse [beg:end)
{
    // Value_type<For> is the type of For’s elements, called it’s value type.
    // Every standard-library iterator has a member value_type.
     vector<Value_type<For>> v {beg,end};  // initialize a vector from [beg:end)
     sort(v.begin(),v.end());              // use the random access sort
     copy(v.begin(),v.end(),beg);          // copy the elements back
}

// I get the Value_type<For> notation by defining a type alias
template<typename C>
     using Value_type = typename C::value_type; // C's value type
// Thus, for a vector<X>, Value_type<X> is X.

// the selection of helper functions
emplate<typename C>
void sort(C& c)
{
    // Iterator_type<C> returns the iterator type of C (that is, C::iterator)
    using Iter = Iterator_type<C>;
    // Iterator_category<Iter>{} constructs a “tag” value indicating the kind of iterator provided:
    // std::random_access_iterator_tag if C’s iterator supports random access
    // std::forward_iterator_tag if C’s iterator supports forward iteration
    // Given that, we can select between the two sorting algorithms at compile time.
    // This technique, called tag dispatch, 
    sort_helper(c.begin(),c.end(),Iterator_category<Iter>{});
}

template<typename C>
    using Iterator_type = typename C::iterator;   // C's iterator type
 
// However, to extend this idea to types without member types, such as pointers,
// the standard-library support for tag dispatch comes in the form of a class template iterator_traits from <iterator>. 
// The specialization for pointers looks like this:
template<class T>
struct iterator_traits<T*>{
     using difference_type = ptrdiff_t;
     using value_type = T;
     using pointer = T*;
     using reference = T&;
     using iterator_category = random_access_iterator_tag;
};

template<typename Iter>
    using Iterator_category = typename std::iterator_traits<Iter>::iterator_category; // Iter's category

// Now an int* can be used as a random-access iterator despite not having a member type; Iterator_category<int*> is random_access_iterator_tag.

// Many traits and traits-based techniques will be made redundant by concepts.
// concepts version
template<RandomAccessIterator Iter>
void sort(Iter p, Iter q);   // use for std::vector and other types supporting random access

template<ForwardIterator Iter>
void sort(Iter p, Iter q)
     // use for std::list and other types supporting just forward traversal
{
     vector<Value_type<Iter>> v {p,q};
     sort(v);                      // use the random-access sort
     copy(v.begin(),v.end(),p);
}

template<RangeR>
void sort(R& r)
{
     sort(r.begin(),r.end());      // use the appropriate sort
}

/*****************
 * @type-predicates
 *****************/

// In <type_traits>, the standard library offers simple type functions, 
// called type predicates that answers a fundamental question about types.
bool b1 = Is_arithmetic<int>();     // yes, int is an arithmetic type
bool b2 = Is_arithmetic<string>();  // no, std::string is not an arithmetic type

template<typename Scalar>
class complex {
     Scalar re, im;
public:
     static_assert(Is_arithmetic<Scalar>(), "Sorry, I only support complex of arithmetic types");
     // ...
};

// To improve readability compared to using the standard library directly, I defined a type function
// Older programs use ::value directly instead of (), but I consider that quite ugly and it exposes implementation details.
template<typename T>
constexpr bool Is_arithmetic()
{
    return std::is_arithmetic<T>::value ;
}

/********************
 * @enable_if
 ********************/

// The syntax of enable_if is odd, awkward to use, and will in many cases be rendered redundant by concepts.
// However, enable_if is the basis for much current template metaprogramming and for many standard-library components.
// It relies on a subtle language feature called SFINAE (“Substitution Failure Is Not An Error”).

// Obvious ways of using type predicates includes conditions for static_asserts, compile-time ifs, and enable_ifs.
// The standard-library enable_if is a widely used mechanism for conditonally introducing definitions.
template<typename T>
class Smart_pointer {
     T& operator*();
     // If Is_class<T>() is true, the type of operator−>() is T&; 
     // otherwise, the definition of operator−>() is ignored.
     // My type function Is_class() is defined using the type trait is_class.
     std::enable_if<Is_class<T>(),T&> operator−>();    // is defined if and only if T is a class
};
