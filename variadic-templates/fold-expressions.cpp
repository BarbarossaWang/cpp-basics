// @templates @concepts @fold-expressions @variadic-templates

// C++17 offers a limited form of iteration over elements of a parameter pack.
template<Number... T>
int sum(T... v)
{
    // (v+...+0) means add all the elements of v starting with the initial value 0.
    // The first element to be added is the “rightmost” (the one with the highest index): (v[0]+(v[1]+(v[2]+(v[3]+(v[4]+0))))).
    // That is, starting from the right where the 0 is. It is called a right fold.
    return (v + ... + 0);     // add all elements of v starting with 0
    // we could have used a left fold:
    // return (0 + ... + v); // add all elements of v to 0
}

int x = sum(1, 2, 3, 4, 5);  // x becomes 15
int y = sum('a', 2.4, x);    // y becomes 114 (2.4 is truncated and the value of 'a' is 97)

// In C++, the fold expressions are currently restricted to simplify the implementation of variadic templates.
// A fold does not have to perform numeric computations. Consider a famous example:
template<typename ...T>
void print(T&&... args)
{
    (std::cout << ... << args) << '\n';  // print all arguments
}

print("Hello!"s,' ',"World ",2017);    // (((((std::cout << "Hello!"s) << ' ') << "World ") << 2017) << '\n');

// Many use cases simply involve a set of values that can be converted to a common type.
// In such cases, simply copying the arguments into a vector or the desired type often simplifies further use:
template<typename Res, typename... Ts>
vector<Res> to_vector(Ts&&... ts)
{
     vector<Res> res;
     (res.push_back(ts) ...);   // no initial value needed
     return res;
}

auto x = to_vector<double>(1,2,4.5,'a');

template<typename ... Ts>
int fct(Ts&&... ts)
{
     auto args = to_vector<string>(ts...);    // args[i] is the ith argument
     // ... use args here ...
}

int y = fct("foo", "bar", x);
