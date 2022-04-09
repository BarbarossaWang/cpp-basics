// @essential-operations @member-initializers @default

// When a data member of a class is defined, we can supply a default initializer called a default member initializer.
class complex {
    double re = 0;
    double im = 0; // representation: two doubles with default value 0.0
public:
    complex(double r, double i) :re{r}, im{i} {}    // construct complex from two scalars: {r,i}
    complex(double r) :re{r} {}                     // construct complex from one scalar: {r,0}
    complex() {}                                    // default complex: {0,0}
    // ...
}
