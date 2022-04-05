// @enumerations @enumerator @enum
// Enumerations are used to represent small sets of integer values.
// They are used to make code more readable and less error-prone 
// than it would have been had the symbolic (and mnemonic) enumerator names not been used.

enum class Color { red, blue, green };
enum class Traffic_light { green, yellow, red };

// Note that enumerators are in the scope of their enum class, 
// so that they can be used repeatedly in different enum classes without confusion.

Color col = Color::red;
Traffic_light light = Traffic_light::red;

// The class after the enum specifies that an enumeration is strongly typed and that its enumerators are scoped.
// Color x = red; // error: which red?
// Color y = Traffic_light::red // error: that red is not a color

// We cannot implicitly mix Color and integer values.
// int i = Color::red; // error: Color::red is not an int
// Color c = 2; // initialization error: 2 is not a Color

// That is allowed explicit conversion form the underlying type (by default is int) in initialize an enum with a value.
Color x = Color{5};
Color y {6};

// By default, an enum class has only assignment, initialization, and comparisons defined.
// an enumeration is a user-defined type, so we can define operators for it:
Traffic_light& operator++(Traffic_light& t) // prefix increment: ++
{
    switch (t) {
    case Traffic_light::green:        return t=Traffic_light::yellow;
    case Traffic_light::yellow:       return t=Traffic_light::red;
    case Traffic_light::red:          return t=Traffic_light::green;
    }
}

Traffic_light next = ++light; // next becomes Traffic_light::green

// @plain-enum enumerator values is ints without the need for an explicit conversion.
// The enumerators from a “plain” enum are entered into the same scope as the name of their enum and
// implicitly converts to their integer value.
// By default, the integer values of enumerators start with 0 and increase by one for each additional enumerator. 
//            0     1     2
enum Color { red, green, blue};
