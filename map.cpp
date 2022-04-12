// @containers @map

// The standard library offers a balanced binary search tree (usually, a red-black tree) called map
// In other contexts, a map is known as an associative array or a dictionary. It is implemented as a balanced binary tree.

// The standard-library map is a container of pairs of values optimized for lookup. 
// We can use the same initializer as for vector and list
map<string,int> phone_book {
     {"David Hume",123456},
     {"Karl Popper",234567},
     {"Bertrand Arthur William Russell",345678}
};

// When indexed by a value of its first type (called the key), 
// a map returns the corresponding value of the second type (called the value or the mapped type).
// subscripting a map is essentially the lookup we called get_number().
// If a key isn’t found, it is entered into the map with a default value for its value.
// The default value for an integer type is 0;
int get_number(const string& s)
{
     return phone_book[s];
}

// Note the differences between a map and an unordered_map:
// A map requires an ordering function (the default is <) and yields an ordered sequence.
// A unordered_map requires a hash function and does not maintain an order among its elements.
