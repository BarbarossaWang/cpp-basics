// @templates @templates-mechanisms

// To define good templates, we need some supporting language facilities:
// Values dependent on a type: variable templates.
// Aliases for types and templates: alias templates.
// A compile-time selection mechanism: if constexpr.
// A compile-time mechanism to inquire about properties of types and expressions: requires-expressions.
// In addition, constexpr functions and static_asserts often take part in template design and use.

/*********************
 * @Varaible-templates
 * *******************/
// When we use a type, we often want constants and values of that type.
// This is of course also the case when we use a class template: when we define a C<T>, 
// we often want constants and variables of type T and other types depending on T.
template <class T>
     constexpr T viscosity = 0.4;

template <class T>
     constexpr space_vector<T> external_acceleration = { T{}, T{−9.8}, T{} };

auto vis2 = 2*viscosity<double>;
auto acc = external_acceleration<float>;

// We can use arbitrary expressions of suitable type as initializers.
template<typename T, typename T2>
     constexpr bool Assignable = is_assignable<T&,T2>::value;  // is_assignable is a type trait

template<typename T>
void testing()
{
     static_assert(Assignable<T&,double>, "can't assign a double");
     static_assert(Assignable<T&,string>, "can't assign a string");
}

/*********************
 * @Aliases
 * *******************/
// The standard header <cstddef> contains a definition of the alias size_t, maybe:
// The actual type named size_t is implementation-dependent, so in another implementation size_t may be an unsigned long.
// Having the alias size_t allows the programmer to write portable code.
using size_t = unsigned int;

// It is very common for a parameterized type to provide an alias for types related to their template arguments.
template<typename T>
class Vector {
public:
     using value_type = T;
     // ...
};

// In fact, every standard-library container provides value_type as the name of its value type.
// This allows us to write code that will work for every container that follows this convention.
template<typename C>
using Value_type = typename C::value_type;     // the type of C's elements

template<typename Container>
void algo(Container& c)
{
     Vector<Value_type<Container>> vec;        // keep results here
     // ...
}

// The aliasing mechanism can be used to define a new template by binding some or all template arguments.
template<typename Key, typename Value>
class Map {
     // ...
};

template<typename Value>
using String_map = Map<string,Value>;

String_map<int> m;     // m is a Map<string,int>

/*********************
 * @compile-time-if
 * *******************/
template<typename T>
void update(T& target)
{
    // ...
    // The is_pod<T> is a type trait that tells us whether a type can be trivially copied.
    // Only the selected branch of an if constexpr is instantiated.
    if constexpr(is_pod<T>::value)
        simple_and_fast(target); // for "plain old data"
    else
        slow_and_safe(target);
    // ...
}

// If constexpr is not a text-manipulation mechanism and cannot be used to break the usual rules of grammar, type, and scope.
// template<typename T>
// void bad(T arg)
// {
     // if constexpr(Something<T>::value)
          // try{                         // syntax error
// 
     // g(arg);
// 
     // if constexpr(Something<T>::value)
          // } catch(...) { /* ... */ }   // syntax error
// }
