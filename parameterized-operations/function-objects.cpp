// @templates @functions-objects @parameterized-operations

// One particularly useful kind of template is the function object (sometimes called a functor), 
// which is used to define objects that can be called like functions.

// The beauty of these function objects is that they carry the value to be compared against with them.
// We don’t have to write a separate function for each value (and each type), and we don’t have to introduce nasty global variables to hold values.
// The ability to carry data plus their efficiency makes function objects particularly useful as arguments to algorithms.

template<typename T>
class Less_than {
    const T val;   // value to compare against
public:
    Less_than(const T& v) :val{v} { }
    // The function called operator() implements the “function call,” “call,” or “application” operator ().
    bool operator()(const T& x) const { return x<val; } // call operator
};

// Define named variables of type Less_than for some argument type
Less_than lti {42};                // lti(i) will compare i to 42 using < (i<42)
Less_than lts {"Backus"s};         // lts(s) will compare s to "Backus" using < (s<"Backus")
Less_than<string> lts2 {"Naur"};   // "Naur" is a C-style string, so we need <string> to get the right <

// We can call such an object, just as we call a function:
void fct(int n, const string & s)
{
    bool b1 = lti(n);    // true if n<42
    bool b2 = lts(s);    // true if s<"Backus"
    // ...
}

// Count the occurrences of values for which a predicate returns true:
template<typename C, typename P>
    // requires Sequence<C> && Callable<P,Value_type<P>>
int count(const C& c, P pred)
{
    int cnt = 0;
    for (const auto& x : c)
        if (pred(x))
            ++cnt;
    return cnt;
}

// A predicate is something that we can invoke to return true or false.
void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    // Less_than{x} constructs an object of type Less_than<int>, for which the call operator compares to the int called x;
    cout << "number of values less than " << x << ": " << count(vec,Less_than{x}) << '\n';
    // Less_than{s} constructs an object that compares to the string called s.
    cout << "number of values less than " << s << ": " << count(lst,Less_than{s}) << '\n';
}

// Function objects used to specify the meaning of key operations of a general algorithm (such as Less_than for count()) are often referred to as policy objects.
