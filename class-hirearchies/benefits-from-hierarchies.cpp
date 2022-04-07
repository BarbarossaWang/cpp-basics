// @classes @class-hierarchie @destructor
// A class hierarchy offers two kinds of benefits:
// Interface inheritance: An object of a derived class can be used wherever an object of a base class is required. That is, the base class acts as an interface for the derived class. The Container and Shape classes are examples. Such classes are often abstract classes.
// Implementation inheritance: A base class provides functions or data that simplifies the implementation of derived classes. Smiley’s uses of Circle’s constructor and of Circle::draw() are examples. Such base classes often have data members and constructors.

// Concrete classes – especially classes with small representations – are much like built-in types: we define them as local variables, access them using their names, copy them around, etc.
// Classes in class hierarchies are different: we tend to allocate them on the free store using new, and we access them through pointers or references.

enum class Kind { circle, triangle, smiley };

Shape* read_shape(istream& is) // read shape descriptions from input stream is
{
    // ... read shape header from is and find its Kind k ...
    switch (k) {
    case Kind::circle:
        // read circle data {Point,int} into p and r
        return new Circle{p,r};
    case Kind::triangle:
        // read triangle data {Point,Point,Point} into p1, p2, and p3
        return new Triangle{p1,p2,p3};
    case Kind::smiley:
        // read smiley data {Point,int,Shape,Shape,Shape} into p, r, e1, e2, and m
        Smiley* ps = new Smiley{p,r};
        ps−>add_eye(e1);
        ps−>add_eye(e2);
        ps−>set_mouth(m);
        return ps;
    }
}

void user()
{
    std::vector<Shape*>v;
    while (cin)
        v.push_back(read_shape(cin));
    draw_all(v); // call draw() for each element
    rotate_all(v, 45); // call rotate(45) for each element
    // Note that there are no pointers to the shapes outside user(), so user() is responsible for deallocating them.
    // This is done with the delete operator and relies critically on Shape’s virtual destructor.
    // Because that destructor is virtual, delete invokes the destructor for the most derived class.
    // Objects are constructed “bottom up” (base first) by constructors and destroyed “top down” (derived first) by destructors.
    for (auto p : v) // remember to delete elements
        delete p;
}
