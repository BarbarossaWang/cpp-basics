// @algorithm @iterators @iterator-types

// These iterator types can be as different as the containers and the specialized needs they serve.

// a vector’s iterator could be an ordinary pointer, because a pointer is quite a reasonable way of referring to an element of a vector
// a vector iterator could be implemented as a pointer to the vector plus an index, using such an iterator would allow range checking

// a list iterator might be a pointer to a link

// What is common for all iterators is their semantics and the naming of their operations.
// For example, applying ++ to any iterator yields an iterator that refers to the next element. 
// Similarly, * yields the element to which the iterator refers.
// n fact, any object that obeys a few simple rules like these is an iterator – Iterator is a concept.

// Furthermore, users rarely need to know the type of a specific iterator; 
// each container “knows” its iterator types and makes them available under the conventional names iterator and const_iterator
