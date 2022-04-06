// @function-arguments

// When we care about performance, we usually pass small values by-value and larger ones by-reference.
// Here “small” means “something that’s really cheap to copy.”
// Exactly what “small” means depends on machine architecture, but “the size of two or three pointers or less” is a good rule of thumb.

// If we want to pass by reference for performance reasons but don’t need to modify the argument, we pass-by-const-reference

void test(vector<int> v, vector<int>& rv)       // v is passed by value; rv is passed by reference
{
     v[1] = 99;     // modify v (a local variable)
     rv[2] = 66;    // modify whatever rv refers to
}

int main()
{
     vector fib = {1,2,3,5,8,13,21};
     test(fib,fib);
     cout << fib[1] << '' << fib[2] << '\n';     // prints 2 66
}

// We can specify such a default by a default function argument.
void print(int value, int base =10) // print value in base "base"

print(x, 16);
print(x, 60);
print(x);

// This is a notationally simpler alternative to overloading:
void print(int value, int base);    // print value in base "base"

void print(int value)               // print value in base 10
{
     print(value,10);
}

