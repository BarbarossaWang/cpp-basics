// @utilities @alternatives @variant @optional @overload

// The standard library offers three types to express alternatives:
// variant to represent one of a specified set of alternatives (in <variant>)
// optional to represent a value of a specified type or no value (in <optional>)
// any to represent one of an unbounded set of alternative types (in <any>)

/******************
 * @variant
 ******************/

// A variant<A,B,C> is often a safer and more convenient alternative to explicitly using a union.
// If we try to access a variant holding a different type than the expected one, bad_variant_access is thrown.
// return either a value or an error code
variant<string,int> compose_message(istream& s)
{
     string mess;
     // ... read from s and compose message ...
     if (no_problems)
           return mess;            // return a string
     else
           return error_number;    // return an int
}

// When you assign or initialize a variant with a value, it remembers the type of that value.
auto m = compose_message(cin);

if (holds_alternative<string>(m)) {
      cout << m.get<string>();
}
else {
      int err = m.get<int>();
      // ... handle error ...
}

// a simple compiler may need to distinguish between different kind of nodes with different representations
using Node = variant<Expression,Statement,Declaration,Type>;

void check(Node* p)
{
     if (holds_alternative<Expression>(*p)) {
           Expression& e = get<Expression>(*p);
           // ...
     }
     else if (holds_alternative<Statement>(*p)) {
           Statement& s = get<Statement>(*p);
           // ...
     }
     // ... Declaration and Type ...
}

// overload version
// This is basically equivalent to a virtual function call, but potentially faster.
void check(Node* p)
{
     visit(overloaded {
           [](Expression& e) { /* ... */ },
           [](Statement& s) { /* ... */ },
           // ... Declaration and Type ...
    }, *p);
}

// overload is a “piece of magic” that 
// builds an overload set from a set of arguments (usually lambdas):
// The “visitor” visit then applies () to the overload, which selects the most appropriate lambda to call according to the overload rules.
template<class... Ts>
struct overloaded : Ts... {
    using Ts::operator()...;
};

template<class... Ts>
    // A deduction guide is a mechanism for resolving subtle ambiguities, 
    // primarily for constructors of class templates in foundation libraries.
    overload(Ts...) -> overloaded<Ts...>; // deduction guide

/******************
 * @optional
 ******************/

// An optional<A> can be seen as 
// a special kind of variant (like a variant<A,nothing>) or as 
// a generalization of the idea of an A* either pointing to an object or being nullptr.

// If we try to access an optional that does not hold a value, the result is undefined; an exception is not thrown. 
// Thus, optional is not guaranteed type safe.

// An optional can be useful for functions that may or may not return an object:
optional<string> compose_message(istream& s)
{
     string mess;

     // ... read from s and compose message ...

     if (no_problems)
           return mess;
     return {};     // the empty optional
}

if (auto m = compose_message(cin))
    // Note the curious use of *. An optional is treated as a pointer to its object rather than the object itself.
    cout << *m;     // note the dereference (*)
else {
    // ... handle error ...
}

// The optional equivalent to nullptr is the empty object, {}.
int cat(optional<int> a, optional<int> b)
{
     int res = 0;
     if (a) res+=*a;
     if (b) res+=*b;
     return res;
}

int x = cat(17,19);
int y = cat(17,{});
int z = cat({},{});

/******************
 * @any
 ******************/

// An any can hold an arbitrary type and know which type (if any) it holds.
// It is basically an unconstrained version of variant:

// If we try to access an any holding a different type than the expected one, bad_any_access is thrown.

any compose_message(istream& s)
{
    string mess;

    // ... read from s and compose message ...

    if (no_problems)
          return mess;           // return a string
    else
          return error_number;   // return an int
}

// When you assign or initialize an any with a value, it remembers the type of that value. 
// Later, we can inquire what type the any holds and extract the value.
auto m = compose_message(cin);
string& s = any_cast<string>(m);
cout << s;

