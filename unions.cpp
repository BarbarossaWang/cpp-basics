// @union @Type
// A union is struct in which all members are allocated at the same address 
// so that the union occupies only as much space as its largest member.

enum Type { ptr, num }; // a Type can hold values ptr and num

// p and i are never used at the same time, 
// so can specify that both should be members of a union
union Value {
    Node* p;
    int i;
};

// A symbol table entry that holds a name and a value. The value can either be a Node* or an int
struct Entry {
    String name;
    Type t;
    // Language doesn't keep track of which kind of value is held by a union
    // use v.p if t==ptr; use v.i if t==num
    Value v;
};

void f(Entry* pe)
{
    if (pe->t == num)
        cout << pe->v.i;
    // ...
}

// @variant
// Maintaining the correspondence between a type field and the type held in a union is error-prone.
// we can enforce that correspondence by encapsulating the union and the type field in a class and
// offer access only through member functions that use the union correctly. - (tagged union)
// The use of “naked” unions is best minimized.

// The standard library type, variant, can be used to eliminate most direct uses of unions.
// A variant stores a value of one of a set of alternative types.
struct Entry {
    string name;
    variant<Node*, int> v;
};

void f(Entry* pe)
{
    if (holds_alternative<int>(pe->v)) // does *pe hold an int?
        cout << get<int>(pe->v);       // get the int
    // ...
}
