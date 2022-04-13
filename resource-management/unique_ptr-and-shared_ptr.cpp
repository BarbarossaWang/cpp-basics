// @resource-management @unique_ptr @shared_ptr @utilities

// In <memory>, the standard library provides two “smart pointers” to help manage objects on the free store:
// unique_ptr to represent unique ownership
// shared_ptr to represent shared ownership

// these “smart pointers” are still conceptually pointers and therefore only my second choice for resource management – 
// after containers and other types that manage their resources at a higher conceptual level.
// In particular, shared_ptrs do not in themselves provide any rules for which of their owners can read and/or write the shared object.
// Data races and other forms of confusion are not addressed simply by eliminating the resource management issues.

// Where do we use “smart pointers” (such as unique_ptr) rather than resource handles with operations designed specifically for the resource (such as vector or thread)?
// When we share an object, we need pointers (or references) to refer to the shared object, so a shared_ptr becomes the obvious choice (unless there is an obvious single owner).
// When we refer to a polymorphic object in classical object-oriented code, we need a pointer (or a reference) because we don’t know the exact type of the object referred to (or even its size), so a unique_ptr becomes the obvious choice.
// A shared polymorphic object typically requires shared_ptrs.
// We do not need to use a pointer to return a collection of objects from a function; a container that is a resource handle will do that simply and efficiently.

// The most basic use of these “smart pointers” is to prevent memory leaks caused by careless programming.
void f(int i, int j)    // X* vs. unique_ptr<X>
{
    X* p = new X;                // allocate a new X
    // unique_ptr ensures that its object is properly destroyed whichever way we exit f() 
    // (by throwing an exception, by executing return, or by “falling off the end”).
    unique_ptr<X> sp {new X};    // allocate a new X and give its pointer to unique_ptr
    // ...

    // we “forgot” to delete p if i<99 or if j<77.
    if (i<99) throw Z{};         // may throw an exception
    if (j<77) return;            // may return "early"
    // ... use p and sp ..
    delete p;                    // destroy *p
}

// overuse of new (and of pointers and references) seems to be an increasing problem.
// we could have solved the problem simply by not using a pointer and not using new:
void f(int i, int j)    // use a local variable
{
    Xx;
    // ...
}

// when you really need the semantics of pointers, unique_ptr is a very lightweight mechanism with 
// no space or time overhead compared to correct use of a built-in pointer.

// A unique_ptr is a handle to an individual object (or an array) in much the same way that a vector is a handle to a sequence of objects.
// Both control the lifetime of other objects (using RAII) and both rely on move semantics to make return simple and efficient.

// Its further uses include passing free-store allocated objects in and out of functions:
unique_ptr<X> make_X(int i)
     // make an X and immediately give it to a unique_ptr
{
     // ... check i, etc. ...
     return unique_ptr<X>{new X{i}};
}

// The shared_ptr is similar to unique_ptr except that shared_ptrs are copied rather than moved.
// shared_ptr provides a form of garbage collection that respects the destructor-based resource management of the memory-managed objects.
// This is neither cost free nor exorbitantly expensive, but it does make the lifetime of the shared object hard to predict.
// Use shared_ptr only if you actually need shared ownership.

// The shared_ptrs for an object share ownership of an object; that object is destroyed when the last of its shared_ptrs is destroyed.
void f(shared_ptr<fstream>);
void g(shared_ptr<fstream>);

void user(const string& name, ios_base::openmode mode)
{
    // the file opened by fp’s constructor will be closed by the last function to (explicitly or implicitly) destroy a copy of fp.
     shared_ptr<fstream> fp {new fstream(name,mode)};
     if (!*fp)               // make sure the file was properly opened
            throw No_file{};

     f(fp);
     g(fp);
     // ...
}

// the standard library (in <memory>) provides functions for constructing an object and 
// returning an appropriate smart pointer, make_shared() and make_unique().
// Using make_shared() is not just more convenient than separately making an object using new and then passing it to a shared_ptr, 
// it is also notably more efficient because it does not need a separate allocation for the use count
struct S {
     int i;
     string s;
     double d;
     // ...
};

auto p1 = make_shared<S>(1,"Ankh Morpork",4.65);    // p1 is a shared_ptr<S>
auto p2 = make_unique<S>(2,"Oz",7.62);              // p2 is a unique_ptr<S>

