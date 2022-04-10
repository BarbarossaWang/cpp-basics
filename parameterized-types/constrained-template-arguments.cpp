// @templates @parameterized-types @constrained-arguments @constrained-template

// Most often, a template will make sense only for template arguments that meet certain criteria.
// “Element” specifies the requirements of a type that can be an element.

// This template<Element T> prefix is C++’s version of mathematic’s “for all T such that Element(T)”;
// Element is a predicate that checks whether T has all the properties that a Vector requires. Such a predicate is called a concept.
// A template argument for which a concept is specified is called a constrained argument and 
// a template for which an argument is constrained is called a constrained template.
template<Element T>
class Vector {
private:
    T* elem; // elem points to an array of sz elements of type T
    int sz;
    // ...
}

// It is a compile-time error to try to instantiate a template with a type that does not meet its requirements.
Vector<int> v1; // OK: we can copy an int
Vector<thread> v2; // error: we can't copy a standard thread.
// A Vector typically offers a copy operation, and if it does, it must require that its elements must be copyable.
