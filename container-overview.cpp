// @containers

// The containers are defined in namespace std and presented in headers <vector>, <list>, <map>, etc.
// In addition, the standard library provides container adaptors queue<T>, stack<T>, and priority_queue<T>.
// The standard library also provides more specialized container-like types, such as a fixed-size array array<T,N> and bitset<N>.

// Standard Container Summary
// vector<T> A variable-size vector 
// list<T> A doubly-linked list 
// forward_list<T> A singly-linked list
// deque<T> A double-ended queue
// set<T> A set (a map with just a key and no value)
// multiset<T> A set in which a value can occur many times
// map<K,V> An associative array 
// multimap<K,V> A map in which a key can occur many times
// unordered_map<K,V> A map using a hashed lookup 
// unordered_multimap<K,V> A multimap using a hashed lookup
// unordered_set<T> A set using a hashed lookup
// unordered_multiset<T> A multiset using a hashed lookup

// The standard containers and their basic operations are designed to be similar from a notational point of view.
// the meanings of the operations are equivalent for the various containers.
// Basic operations apply to every kind of container for which they make sense and can be efficiently implemented:

// This notational and semantic uniformity enables programmers to provide new container types that can be used in a very similar manner to the standard ones.
// The uniformity of container interfaces allows us to specify algorithms independently of individual container types.
// However, each has strengths and weaknesses.
// For example, subscripting and traversing a vector is cheap and easy. On the other hand, vector elements are moved when we insert or remove elements; 
// list has exactly the opposite properties.

// Standard Container Operations
// value_type The type of an element
// --------------------------------------------------------------------------------------------
// p=c.begin() p points to first element of c; also cbegin() for an iterator to const
// p=c.end() p points to one-past-the-last element of c; also cend() for an iterator to const
// k=c.size() k is the number of elements in c
// c.empty() Is c empty?
// k=c.capacity() k is the number of elements that c can hold without a new allocation
// c.reserve(k) Make the capacity k
// c.resize(k) Make the number of elements k; added elements has the value value_type{}
// c[k] The kth element of c; no range checking
// c.at(k) The kth element of c; if out of range, throw out_of_range
// c.push_back(x) Add x at the end of c; increase the size of c by one
// c.emplace_back(a) Add value_type{a} at the end of c; increase the size of c by one
// q=c.insert(p,x) Add x before p in c
// q=c.erase(p) Remove element at p from c
// --------------------------------------------------------------------------------------------
// = Assignment
// ==, != Equality of all elements of c
// <, <=, >, >= Lexicographical order

// An emplace operation, such as emplace_back() takes arguments for an element’s constructor and
// builds the object in a newly allocated space in the container, rather than copying an object into the container.
v.push_back(pair{1,"copy or move"));   // make a pair and move it into v
v.emplace_back(1,"build in place");    // buid a pair in v
