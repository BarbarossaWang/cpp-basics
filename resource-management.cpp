// @essential-operations @resource-management @garbage-collection

// C++ also offers a garbage collection interface so that you can plug in a garbage collector. 
// However, I consider garbage collection the last choice after cleaner, more general, and better localized alternatives to resource management have been exhausted. 
// My ideal is not to create any garbage, thus eliminating the need for a garbage collector: Do not litter!

// Garbage collection is fundamentally a global memory management scheme.
// Clever implementations can compensate, but as systems are getting more distributed (think caches, multicores, and clusters), locality is more important than ever.

// Memory is not the only resource. A resource is anything that has to be acquired and (explicitly or implicitly) released after use. 
// Examples are memory, locks, sockets, file handles, and thread handles.
// A resource that is not just memory is called a non-memory resource. 
// A good resource management system handles all kinds of resources. Leaks must be avoided in any long-running system, but excessive resource retention can be almost as bad as a leak.

// Before resorting to garbage collection, systematically use resource handles: 
// let each resource have an owner in some scope and by default be released at the end of its owners scope.
// In C++, this is known as RAII (Resource Acquisition Is Initialization) and is integrated with error handling in the form of exceptions. 
// Resources can be moved from scope to scope using move semantics or “smart pointers,” and shared ownership can be represented by “shared pointers”

std::vector<thread> my_threads;

Vector init(int n)
{
    thread t {heartbeat};                 // run heartbeat concurrently (in a separate thread)
    my_threads.push_back(std::move(t));   // move t into my_threads (§13.2.2)
    // ... more initialization ...

    Vector vec(n);
    for (int i=0; i!=vec.size(); ++i)
         vec[i] = 777;
    return vec;                      // move vec out of init()
}

auto v = init(1'000'000);     // start heartbeat and initialize

// Resource handles, such as Vector and thread, are superior alternatives to direct use of built-in pointers in many cases.
// In fact, the standard-library “smart pointers,” such as unique_ptr, are themselves resource handles.

// In very much the same way that new and delete disappear from application code, we can make pointers disappear into resource handles. 
// In both cases, the result is simpler and more maintainable code, without added overhead.
// In particular, we can achieve strong resource safety; that is, we can eliminate resource leaks for a general notion of a resource. 
// Examples are vectors holding memory, threads holding system threads, and fstreams holding file handles.

// By defining constructors, copy operations, move operations, and a destructor, a programmer can provide complete control of the lifetime of a contained resource (such as the elements of a container). 
// Furthermore, a move constructor allows an object to move simply and cheaply from one scope to another. That way, objects that we cannot or would not want to copy out of a scope can be simply and cheaply moved out instead.
