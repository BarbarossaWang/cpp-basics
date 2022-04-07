// @classes @class-hierarchies

// A class hierarchy is a set of classes ordered in a lattice created by derivation (e.g., : public). 
// We use class hierarchies to represent concepts that have hierarchical relationships, 
// such as “A fire engine is a kind of a truck which is a kind of a vehicle” 

//  Smiley -> Circle -> Shape <- Triangle

class Shape {
public:
     virtual Point center() const =0;     // pure virtual
     virtual void move(Point to) =0;

     virtual void draw() const = 0;       // draw on current "Canvas"
     virtual void rotate(int angle) = 0;

     virtual ~Shape() {}                  // destructor
     // ...
};

void rotate_all(vector<Shape*>& v, int angle) // rotate v's elements by angle degrees
{
     for (auto p : v)
           p−>rotate(angle);
}

class Circle : public Shape {
public:
     Circle(Point p, int rad);       // constructor

     Point center() const override
     {
          return x;
     }
     void move(Point to) override
     {
          x = to;
     }

     void draw() const override;
     void rotate(int) override {}         // nice simple algorithm
private:
     Point x;   // center
     int r;     // radius
};

Class Smiley : public Circle {  // use the circle as the base for a face
public:
     Smiley(Point p, int rad) : Circle{p,r}, mouth{nullptr} { }

     // Shape’s destructor is virtual and Smiley’s destructor overrides it. 
     // A virtual destructor is essential for an abstract class because an object of a derived class is usually manipulated through the interface provided by its abstract base class.
     ~Smiley()
     {
          delete mouth;
          // it may be deleted through a pointer to a base class. 
          // Then, the virtual function call mechanism ensures that the proper destructor is called. 
          // That destructor then implicitly invokes the destructors of its bases and members.
          for (auto p : eyes)
                delete p;
     }

     void move(Point to) override;

     void draw() const override;
     void rotate(int) override;

     void add_eye(Shape* s)
     {
          eyes.push_back(s);
     }
     // The push_back() member of vector copies its argument into the vector (here, eyes) as the last element, 
     // increasing that vector’s size by one.
     void set_mouth(Shape* s);
     virtual void wink(int i);     // wink eye number i

     // ...

private:
     vector<Shape*> eyes;          // usually two eyes
     Shape* mouth;
};

void Smiley::draw() const
{
     Circle::draw();
     for (auto p : eyes)
           p−>draw();
     mouth−>draw();
}

