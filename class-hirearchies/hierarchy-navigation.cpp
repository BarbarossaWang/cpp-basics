// @classes @classes-hierarchy @dynamic_cast

Shape* ps {read_shape(cin)};

// If at run time the object pointed to by the argument of dynamic_cast (here, ps) is not of the expected type (here, Smiley) or a class derived from the expected type, 
// dynamic_cast returns nullptr.
if (Smiley* p = dynamic_cast<Smiley*>(ps)) { // ... does ps point to a Smiley? ...
    // ... a Smiley; use it
}
else {
    // ... not a Smiley, try something else ...
}

// When a different type is unacceptable, we can simply dynamic_cast to a reference type. 
// If the object is not of the expected type, dynamic_cast throws a bad_cast exception:
Shape* ps {read_shape(cin)};
Smiley& r {dynamic_cast<Smiley&>(*ps)}; // somewhere, catch std::bad_cast

// Code is cleaner when dynamic_cast is used with restraint. 
// If we can avoid using type information, we can write simpler and more efficient code, but occasionally type information is lost and must be recovered. 
// This typically happens when we pass an object to some system that accepts an interface specified by a base class. 
// When that system later passes the object back to us, we might have to recover the original type. 

// Operations similar to dynamic_cast are known as “is kind of” and “is instance of” operations.1
