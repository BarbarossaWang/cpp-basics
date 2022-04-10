// @generic-programming @concepts

/**********************
 * @Use-of-concepts
 * ********************/

// The form of generic programming supported by C++ centers around the idea of abstracting from concrete, efficient algorithms to obtain generic algorithms that can be combined with different data representations to produce a wide variety of useful software.
// A concept is not just a syntactic notion, it is fundamentally about semantics. For example, don’t define + to divide; that would not match the requirements for any reasonable number
// Good, useful concepts are fundamental and are discovered more than they are designed.

// A type is regular when it behaves much like an int or a vector. An object of a regular type
// can be default constructed.
// can be copied (with the usual semantics of copy, yielding two objects that are independent and compare equal) using a constructor or an assignment.
// can be compared using == and !=.
// doesn’t suffer technical problems from overly clever programming tricks.

/**********************
 * @Abstraction-using-templates
 * ********************/

// Start with one – and preferably more – concrete examples from real use and try to eliminate
// The process of generalizing from a concrete piece of code (and preferably from several) while preserving performance is called lifting.
// The best way to develop a template is often to
// first, write a concrete version
// then, debug, test, and measure it
// finally, replace the concrete types with template arguments.
double sum(const vector<int>& v)
{
    double res = 0;
    for (auto x : v)
         res += x;
    return res;
}
// Consider what makes this code less general than it needs to be:
// Why just ints?
// Why just vectors?
// Why accumulate in a double?
// Why start at 0?
// Why add?
template<typename Iter, typename Val>
Val accumulate(Iter first, Iter last, Val res)
{
    for (auto p = first; p!=last; ++p)
        res += *p;
    return res;
}

void use(const vector<int>& vec, const list<double>& lst)
{
    auto sum = accumulate(begin(vec),end(vec),0.0); // accumulate in a double
    auto sum2 = accumulate(begin(lst),end(lst),sum);
    //
}

// Naturally, the repetition of begin() and end() is tedious, so we can simplify the user interface a bit:
template<Range R, Number Val>   // a Range is something with begin() and end()
Val accumulate(R r, Val res = 0)
{
     for (auto p = begin(r); p!=end(r); ++p)
           res += *p;
     return res;
}
