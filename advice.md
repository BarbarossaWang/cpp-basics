## The Basics

- Don't panic! All will become clear in time;
- Don't use the built-in feature exclusively  or on their own; On the contrary the fundamental (built-in) feature are usually best used indirectly through libraries, such as the ISO C++ standard library;
- Your don't have to know every detail of C++ to write good programs;
- Focus on programming techniques, not on language features;
- For the final word on language definition issues, see the ISO C++ standard;
- "Package" meaningful operations as carefully named functions;
- A function should perform a single logical operation;
- Keep function short;
- Use overloading when functions perform conceptually the same task on different types;
- If a function may have to be evaluated at compile time, declare it constexpr;
- Understand how language primitives map to hardware;
- Use digit separators to make large literals readable;
- Avoid complicated expressions;
- Avoid narrowing conversions;
- Minimize the scope of a variable;
- Avoid "magic constants"; use symbolic constants;
- Prefer immutable data;
- Declare one name (only) per declaration;
- Keep common and local names short, and keep uncommon and non-local names longer;
- Avoid similar-looking names;
- Avoid ALL_CAPS names;
- Prefer the {}-initializer syntax for declarations with a named types;
- Use auto to avoid repeating type names;
- Avoid uninitialized variables;
- Keep scopes small;
- When declaring a variable in the condition of an if-statement, prefer the version with the implicit test against 0;
- Use unsigned for bit manipulation only;
- Keep use of pointers simple and straightforward;
- Use nullptr rather than 0 and NULL;
- Don't declare a variable until you have a value to initialize it with;
- Don't say in comments what can be clearly stated in code;
- State intent in comments;
- Maintain a consistent indentation style; 

## User-Defined Types

- Prefer well-defined user-defined types over built-in types when the built-in types are too low-level;
- Organize related data into structures (structs or classes);
- Represent the distinction between an interface and an implementation using a class;
- A struct is simply a class with its members public by default;
- Define constructors to guarantee and simplify initialization of classes;
- Avoid “naked” unions; wrap them in a class together with a type field;
- Use enumerations to represent sets of named constants;
- Prefer class enums over “plain” enums to minimize surprises;
- Define operations on enumerations for safe and simple use;

## Modularity

- Distinguish between declarations (used as interfaces) and definitions (used as implementations);
- Use header files to represent interfaces and to emphasize logical structure;
- #include a header in the source file that implements its functions;
- Avoid non-inline function definitions in headers;
- Prefer modules over headers (where modules are supported);
- Use namespaces to express logical structure;
- Use using-directives for transition, for foundational libraries (such as std), or within a local scope;
- Don’t put a using-directive in a header file;
- Throw an exception to indicate that you cannot perform an assigned task;
- Use exceptions for error handling only; 
- Use error codes when an immediate caller is expected to handle the error;
- Throw an exception if the error is expected to perculate up through many function calls;
- If in doubt whether to use an exception or an error code, prefer exceptions;
- Develop an error-handling strategy early in a design;
- Use purpose-designed user-defined types as exceptions (not built-in types);
- Don’t try to catch every exception in every function;
- Prefer RAII to explicit try-blocks;
- If your function may not throw, declare it noexcept;
- Let a constructor establish an invariant, and throw if it cannot;
- Design your error-handling strategy around invariants;
- What can be checked at compile time is usually best checked at compile time;
- Pass “small” values by value and “large“ values by references;
- Prefer pass-by-const-reference over plain pass-by-reference;
- Return values as function-return values (rather than by out-parameters);
- Don’t overuse return-type deduction;
- Don’t overuse structured binding; using a named return type is often clearer documentation;

## Classes

- Express ideas directly in code;
- A concrete type is the simplest kind of class. Where applicable, prefer a concrete type over more complicated classes and over plain data structures;
- Use concrete classes to represent simple concepts;
- Prefer concerete classes over class hierarchies for performance-critical components;
- Define constructors to handle initialization of objects;
- Make a function a member only if it needs direct access to the representation of a class;
- Define operators primarily to mimic conventional usage;
- Use nonmember functions for symmetric operators;
- Declare a member function that does not modify the state of its object const;
- If a constructor acquires a resource, its class needs a destructor to release the resource;
- Avoid “naked” new and delete operations;
- Use resource handles and RAII to manage resources;
- If a class is a container, give it an initializer-list constructor;
- Use abstract classes as interfaces when complete separation of interface and implementation is needed;
- Access polymorphic objects through pointers and references;
- An abstract class typically doesn’t need a constructor;
- Use class hierarchies to represent concepts with inherent hierarchical structure;
- A class with a virtual function should have a virtual destructor;
- Use override to make overriding explicit in large class hierarchies;
- When designing a class hierarchy, distinguish between implementation inheritance and interface inheritance;
- Use dynamic_cast where class hierarchy navigation is unavoidable;
- Use dynamic_cast to a reference type when failure to find the required class is considered a failure;
- Use dynamic_cast to a pointer type when failure to find the required class is considered a valid alternative;
- Use unique_ptr or shared_ptr to avoid forgetting to delete objects created using new;

