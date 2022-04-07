// @classes

// Pointers to objects allocated on the free store is dangerous: a “plain old pointer” should not be used to represent ownership.
void user(int x)
{
    // This will leak unless x is positive. 
    // Assigning the result of new to a “naked pointer” is asking for trouble.
    Shape* p = new Circle{Point{0,0},10};
    // ...
    if (x<0) throw Bad_x{};   // potential leak
    if (x==0) return;         // potential leak
    // ...
    delete p;
}

// One simple solution to such problems is to use a standard-library unique_ptr rather than a “naked pointer” when deletion is required
// As a pleasant side effect of this change, we no longer need to define a destructor for Smiley. 
// The compiler will implicitly generate one that does the required destruction of the unique_ptrs in the vector.
class Smiley : public Circle {
    // ...
private:
    vector<unique_ptr<Shape>> eyes; // usually two eyes
    unique_ptr<Shape> mouth;
};

// Now each object is owned by a unique_ptr that will delete the object when 
// it is no longer needed, that is, when its unique_ptr goes out of scope.
unique_ptr<Shape> read_shape(istream& is) // read shape descriptions from input stream is
{
    // read shape header from is and find its Kind k
    switch (k) {
    case Kind::circle:
         // read circle data {Point,int} into p and r
         return unique_ptr<Shape>{new Circle{p,r}};
    // ...
}

void user()
{
    vector<unique_ptr<Shape>> v;
    while (cin)
         v.push_back(read_shape(cin));
    draw_all(v);               // call draw() for each element
    rotate_all(v,45);          // call rotate(45) for each element
}// all Shapes implicitly destroyed
