// @templates @parameterized-types @template-argument-deduction

// The effects of deduction guides are often subtle, so it is best to design class templates so that deduction guides are not needed.
 
template<typename T>
class Vector {
public:
    Vector(int);
    Vector(initializer_list<T>); // initializer-list constructor
    // ...
};

Vector v1 {1,2,3}; // deduce v1's element type from the initializer element type
Vector v2 = v1; // deduce v2's element type from v1's element type

auto p = new Vector{1,2,3}; // p points to a Vector<int>

Vector<int> v3(1);  // here we need to be explicit about the element type (no element type is mentioned)

// Deduction it is not a panacea, it can cause surprises (both for make_ functions and constructors).
Vector<string> vs1 {"Hello", "World"};  // Vector<string>
// The type of a C-style string literal is const char*.
// If that was not what was intended, use the s suffix to make it a proper string.
Vector vs {"Hello", "World"};           // deduces to Vector<const char*> (Surprise?)
Vector vs2 {"Hello"s, "World"s};        // deduces to Vector<string>
// If elements of an initializer list have differing types, we cannot deduce a unique element type, so we get an error.
Vector vs3 {"Hello"s, "World"};         // error: the initializer list is not homogenous

// When a template argument cannot be deduced from the constructor arguments, 
// we can help by providing a deduction guide.
template<typename T>
class Vector2 {
public:
    using value_type = T;
    // ...
    Vector2(initializer_list<T>); // initializer-list constructor

    template<typename Iter>
        Vector2(Iter b, Iter e); // [b:e) range constructor
    // ...
}

// If we see a Vector2 initialized by a pair of iterators, we should deduce Vector2::value_type to be the iterator’s value type.
template<typename T>
    Vector2(Iter, Iter) -> Vector2<typename Iter::value_type>;

Vector2 v1 {1,2,3,4,5};              // element type is int
// v2 should be a Vector2<int>, but without help, the compiler cannot deduce that.
// The code only states that there is a constructor from a pair of values of the same type. Without language support for concepts,
// The compiler cannot assume anything about that type.
Vector2 v2(v1.begin(),v1.begin()+2);

