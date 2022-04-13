// @resource-management @utilities

// A resource is something that must be acquired and later (explicitly or implicitly) released.
// Examples are memory, locks, sockets, thread handles, and file handles.

// RAII is fundamental to the idiomatic handling of resources in C++.

// The standard library components are designed not to leak resources.
// They rely on the basic language support for resource management using constructor/destructor pairs to 
// ensure that a resource doesn’t outlive an object responsible for it.
// this approach interacts correctly with error handling using exceptions.

// the standard-library lock classes
mutex m; // used to protect access to shared data
// ...
void f()
{
    // A thread will not proceed until lck’s constructor has acquired the mutex.
    // The corresponding destructor releases the resources.
    scoped_lock<mutex> lck {m}; // acquire the mutex m
    // ... manipulate shared data ...
}
// scoped_lock’s destructor releases the mutex when the thread of control leaves f() (through a return,
// by “falling off the end of the function,” or through an exception throw).
