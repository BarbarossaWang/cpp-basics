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
