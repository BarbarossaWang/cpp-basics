// @classes @virtual-functions @vtbl

// The compiler to convert the name of a virtual function into an index into a table of pointers to functions. 
// That table is usually called the virtual function table or simply the vtbl. 
// Each class with virtual functions has its own vtbl identifying its virtual functions.

// This virtual call mechanism can be made almost as efficient as the “normal function call” mechanism (within 25%). 
// Its space overhead is one pointer in each object of a class with virtual functions plus one vtbl for each such class.

// Vector_container: --> | vtbl |
//      v                |      |----> Vector_container::operator[]()
//                       |      |----> Vector_container::size()
//                       |      |----> Vector_container::~Vector_container()

// List_container: --> | vtbl |
//      ld             |      |----> List_container::operator[]()
//                     |      |----> List_container::size()
//                     |      |----> List_container::~List_container()
