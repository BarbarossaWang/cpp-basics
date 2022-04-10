// @template @concepts @template-compilation-model

// Assuming concepts, the arguments for a template are checked against its concepts.
// Errors found here will be reported and the programmer has to fix the problems.
// What cannot be checked at this point, such as arguments for unconstrained template arguments, 
// is postponed until code is generated for the template and a set of template arguments: “at template instantiation time.”
// For pre-concept code, this is where all type checking happens. When using concepts, we get here only after concept checking succeeded.

// An unfortunate side effect of instantiation-time (late) type checking is that a type error can be found uncomfortably late and can result in spectacularly bad error messages 
// because the compiler found the problem only after combining information from several places in the program.

// The instantiation-time type checking provided for templates checks the use of arguments in the template definition.
// This provides a compile-time variant of what is often called duck typing (“If it walks like a duck and it quacks like a duck, it’s a duck”).
// Or – using more technical terminology – we operate on values, and the presence and meaning of an operation depend solely on its operand values.

// This differs from the alternative view that objects have types, which determine the presence and meaning of operations. Values “live” in objects.
// This is the way objects (e.g., variables) work in C++, and only values that meet an object’s requirements can be put into it.

// What is done at compile time using templates mostly does not involve objects, only values.
// The exception is local variables in a constexpr function that are used as objects inside the compiler.

// To use an unconstrained template, its definition (not just its declaration) must be in scope at its point of use.
// For example, the standard header <vector> holds the definition of vector.

// In practice, this means that template definitions are typically found in header files, rather than .cpp files.
// This changes when we start to use modules.
// Using modules, the source code is organized in the same way for ordinary functions and template functions. 
// In both cases, definitions will be protected against the problems of textual inclusion.
