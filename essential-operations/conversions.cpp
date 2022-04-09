// @essential-operations @converisons @explicit

// Use explicit for constructors that take a single argument unless there is a good reason not to.

// A constructor taking a single argument defines a conversion from its argument type.
complex z1 = 3.14;  // z1 becomes {3.14,0.0}
complex z2 = z1*2;  // z2 becomes z1*{2.0,0} == {6.28,0.0}

// This implicit conversion is sometimes ideal, but not always.
// The way to avoid this problem is to say that only explicit “conversion” is allowed;
class Vector {
public:
    explicit Vector(int s);    // no implicit conversion from int to Vector
    // ...
};

Vector v1(7);   // OK: v1 has 7 elements
Vector v2 = 7;  // error: no implicit conversion from int to Vector
