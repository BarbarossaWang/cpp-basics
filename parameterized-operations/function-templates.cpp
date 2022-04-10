// @templates @functions-templates @parameterized-operations

// A function template can be a member function, but not a virtual member. 
// The compiler would not know all instantiations of such a template in a program, so it could not generate a vtbl

// The Value template argument and the function argument v are there to allow the caller to specify the type and 
// initial value of the accumulator (the variable in which to accumulate the sum):
// This sum() is a simplified version of the standard-library accumulate().
template<typename Sequence, typename Value>
Value sum(const Sequence& s, Value v)
{
    for (auto x : s)
        v+=x;
    return x;
}

// Note how the types of the template arguments for sum<Sequence,Value> are deduced from the function arguments. 
// We do not need to explicitly specify those types.
void user(Vector<int>& vi, list<double>& id, vector<complex>& vc)
{
    int x = sum(vi, 0);                     // the sum of a vector of ints (add ints)
    // The point of adding ints in a double would be to gracefully handle a number larger than the largest int.
    double d = sum(vi,0.0);                // the sum of a vector of ints (add doubles)
    double dd = sum(ld,0.0);               // the sum of a list of doubles
    auto z = sum(vc,complex{0.0,0.0});     // the sum of a vector of complex<double>s
}
