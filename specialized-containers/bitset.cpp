// @containers @specialized-containers @bitset @utilities

// Aspects of a system, such as the state of an input stream, are often represented as a set of flags indicating binary conditions such as good/bad, true/false, and on/off.

// C++ supports the notion of small sets of flags efficiently through bitwise operations on integers.
// Class bitset<N> generalizes this notion by providing operations on a sequence of N bits [0:N), where N is known at compile time.

// or sets of bits that don’t fit into a long long int, using a bitset is much more convenient than using integers directly.
// For smaller sets, bitset is usually optimized.

// If you want to name the bits, rather than numbering them, you can use a set or enumeration.

// A bitset can be initialized with an integer or a string:
bitset<9> bs1 {"110001111"};
bitset<9> bs2 {0b1'1000'1111};     // binary literal using digit separators

// The usual bitwise operators and the left- and right-shift operators (<< and >>) can be applied:
bitset<9> bs3 = ~bs1;       // complement: bs3=="001110000"
bitset<9> bs4 = bs1&bs3;    // all zeros
// The shift operators (here, <<) “shift in” zeros.
bitset<9> bs5 = bs1<<2;     // shift left: bs5 = "000111100"

// The operations to_ullong() and to_string() provide the inverse operations to the constructors.
// we could write out the binary representation of an int:
void binary(int i)
{
    bitset<8*sizeof(int)>b = i;        // assume 8-bit byte
    cout << b.to_string() << '\n';     // write out the bits of i
    // directly use the bitset ouput operator
    cout << b << '\n';             // write out the bits of i
}
// This prints the bits represented as 1s and 0s from left to right, with the most significant bit leftmost,
// argument 123 would give the output
// 00000000000000000000000001111011
