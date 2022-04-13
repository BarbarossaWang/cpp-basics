// @resource-management @utilities @move() @forward()

// The state of a moved-from object is in general unspecified, but all standard-library types leave a moved-from object in a state where it can be destroyed and assigned to. 
// It would be unwise not to follow that lead. For a container (e.g., vector or string), the moved-from state will “empty.” 
// For many types, the default value is a good empty state: meaningful and cheap to establish.

// The choice between moving and copying is mostly implicit.
// A compiler will prefer to move when an object is about to be destroyed (as in a return) because 
// that’s assumed to be the simpler and more efficient operation.
// However, sometimes we must be explicit.
void f1()
{
     auto p = make_unique<int>(2);
     auto q = p;       // error: we can't copy a unique_ptr
     // ...

     // If you want a unique_ptr elsewhere, you must move it.
     // std::move() doesn’t move anything. Instead, it casts its argument to an rvalue reference, 
     // thereby saying that its argument will not be used again and therefore may be moved.
     // It should have been called something like rvalue_cast
     auto q = move(p);       // p now holds nullptr
}

// We don’t want to repeatedly copy potentially large objects, so we request moves using std::move().
template <typename T>
void swap(T& a, T& b)
{
     T tmp {move(a)};       // the T constructor sees an rvalue and moves
     a = move(b);           // the T assignment sees an rvalue and moves
     b = move(tmp);         // the T assignment sees an rvalue and moves
}

// Like for other casts, there are tempting, but dangerous, uses of std::move().
string s1 = "Hello";
string s2 = "World";
vector<string> v;
v.push_back(s1);          // use a "const string&" argument; push_back() will copy
v.push_back(move(s2));    // use a move constructor
// The problem is that a moved-from object is left behind. If we use s2 again, we have a problem:
cout << s1[2];     // write 'l'
cout << s2[2];     // crash?

// Forwarding arguments is an important use case that requires moves.
// We sometimes want to transmit a set of arguments on to another function without changing anything (to achieve “perfect forwarding”):
// The standard-library forward() differs from the simpler std::move() by correctly handling subtleties to do with lvalue and rvalue.
// Use std::forward() exclusively for forwarding and don’t forward() something twice; 
// once you have forwarded an object, it’s not yours to use anymore.
template<typename T, typename ... Args>
unique_ptr<T> make_unique(Args&&... args)
{
    return unique_ptr<T>{new T{std::forward<Args>(args)...}};  // forward each argument
}