## Essential Operations

- Control construction, copy, move, and destruction of objects;
- Design constructors, assignments, and the destructor as a matched set of operations;
- Define all essential operations or none;
- If a default constructor, assignment, or destructor is appropriate, let the compiler generate it (don’t rewrite it yourself);
- If a class has a pointer member, it probably needs a user-defined or deleted destructor, copy and move;
- If a class has a destructor, it probably needs user-defined or deleted copy and move;
- By default, declare single-argument constructors explicit;
- If a class member has a reasonable default value, provide it as a data member initializer;
- Redefine or prohibit copying if the default is not appropriate for a type;
- Return containers by value (relying on move for efficiency);
- For large operands, use const reference argument types;
- Provide strong resource safety; that is, never leak anything that you think of as a resource;
- If a class is a resource handle, it needs a user-defined constructor, a destructor, and non-default copy operations;
- Overload operations to mimic conventional usage;
- Follow the standard-library container design;

## Templates
- Use templates to express algorithms that apply to many argument types;
- Use templates to express containers;
- Use templates to raise the level of abstraction of code;
- Templates are type safe, but checking happens too late;
- Let constructors or function templates deduce class template argument types;
- Use function objects as arguments to algorithms;
- Use a lambda if you need a simple function object in one place only;
- A virtual function member cannot be a template member function;
- Use template aliases to simplify notation and hide implementation details;
- To use a template, make sure its definition (not just its declaration) is in scope;
- Templates offer compile-time “duck typing”;
- There is no separate compilation of templates: #include template definitions in every translation unit that uses them.

## Concepts
- Templates provide a general mechanism for compile-time programming;
- When designing a template, carefully consider the concepts (requirements) assumed for its template arguments;
- When designing a template, use a concrete version for initial implementation, debugging, and measurement;
- Use concepts as a design tool;
- Specify concepts for all template arguments;
- Whenever possible use standard concepts (e.g., the Ranges concepts);
- Use a lambda if you need a simple function object in one place only;
- There is no separate compilation of templates: #include template definitions in every translation unit that uses them.
- Use templates to express containers and ranges;
- Avoid “concepts” without meaningful semantics;
- Require a complete set of operations for a concept;
- Use variadic templates when you need a function that takes a variable number of arguments of a variety of types;
- Don’t use variadic templates for homogeneous argument lists (prefer initializer lists for that);
- To use a template, make sure its definition (not just its declaration) is in scope;
- Templates offer compile-time “duck typing”;

## Library Overview

- Don’t reinvent the wheel; use libraries;
- When you have a choice, prefer the standard library over other libraries;
- Do not think that the standard library is ideal for everything;
- Remember to #include the headers for the facilities you use;
- Remember that standard-library facilities are defined in namespace std;

## Strings and Regular Expressions

- Use std::string to own character sequences;
- Prefer string operations to C-style string functions;
- Use string to declare variables and members rather than as a base class;
- Return strings by value (rely on move semantics);
- Directly or indirectly, use substr() to read substrings and replace() to write substrings;
- A string can grow and shrink, as needed;
- Use at() rather than iterators or [ ] when you want range checking;
- Use iterators and [ ] rather than at() when you want to optimize speed;
- string input doesn’t overflow;
- Use c_str() to produce a C-style string representation of a string (only) when you have to;
- Use a stringstream or a generic value extraction function (such as to\<X\>) for numeric conversion of strings;
- A basic_string can be used to make strings of characters on any type;
- Use the s suffix for string literals meant to be standard-library strings;
- Use string_view as an argument of functions that needs to read character sequences stored in various ways;
- Use gsl::string_span as an argument of functions that needs to write character sequences stored in various ways;
- Think of a string_view as a kind of pointer with a size attached; it does not own its characters;
- Use the sv suffix for string literals meant to be standard-library string_views;
- Use regex for most conventional uses of regular expressions;
- Prefer raw string literals for expressing all but the simplest patterns;
- Use regex_match() to match a complete input;
- Use regex_search() to search for a pattern in an input stream;
- The regular expression notation can be adjusted to match various standards;
- The default regular expression notation is that of ECMAScript;
- Be restrained; regular expressions can easily become a write-only language;
- Note that \i allows you to express a subpattern in terms of a previous subpattern;
- Use ? to make patterns “lazy”;
- Use regex_iterators for iterating over a stream looking for a pattern;

## Input and Output

