// @copy @move

// When we design a class, we must always consider if and how an object might be copied.

// By default, objects can be copied. This is true for objects of user-defined types as well as for built-in types. 
// The default meaning of copy is memberwise copy: copy each member.
void test(complex z1)
{
    complex z2 {z1};    // copy initialization
    complex z3;
    // Now z1, z2, and z3 have the same value because both the assignment and the initialization copied both members.
    z3 = z2;            // copy assignment
    // ...
}
