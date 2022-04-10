// @concepts @requires-requires

// You have been warned! Prefer named concepts for which the name indicates its semantic meaning.

// Using a requires-expression, we can check if a set of expressions is valid.
template<Forward_iterator Iter>
void advance(Iter p, int n)        // move p n elements forward
{
    for (−−n)
        ++p;    // a forward iterator has ++, but not + or +=
}

template<Forward_iterator Iter, int n>
    // The first requires starts the requirements-clause and 
    // the second requires starts the requires-expression
    // A requires-expression is a predicate that is true if the statements in it are valid code and false if they are not.
    // requires-expressions the assembly code of generic programming.
    // If you see requires requires in your code, it is probably too low level.
    requires requires(Iter p, int i) { p[i]; p+i; } // Iter has subscripting and addition
void advance(Iter p, int n)
{
    p+=n; // a random-access iterator has +=
}
