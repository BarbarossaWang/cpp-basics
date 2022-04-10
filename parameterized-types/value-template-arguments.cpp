// @templates @parameterized-types @value-template-arguments

// A template value argument must be a constant expression.

// In addition to type arguments, a template can take value arguments.
template<typename T, int N>
struct Buffer {
    // The alias (value_type) and the constexpr function are provided to 
    // allow users (read-only) access to the template arguments.
    using value_type = T;
    constexpr int size() { return N; }
    T[N];
    // ...
};

Buffer<char, 1024> glob; // global buffer of characters (statically allocated)

void fct()
{
    Buffer<int, 10> buf; // local buffer of integers (on the stack)
    // ...
}
