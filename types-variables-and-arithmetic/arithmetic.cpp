// @types @variables @arithmetic

// C++ offers a direct mapping to hardware. When you use one of the fundamental operations, the implementation is what the hardware offers, typically a single machine operation. 
// For example, adding two ints, x+y executes an integer add machine instruction.

// The order of evaluation of expressions is left to right, except for assignments, which are right-to-left. 
// The order of evaluation of function arguments is unfortunately unspecified.

// fundamental operators
x+y     // plus
+x      // unary plus
x-y     // minus
-x      // unary minus
x*y     // multiply
x/y     // divide
x%y     // remainder (modulus) for integers

// comparison operators
x==y     // equal
x!=y     // not equal
x<y      // less than
x>y      // greater than
x<=y     // less than or equal
x>=y     // greater than or equal

// logical operators
x&y      // bitwise and
x|y      // bitwise or
x^y      // bitwise exclusive or
~x       // bitwise complement
x&&y     // logical and
x||y     // logical or
!x       // logical not (negation)

// operations for modifying a variable
x+=y     // x = x+y
++x      // increment: x = x+1
x−=y     // x = x-y
−−x      // decrement: x = x-1
x*=y     // scaling: x = x*y
x/=y     // scaling: x = x/y
x%=y     // x = x%y

// The conversions used in expressions are called the usual arithmetic conversions and 
// aim to ensure that expressions are computed at the highest precision of its operands.
void some_function()    // function that doesn't return a value
{
     double d = 2.2;    // initialize floating-point number
     int i = 7;         // initialize integer
     d = d+i;           // assign sum to d
     i = d*i;           // assign product to i; beware: truncating the double d*i to an int
}
