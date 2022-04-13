// @containers @utilities @array @specialized-containers

// An array, defined in <array>, is a fixed-size sequence of elements of a given type where the number of elements is specified at compile time.
// an array can be allocated with its elements on the stack, in an object, or in static storage.
// The elements are allocated in the scope where the array is defined.

// An array is best understood as a built-in array with 
// its size firmly attached, 
// without implicit, potentially surprising conversions to pointer types, and 
// with a few convenience functions provided.

// There is no overhead (time or space) involved in using an array compared to using a built-in array.

// An array does not follow the “handle to elements” model of STL containers. Instead, an array directly contains its elements.

// An array can be initialized by an initializer list:
// The number of elements in the initializer must be equal to or less than the number of elements specified for the array.
// The element count is not optional:
// The element count must be a constant expression:
array<int,3> a1 = {1,2,3};

array<int> ax = {1,2,3};     // error size not specified

void f(int n)
{
     array<string,n> aa = {"John's", "Queens' "};     // error: size not a constant expression
     //
}

// When necessary, an array can be explicitly passed to a C-style function that expects a pointer.
void f(int* p, int sz);    // C-style interface

void g()
{
     array<int,10> a;

     f(a,a.size());             // error: no conversion
     f(&a[0],a.size());         // C-style use
     f(a.data(),a.size());      // C-style use

     auto p = find(a.begin(),a.end(),777);    // C++/STL-style use
     // ...
}

// Why would we use an array when vector is so much more flexible?
// If you need the element count to be a variable, use vector.
// An array is less flexible so it is simpler. 
// Occasionally, there is a significant performance advantage to be had by directly accessing elements allocated on the stack 
// rather than allocating elements on the free store, 
// accessing them indirectly through the vector (a handle), and 
// then deallocating them.

// Why would we use an array when we could use a built-in array?
// An array knows its size, so it is easy to use with standard-library algorithms, and it can be copied using =.
// main reason to prefer array is that it saves me from surprising and nasty conversions to pointers.
void h()
{
    Circle a1[10];
    array<Circle,10> a2;
    // ...
    Shape* p1 = a1;    // OK: disaster waiting to happen
    Shape* p2 = a2;    // error: no conversion of array<Circle,10> to Shape*
    // The “disaster” comment assumes that sizeof(Shape)<sizeof(Circle), 
    // so subscripting a Circle[] through a Shape* gives a wrong offset.
    p1[3].draw();      // disaster
}
