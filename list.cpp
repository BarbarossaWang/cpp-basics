// @containers @list @forward_list

// The standard library offers a doubly-linked list called list
// We use a list for sequences where we want to insert and delete elements without moving other elements.

// These list examples could be written identically using vector and 
// (surprisingly, unless you understand machine architecture) perform better with a small vector than with a small list.
// Unless you have a reason not to, use a vector. 
// A vector performs better for traversal (e.g., find() and count()) and for sorting and searching (e.g., sort() and equal_range();

list<Entry> phone_book = {
     {"David Hume",123456},
     {"Karl Popper",234567},
     {"Bertrand Arthur William Russell",345678}
};

// we might search the list looking for an element with a given value.
// The search for s starts at the beginning of the list and proceeds until s is found or the end of phone_book is reached.
int get_number(const string& s)
{
     for (const auto& x : phone_book)
          if (x.name==s)
                return x.number;
     return 0; // use 0 to represent "number not found"
}

// Sometimes, we need to identify an element in a list.
// To do that we use an iterator: a list iterator identifies an element of a list and can be used to iterate through a list (hence its name).
// Every standard-library container provides the functions begin() and end(), which return an iterator to the first and to one-past-the-last element, respectively.
// In fact, this is roughly the way the terser and less error-prone range-for loop is implemented by the compiler.
// Given an iterator p, *p is the element to which it refers, ++p advances p to refer to the next element, and 
// when p refers to a class with a member m, then p−>m is equivalent to (*p).m.
int get_number(const string& s)
{
     for (auto p = phone_book.begin(); p!=phone_book.end(); ++p)
          if (p−>name==s)
                return p−>number;
     return 0; // use 0 to represent "number not found"
}

void f(const Entry& ee, list<Entry>::iterator p, list<Entry>::iterator q)
{ 
    // For a list, insert(p,elem) inserts an element with a copy of the value elem before the element pointed to by p.
    // Here, p may be an iterator pointing one-beyond-the-end of the list.
     phone_book.insert(p,ee);     // add ee before the element referred to by p
    // erase(p) removes the element pointed to by p and destroys it.
     phone_book.erase(q);         // remove the element referred to by q
}

// The standard library also offers a singly-linked list called forward_list:
// A forward_list differs from list by only allowing forward iteration. 
// The real point of that is to save space.
// A forward_list doesn’t even keep its number of elements. 
// If you need the element count, you can count.

// Consider the singly-linked list, forward_list, a container optimized for the empty sequence.
// An empty forward_list occupies just one word, whereas an empty vector occupy three.
