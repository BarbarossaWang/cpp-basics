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
