// @pointers @arrays @references @basics @range-for-statement @for-statement @declarator-operators @null-pointer

// There is no null reference. A reference must refer to a valid object (and implementations assume that it does). 

// When used in declarations, operators (such as &, *, and [ ]) are called declarator operators:
T a[n]    // T[n]: a is an array of n Ts
T* p      // T*: p is a pointer to T
T& r      // T&: r is a reference to T
T f(A)    // T(A): f is a function taking an argument of type A returning a result of type T

// The most fundamental collection of data is a contiguously allocated sequence of elements of the same type, called an array.
// In declarations, [ ] means array of and 
// * means pointer to. 
// All arrays have 0 as their lower bound. 
// The size of an array must be a constant expression.
char v[6];        // array of 6 characters
char* p;        // pointer to character

// In an expression, prefix unary * means contents of and 
// prefix unary & means address of.
char* p = &v[3];        // p points to v's fourth element
char x = *p;            // *p is the object that p points to

void copy_fct()
{
     int v1[10] = {0,1,2,3,4,5,6,7,8,9};
     int v2[10];                 // to become a copy of v1

     for (auto i=0; i!=10; ++i)  // copy elements
           v2[i]=v1[i];
     // ...
}

// a range-for-statement, for loops that traverse a sequence in the simplest way:
void print()
{
     int v[] = {0,1,2,3,4,5,6,7,8,9};

     // Note that we don’t have to specify an array bound when we initialize it with a list. 
     // The range-for-statement can be used for any sequence of elements
     for (auto x : v)             // for each x in v
           cout << x << '\n';

     for (auto x : {10,21,32,43,54,65})
           cout << x << '\n';
     // ...
}

// If we didn't want to copy the values from v into the variable x, but rather just have x refer to an element, we could write:
void increment()
{
    int v[] = {0,1,2,3,4,5,6,7,8,9};
    // In a declaration, the unary suffix & means reference to A reference is similar to a pointer, 
    // except that you don't need to use a prefix * to access the value referred to by the reference.
    // Also, a reference cannot be made to refer to a different object after its initialization.
    for (auto& x : v)     // add 1 to each x in v
        ++x;
    // ...
}

// When we don't want to modify an argument but still don't want the cost of copying, we use a const reference
double sum(const vector<double>&)

// When we don't have an object to point to or if we need to represent the notion of no object available (e.g., for an end of a list), 
// we give the pointer the value nullptr (the null pointer). There is only one nullptr shared by all pointer types:
double* pd = nullptr;
Link<Record>* lst = nullptr;  // pointer to a Link to a Record
int x = nullptr;              // error: nullptr is a pointer not an integer

// It is often wise to check that a pointer argument actually points to something.
int count_x(const char* p, char x)
    // count the number of occurrences of x in p[]
    // p is assumed to point to a zero-terminated array of char (or to nothing)
{
    if (p==nullptr)
          return 0;
    int count = 0;
    // we are not using the initializer part of the for-statement, so we can use the simpler while-statement.
    // while (*p) {
    //     if (*p==x)
    //         ++count;
    //     ++p;
    // }
    for (; *p!=0; ++p)
          if (*p==x)
                ++count;
    return count;
}

// A reference and a pointer both refer/point to an object and both are represented in memory as a machine address. 
// However, the language rules for using them differ.
int x = 2;
int y = 3;
int* p = &x;
int* q = &y;    // now p!=q and *p!=*q
p = q;          // p becomes &y; now p==q, so (obviously)*p == *q
// To access the value pointed to by a pointer, you use *; that is automatically (implicitly) done for a reference.
int& r = x;     // r refers to x
int& r2 = y;    // now r2 refers to y
r = r2;         // read through r2, write through r: x becomes 3
