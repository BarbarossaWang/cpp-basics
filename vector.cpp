// @vector @containers @elements @range-checking

// A vector is a sequence of elements of a given type. 
// The elements are stored contiguously in memory.

// A typical implementation of vector will consist of 
// a handle holding pointers to the first element, 
// one-past-the-last element, and 
// one-past-the-last allocated space
// or the equivalent information represented as a pointer plus offsets
// In addition, it holds an allocator (here, alloc), from which the vector can acquire memory for its elements.
// The default allocator uses new and delete to acquire and release memory.

// We can initialize a vector with a set of values of its element type:
vector<Entry> phone_book = {
    {"David Hume",123456},
    {"Karl Popper",234567},
    {"Bertrand Arthur William Russell",345678}
};

// Elements can be accessed through subscripting. So, assuming that we have defined << for Entry,
void print_book(const vector<Entry>& book)
{
    // The vector member function size() gives the number of elements.
    // indexing starts at 0 so that book[0] holds the entry for David Hume.
    for (int i = 0; i!=book.size(); ++i)
        cout << book[i] << '\n';
}

// The elements of a vector constitute a range, so we can use a range-for loop
void print_book(const vector<Entry>& book)
{
    for (const auto& x : book)     
        cout << x << '\n';
}

// When we define a vector, we give it an initial size (initial number of elements):
vector<int> v1 = {1, 2, 3, 4};     // sizeis4
vector<string> v2;                 // sizeis0
vector<Shape*> v3(23);             // size is 23; initial element value: nullptr
vector<double> v4(32,9.9);         // size is 32; initial element value: 9.9

// The initial size can be changed.
// One of the most useful operations on a vector is push_back(), which adds a new element at the end of a vector, increasing its size by one.
// Assuming that we have defined >> for Entry, we can write:
void input()
{
     for (Entry e; cin>>e;)
           phone_book.push_back(e);
}

// The standard-library vector is implemented so that growing a vector by repeated push_back()s is efficient.
template<typename T>
class Vector {
     T* elem;     // pointer to first element
     T* space;    // pointer to first unused (and uninitialized) slot
     T* last;     // pointer to last slot
public:
     // ...
     int size();                     // number of elements (space-elem)
     int capacity();                 // number of slots available for elements (last-elem)
     // ...
     // The reserve() is used by users of vector and other vector members to make room for more elements.
     // It may have to allocate new memory and when it does, it moves the elements to the new allocation.
     // Only explicitly use reserve() to avoid reallocation of elements when I want to use pointers to elements.
     void reserve(int newsz);        // increase capacity() to newsz
     // ...
     void push_back(const T& t);     // copy t into Vector
     void push_back(T&& t);          // move t into Vector
};

template<typename T>
void Vector<T>::push_back(const T& t)
{
     if (capacity()<size()+1)             // make sure we have space for t
           reserve(size()==0?8:2*size()); // double the capacity
     new(space) T{t};                     // initialize *space to t
     ++space;
}

// A vector can be copied in assignments and initializations.
// Copying and moving of vectors are implemented by constructors and assignment operators
// Where copying is undesirable, references or pointers or move operations should be used.
vector<Entry> book2 = phone_book;

/************
 * @elements
 ************/

// vector is a container of elements of some type T, that is, a vector<T>. 
// Just about any type qualifies as an element type:

// When you insert a new element, its value is copied into the container.

// If your have a class hierarchy that relies on virtual funcitons to get polymorphic,
// do not store objects directly in a container.
// Instead store a pointer (or a smart pointer;
vector<Shape> vs;                  // No, don't - there is no room for a Circle or a Smiley
vector<Shape*> vps;                // better, but see class-hierarchy 
vector<unique_ptr<Shape>> vups;    // OK


/************
 * @range-checking
 ************/

// The standard-library vector does not guarantee range checking.
// Many performance-critical applications use vectors and checking all subscripting implies a cost on the order of 10%.
// A range-for avoids range errors at no cost by accessing elements through iterators in the range [begin():end()). 
// As long as their iterator arguments are valid, the standard-library algorithms do the same to ensure the absence of range errors.
void silly(vector<Entry>& book)
{
     int i = book[book.size()].number;     // book.size() is out of range
     // ...
}

// I often use a simple range-checking adaptation of vector
// If you can use vector::at() directly in your code, you don’t need my Vec workaround.
template<typename T>
// Vec inherits everything from vector except for the subscript operations that it redefines to do range checking.
class Vec : public std::vector<T> {
public:
    using vector<T>::vector;                // use the constructors from vector (under the name Vec)

    T& operator[](int i)                    // range check
        // The at() operation is a vector subscript operation that 
        // throws an exception of type out_of_range if its argument is out of the vector’s range.
        { return vector<T>::at(i); }

    const T& operator[](int i) const        // range check const objects; 
        { return vector<T>::at(i); }
};

// For Vec, an out-of-range access will throw an exception that the user can catch.
void checked(Vec<Entry>& book)
{
    // The exception will be thrown, and then caught.
    // If the user doesn’t catch an exception, the program will terminate in a well-defined manner rather than 
    // proceeding or failing in an undefined manner.
     try{
          book[book.size()] = {"Joe",999999};     // will throw an exception
          // ...
     }
     catch (out_of_range&) {
          cerr << "range error\n";
     }
}

// One way to minimize surprises from uncaught exceptions is to use a main() with a try-block as its body.
int main()
try{
     // your code
}
catch (out_of_range&) {
     cerr << "range error\n";
}
catch (...) {
     cerr << "unknown exception thrown\n";
}