- iostreams are type-safe, type-sensitive, and extensible;
- Use character-level input only when you have to;
- When reading, always consider ill-formed input;
- Avoid endl;
- Define << and >> for user-defined types with values that have meaningful textual representations;
- Use cout for normal output and cerr for errors;
- There are iostreams for ordinary characters and wide characters, and you can define an iostream for any kind of character;
- Binary I/O is supported;
- There are standard iostreams for standard I/O streams, files, and strings;
- Chain << operations for a terser notation;
- Chain >> operations for a terser notation;
- Input into strings does not overflow;
- By default >> skips initial whitespace;
- Use the stream state fail to handle potentially recoverable I/O errors;
- You can define << and >> operators for your own types;
- You don’t need to modify istream or ostream to add new << and >> operators;
- Use manipulators to control formatting;
- precision() specifications apply to all following floating-point output operations;
- Floating-point format specifications (e.g., scientific) apply to all following floating-point output operations;
- #include \<ios\> when using standard manipulators;
- #include \<iomanip\> when using standard manipulators taking arguments;
- Don’t try to copy a file stream.
- Remember to check that a file stream is attached to a file before using it;
- Use stringstreams for in-memory formatting;
- You can define conversions between any two types that both have string representation;
- C-style I/O is not type-safe;
- Unless you use printf-family functions call ios_base::sync_with_stdio(false); §10.9;
- Prefer \<filesystem\> to direct use of a specific operating system interfaces;

## Containers

- An STL container defines a sequence;
- STL containers are resource handles;
- Use vector as your default container;
- For simple traversals of a container, use a range-for loop or a begin/end pair of iterators;
- Use reserve() to avoid invalidating pointers and iterators to elements;
- Don’t assume performance benefits from reserve() without measurement;
- Use push_back() or resize() on a container rather than realloc() on an array;
- Don’t use iterators into a resized vector;
- Do not assume that [ ] range checks;
- Use at() when you need guaranteed range checks;
- Use range-for and standard-library algorithms for cost-free avoidance of range errors;
- Elements are copied into a container;
- To preserve polymorphic behavior of elements, store pointers;
- Insertion operators, such as insert() and push_back(), are often surprisingly efficient on a vector;
- Use forward_list for sequences that are usually empty;
- When it comes to performance, don’t trust your intuition: measure;
- A map is usually implemented as a red-black tree;
- An unordered_map is a hash table;
- Pass a container by reference and return a container by value;
- For a container, use the ()-initializer syntax for sizes and the {}-initializer syntax for lists of elements;
- Prefer compact and contiguous data structures;
- A list is relatively expensive to traverse;
- Use unordered containers if you need fast lookup for large amounts of data;
- Use ordered associative containers (e.g., map and set) if you need to iterate over their elements in order;
- Use unordered containers for element types with no natural order (e.g., no reasonable <);
- Experiment to check that you have an acceptable hash function;
- A hash function obtained by combining standard hash functions for elements using the exclusive-or operator (^) is often good;
- Know your standard-library containers and prefer them to handcrafted data structures;

## Algorithms

- An STL algorithm operates on one or more sequences;
- An input sequence is half-open and defined by a pair of iterators;
- When searching, an algorithm usually returns the end of the input sequence to indicate “not found”;
- Algorithms do not directly add or subtract elements from their argument sequences;
- When writing a loop, consider whether it could be expressed as a general algorithm;
- Use predicates and other function objects to give standard algorithms a wider range of meanings;
- A predicate must not modify its argument;
- Know your standard-library algorithms and prefer them to hand-crafted loops;
- When the pair-of-iterators style becomes tedious, introduce a container/range algorithm;

## Utilities

- A library doesn’t have to be large or complicated to be useful;
- A resource is anything that has to be acquired and (explicitly or implicitly) released;
- Use resource handles to manage resources (RAII);
- Use unique_ptr to refer to objects of polymorphic type;
- Use shared_ptr to refer to shared objects (only);
- Prefer resource handles with specific semantics to smart pointers;
- Prefer unique_ptr to shared_ptr;
- Use make_unique() to construct unique_ptrs;
- Use make_shared() to construct shared_ptrs;
- Prefer smart pointers to garbage collection;
- Don’t use std::move();
- Use std::forward() exclusively for forwarding;
- Never read from an object after std::move()ing or std::forward()ing it;
- Prefer spans to pointer-plus-count interfaces;
- Use array where you need a sequence with a constexpr size;
- Prefer array over built-in arrays;
- Use bitset if you need N bits and N is not necessarily the number of bits in a built-in integer type;
- Don’t overuse pair and tuple; named structs often lead to more readable code;
- When using pair, use template argument deduction or make_pair() to avoid redundant type specification;
- When using tuple, use template argument deduction and make_tuple() to avoid redundant type specification;
- Prefer variant to explicit use of unions;
- Use allocators to prevent memory fragmentation;
- Time your programs before making claims about efficiency;
- Use duration_cast to report time measurements with proper units;
- When specifying a duration, use proper units;
- Use mem_fn() or a lambda to create function objects that can invoke a member function when called using the traditional function call notation;
- Use function when you need to store something that can be called;
- You can write code to explicitly depend on properties of types;
- Prefer concepts over traits and enable_if whenever you can;
- Use aliases and type predicates to simplify notation;
