// @concepts @overloading

// Like other overloading, this is a compile-time mechanism implying no run-time cost, and 
// where the compiler does not find a best choice, it gives an ambiguity error.

// Consider first a single argument for several alternative functions:
// If the argument doesn’t match the concept, that alternative cannot be chosen.
// If the argument matches the concept for just one alternative, that alternative is chosen
// If arguments from two alternatives are equally good matches for a concept, we have an ambiguity.
// If arguments from two alternatives match a concept and one is stricter than the other (match all the requirements of the other and more), that alternative is chosen.

// For an alternative to be chosen it has to be
// a match for all of its arguments, and
// at least an equally good match for all arguments as other alternatives, and
// a better match for at least one argument.

template<Forward_iterator Iter>
void advance(Iter p, int n)        // move p n elements forward
{
    for (−−n)
        ++p;    // a forward iterator has ++, but not + or +=
}

template<Random_access_iterator Iter, int n>
void advance(Iter p, int n)        // move p n elements forward
{
    p+=n;        // a random-access iterator has +=
}

// The compiler will select the template with the strongest requirements met by the arguments.
// a list only supplies forward iterators, but
// a vector offers random-access iterators,
void user(vector<int>::iterator vip, list<string>::iterator lsp)
{
     advance(vip,10);   // use the fast advance()
     advance(lsp,10);   // use the slow advance()
}
