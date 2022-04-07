// @basics @types @variables @arithmetic

// Every name and every expression has a type that determines the operations that may be performed on it.
int inch;

// A declaration is a statement that introduces an entity into the program. It specifies a type for the entity:
// A type defines a set of possible values and a set of operations (for an object).
// An object is some memory that holds a value of some type.
// A value is a set of bits interpreted according to a type.
// A variable is a named object.

// A char variable is of the natural size to hold a character on a given machine (typically an 8-bit byte), and 
// the sizes of other types are quoted in multiples of the size of a char.
// The size of a type is implementation-defined (i.e., it can vary among different machines) and 
// can be obtained by the sizeof operator.
sizeof(char) // 1
sizeof(int) // 4

// Numbers can be floating-point or integers.
// Floating-point numbers are recognized by a decimal point (e.g., 3.14) or by an exponent (e.g., 3e-2).
// Integer literals are by default decimal. 
// A 0b prefix indicates a binary (base 2) integer literal. 
// A 0x prefix indicates a hexadecimal (base 16) integer literal. 
// A 0 prefix indicates an octal (base 8) integer literal.

// To make long literals more readable for humans, we can use a single quote (') as a digit separator.

