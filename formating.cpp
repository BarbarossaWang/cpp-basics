// @I/O @formatting

// The simplest formatting controls are called manipulators and 
// are found in <ios>, <istream>, <ostream>, and <iomanip> (for manipulators that take arguments).

// These floating-point manipulators are “sticky”; that is, their effects persist for subsequent floating-point operations.

// We can output integers as decimal (the default), octal, or hexadecimal numbers:
cout << 1234 << ',' << hex << 1234 << ',' << oct << 1234 << '\n';        // print 1234,4d2,2322

// We can explicitly set the output format for floating-point numbers:
constexpr double d = 123.456;

// The general format (defaultfloat) lets the implementation choose a format that presents a value in the style that best preserves the value in the space available. 
// The precision specifies the maximum number of digits.
cout << d << "; "                    // use the default format for d
    // The scientific format (scientific) presents a value with one digit before a decimal point and an exponent. 
    // The precision specifies the maximum number of digits after the decimal point.
    << scientific << d << "; "      // use 1.123e2 style format for d
    << hexfloat << d << "; "        // use hexadecimal notation for d
    // The fixed format (fixed) presents a value as an integer part followed by a decimal point and a fractional part. 
    // The precision specifies the maximum number of digits after the decimal point.
    << fixed << d << "; "           // use 123.456 style format for d
    << defaultfloat << d << '\n';   // use the default format for d
// Output:
// 123.456; 1.234560e+002; 0x1.edd2f2p+6; 123.456000; 123.456

// Floating-point values are rounded rather than just truncated, and 
// precision() doesn’t affect integer output.
cout.precision(8);
cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << '\n';

cout.precision(4);
cout << 1234.56789 << ' ' << 1234.56789 << ' ' << 123456 << '\n';
cout << 1234.56789 << '\n';
// Output
// 1234.5679 1234.5679 123456
// 1235 1235 123456
// 1235
