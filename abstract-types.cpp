// @abstract-types @classes @polymorphic @OOP @inheritance @override

// An abstract type is a type that completely insulates a user from implementation details. 
// To do that, we decouple the interface from the representation and give up genuine local variables.
// Since we don’t know anything about the representation of an abstract type (not even its size), 
// we must allocate objects on the free store and access them through references or pointers.

// This class is a pure interface to specific containers defined later. 
// The word virtual means “may be redefined later in a class derived from this one.”
// A Container can only serve as the interface to a class that implements its operator[]() and size() functions. 
// A class with a pure virtual function is called an abstract class.
class Container {
public:
    // A function declared virtual is called a virtual function.
    // The curious =0 syntax says the function is pure virtual;
    // that is, some class derived from Container must define the function.
    virtual double& operator[](int) = 0; // pure virtual function
    virtual int size() const = 0; // const member function
    // As is common for abstract classes, Container does not have a constructor. After all, it does not have any data to initialize.
    // Container does have a destructor and that destructor is virtual, so that classes derived from Container can provide implementations. 
    // Again, that is common for abstract classes because they tend to be manipulated through references or pointers, and 
    // someone destroying a Container through a pointer has no idea what resources are owned by its implementation;
    virtual ~Container() { } // destructor
};

// For Container to be useful, we have to implement a container that implements the functions required by its interface.
// The :public can be read as “is derived from” or “is a subtype of.”
// Class Vector_container is said to be derived from class Container, and class Container is said to be a base of class Vector_container.
// An alternative terminology calls Vector_container and Container subclass and superclass, respectively.
// The derived class is said to inherit members from its base class, so the use of base and derived classes is commonly referred to as inheritance.
class Vector_container : public Container { // Vector_container implements Container
public:
    Vector_container(int s) : v(s) { } // vector of s elements
    // Note that the member destructor (~Vector()) is implicitly invoked by its class’s destructor (~Vector_container()).
    ~Vector_container() {}

    // The members operator[]() and size() are said to override the corresponding members in the base class Container.
    // I used the explicit override to make clear what’s intended. 
    // The use of override is optional, but being explicit allows the compiler to catch mistakes, 
    // such as misspellings of function names or slight differences between the type of a virtual function and its intended overrider.
    double& operator[](int i) override { return v[i]; }
    int size() const override { return v.size(); }
private:
    Vector v;
};

// Container c;                                // error: there can be no objects of an abstract class
Container* p = new Vector_container(10);    // OK: Container is an interface

class List_container : public Container { // List_container implements Container
public:
    List_container() { } // empty List
    List_container(initializer_list<double> il) : ld{il} { }
    ~List_container() {}
    double& operator[](int i) override;
    int size() const override { return ld.size; }
private:
    std::list<double> ld; // (standard-library) list of doubles
};

double& List_container::operator[](int i)
{
    for (auto& x : ld) {
        if (i==)
            return x;
        --i;
    }
    throw out_of_range{"List container"};
}

// use() uses the Container interface in complete ignorance of implementation details. 
// It uses size() and [ ] without any idea of exactly which type provides their implementation.
// A class that provides the interface to a variety of other classes is often called a polymorphic type.
void use(Container& c)
{
    const int sz = c.size();

    for (int i=0;i!=sz;++i)
        cout << c[i] << '\n';
}

// use(Container&) has no idea if its argument is a Vector_container, a List_container, or some other kind of container; it doesn’t need to know. 
// It can use any kind of Container. It knows only the interface defined by Container. 
// Consequently, use(Container&) needn’t be recompiled if the implementation of List_container changes or a brand-new class derived from Container is used.
void g()
{
    Vector_container vc(10); // Vector of ten elements
    // ... fill vc ...
    use(vc);
}

void h()
{
    List_container ic = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    use(lc);
}

// The flip side of this flexibility is that objects must be manipulated through pointers or references.
