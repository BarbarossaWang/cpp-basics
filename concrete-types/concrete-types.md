@concrete-types @classes

# Concrete Types

The basic idea of concrete classes is that they behave “just like built-in types.”

The defining characteristic of a concrete type is that its representation is part of its definition.

In many important cases, such as a vector, that representation is only one or more pointers to data stored elsewhere, 
but that representation is present in each object of a concrete class. That allows implementations to be optimally efficient in time and space. 
In particular, it allows us to:
- place objects of concrete types on the stack, in statically allocated memory, and in other objects;
- refer to objects directly (and not just through pointers or references);
- initialize objects immediately and completely (e.g., using constructors);
- copy and move objects;

The representation can be private (as it is for Vector;) and accessible only through the member functions, but it is present.

If the representation changes in any significant way, a user must recompile. This is the price to pay for having concrete types behave exactly like built-in types.
- For types that don’t change often, and where local variables provide much-needed clarity and efficiency, this is acceptable and often ideal. 

To increase flexibility, a concrete type can keep major parts of its representation on the free store (dynamic memory, heap) and access them through the part stored in the class object itself.
- That’s the way vector and string are implemented;
