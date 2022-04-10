// @templates @lambda-expressions @parameterized-operations

// There is a notation for implicitly generating function objects:
void f(const Vector<int>& vec, const list<string>& lst, int x, const string& s)
{
    cout << "number of values less than " << x
        // The notation [&](int a){ return a<x; } is called a lambda expression.
        // The [&] is a capture list specifying that all local names used in the lambda body (such as x) will be accessed through references.
        // Had we wanted to “capture” only x, we could have said so: [&x].
        // Had we wanted to give the generated object a copy of x, we could have said so: [=x].
        // Capture nothing is [ ],
        // capture all local names used by reference is [&], and
        // capture all local names used by value is [=].
        << ": " << count(vec,[&](int a){ return a<x; })
        << '\n';
    cout << "number of values less than " << s
        << ": " << count(lst,[&](const string& a){ return a<s; })
        << '\n';
}

// we noted the annoyance of having to write many functions to perform operations on elements of vectors of pointers and unique_ptrs, such as draw_all() and rotate_all().
// Function objects (in particular, lambdas) can help by allowing us to 
// separate the traversal of the container from the specification of what is to be done with each element.
template<typename C, typename Oper>
void for_all(C& c, Oper op)       // assume that C is a container of pointers
     // requires Sequence<C> && Callable<Oper,Value_type<C>>
{
     for (auto& x : c)
           op(x);       // pass op() a reference to each element pointed to
}

void user2()
{
    vector<unique_ptr<Shape>> v;
    while (cin)
        v.push_back(read_shape(cin));
    // I pass a unique_ptr<Shape>& to a lambda so that for_all() doesn’t have to care exactly how the objects are stored.
    // In particular, those for_all() calls do not affect the lifetime of the Shapes passed and 
    // the bodies of the lambdas use the argument just as if were been a plain-old pointers.
    for_all(v,[](unique_ptr<Shape>& ps){ ps−>draw(); });        // draw_all()
    for_all(v,[](unique_ptr<Shape>& ps){ ps−>rotate(45); });    // rotate_all(45)
}

// Like a function, a lambda can be generic.
template<class S>
void rotate_and_draw(vector<S>& v, int r)
{
    // like in variable declarations, auto means that any type is accepted as an initializer (an argument is considered to initialize the formal parameter in a call).
    // This makes a lambda with an auto parameter a template, a generic lambda.
    for_all(v,[](auto& s){ s−>rotate(r); s−>draw(); });
}

void user4()
{
    vector<unique_ptr<Shape>> v1;
    vector<Shape*> v2;
    // ...
    rotate_and_draw(v1,45);
    rotate_and_draw(v2,90);
}

// Using a lambda, we can turn any statement into an expression.
// This is mostly used to provide an operation to compute a value as an argument value, but the ability is general.
enum class Init_mode { zero, seq, cpy, patrn };     // initializer alternatives

vector<int> v = [&] {
     switch (m) {
     case zero:
          return vector<int>(n);       // n elements initialized to 0
     case seq:
          return vector<int>{p,q};     // copy from sequence [p:q)
     case cpy:
          return arg;
     }
};
// ...
