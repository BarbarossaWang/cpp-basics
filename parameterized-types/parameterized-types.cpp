// @templates @parameterized-types

// Templates are a compile-time mechanism, so their use incurs no run-time overhead compared to hand-crafted code.

// A template plus a set of template arguments is called an instantiation or a specialization.

// Late in the compilation process, at instantiation time, code is generated for each instantiation used in a program.
// The code generated is type checked so that the generated code is as type safe as handwritten code.

// The template<typename T> prefix makes T a parameter of the declaration it prefixes.
// It is C++’s version of the mathematical “for all T” or more precisely “for all types T.” 
// If you want the mathematical “for all T, such that P(T),” you need @concepts.
// Using class to introduce a type parameter is equivalent to using typename, and 
// in older code we often see template<class T> as the prefix.
template<typename T>
class Vector {
private:
    T* elem; // elem points to an array of sz elements of value T
    int sz;
public:
    explicit Vector(int s); // constructor: establish invariant, acquire resources
    ~Vector() { delete[] elem; } // destructor: release resources

    // ... copy and move operations

    T& operator[](int i); // for non-cost Vector
    const T& operator[](int i) const; // for const Vectors
    int size() const { return sz; }
};

// The member functions
template<typename T>
Vector<T>::Vector(int s)
{
    if (s<0)
        throw Negative_size{};
    elem = new T[s];
    sz = s;
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
    if (i<0 || size()<=i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

// To support the range-for loop for our Vector, we must define suitable begin() and end() functions:
template<typename T>
T* begin(Vector<T>& x)
{
    return x.size() ? &x[0] : nullptr; // pointer to first element or nullptr
}

template<typename T>
T* begin(Vector<T>& x)
{
    return x.size() ? &x[0]+x.size() : nullptr; // pointer to one-past-last element or nullptr
}

// Define Vector
Vector<char> vc(200);          // vector of 200 characters
Vector<string> vs(17);         // vector of 17 strings
// Nested template arguments
Vector<list<int>> vli(45);     // vector of 45 lists of integers

// Use Vector
void write(const Vector<string>& vs) // Vector of some string
{
    for (int i = 0; i!=vs.size(); ++i)
        cout << vs[i] << '\n';
}

void f2(Vector<string>& vs) // Vector of some string
{
    for (auto& s : vs)
        cout << s << '\n';
}
