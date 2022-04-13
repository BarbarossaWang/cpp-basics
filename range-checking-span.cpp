// @utilities @range-checking @span

// A key source of range errors is that people pass pointers (raw or smart) and then rely on convention to know the number of elements pointed to. 
// The best advice for code outside resource handles is to assume that at most one object is pointed to,
// but without support that advice is unmanageable.
// The standard-library string_view can help, but that is read-only and for characters only.

// A string_view is basically a (pointer,length) pair denoting a sequence of elements
// A span gives access to a contiguous sequence of elements.
// Like a pointer, a span does not own the characters it points to. 
// In that, it resembles a string_view and an STL pair of iterators.
void fs(span<int> p)
{
    for (int x : p)
         x = 0;
}

void use(int x)
{
    // That is, the common case, creating a span directly from an array, is now safe (the compiler computes the element count) and notationally simple.
    // For other cases, the probability of mistakes is lowered because the programmer has to explicitly compose a span.
    int a[100];
    fs(a);                  // implicitly creates a span<int>{a,100}
    fs(a,1000);             // error: span expected
    fs({a+10,100});         // a range error in fs
    fs({a,x});              // obviously suspect
}

// The common case where a span is passed along from function to function is simpler than for 
// (pointer,count) interfaces and obviously doesn’t require extra checking:
void f1(span<int> p);

void f2(span<int> p)
{
     // ...
     f1(p);
}

// When used for subscripting (e.g., r[i]), range checking is done and a gsl::fail_fast is thrown in case of a range error.
// Range checks can be suppressed for performance critical code.

// Note that just a single range check is needed for the loop.

// A span of characters is supported directly and called gsl::string_span.
