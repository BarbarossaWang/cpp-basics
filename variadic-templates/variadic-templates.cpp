// @templates @concepts @variadic-templates

// A template can be defined to accept an arbitrary number of arguments of arbitrary types. Such a template is called a variadic template.
void user()
{
    print("first: ", 1, 2.2, "hello\n"s);              // first: 1 2.2 hello

    print("\nsecond: ", 0.2, 'c', "yuck!"s, 0, 1, 2, '\n');   // second: 0.2 c yuck! 0 1 2
}

// Traditionally, implementing a variadic template has been to separate the first argument from the rest and 
// then recursively call the variadic template for the tail of the arguments:
// Eventually, of course, tail will become empty, so we need the no-argument version of print() to deal with that.
void print()
{
    // what we do for no arguments: nothing
}

// The typename ... indicates that Tail is a sequence of types.
template<typename T, typename ... Tail> 
// The Tail... indicates that tail is a sequence of values of the types in Tail.
// A parameter declared with a ... is called a parameter pack
// Here, tail is a (function argument) parameter pack where the elements are of the types found in the (template argument) parameter pack Tail. 
// So, print() can take any number of arguments of any types.
void print(T head, Tail... tail)
{
    // what we do for each argument, e.g.,
    cout << head << ' ';
    // A call of print() separates the arguments into a head (the first) and a tail (the rest). The head is printed and then print() is called for the tail.
    print(tail...);
}

// If we don’t want to allow the zero-argument case, we can eliminate that print() using a compile-time if:
template<typename T, typename ... Tail>
void print(T head, Tail... tail)
{
    cout << head << ' ';
    if constexpr(sizeof...(tail)> 0)
        print(tail...);
}

