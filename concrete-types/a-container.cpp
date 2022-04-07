// @classes @container @destructor @RAII

// A container is an object holding a collection of elements. 
// We call class Vector a container because objects of type Vector are containers.
// Vector have a fatal flaw: it allocates elements using new but never deallocates them. 
// Although C++ defines an interface for a garbage collector, it is not guaranteed that one is available to make unused memory available for new objects.

// The constructor allocates the elements and initializes the Vector members appropriately. 
// The destructor deallocates the elements.
// This handle-to-data model is very commonly used to manage data that can vary in size during the lifetime of an object.

// The technique of acquiring resources in a constructor and releasing them in a destructor, known as Resource Acquisition Is Initialization or RAII, 
// allows us to eliminate “naked new operations,” that is, to avoid allocations in general code and 
// keep them buried inside the implementation of well-behaved abstractions.

// Similarly, “naked delete operations” should be avoided. 
// Avoiding naked new and naked delete makes code far less error-prone and far easier to keep free of resource leaks

class Vector {
public:
    // Vector’s constructor allocates some memory on the free store (also called the heap or dynamic store) using the new operator.
    Vector(int s) :elem{new double[s]}, sz{s}; // constructor: acquire resources
    {
        for (int i=0; i!=s; ++i} // initialize elements
            elem[i]=0;
    }

    // The name of a destructor is the complement operator, ~, followed by the name of the class; it is the complement of a constructor.
    // The destructor cleans up by freeing that memory using the delete[] operator. 
    // Plain delete deletes an individual object, delete[] deletes an array.
    ~Vector() { delete[] elem; } // destructor: release resources

    double& operator[](int i);
    int size() const;
private:
    double* elem; // elem points to an array of sz doubles
    int sz;
};

// Vector obeys the same rules for naming, scope, allocation, lifetime, etc., as does a built-in type.
void fct(int n)
{
    Vector v(n);
    // ... use v ...
    {
        Vector v2(2*n);
        // ... use v and v2 ...
    } // v2 is destroyed here
    // ... use v ...
} // v is destroyed here
