// @utilities @function-adaption @lambdas @functions @mem_fn() @function-object

// When passing a function as a function argument, the type of the argument must exactly match the expectations expressed in the called function’s declaration
// If the intended argument “almost matches expectations,” we have three good alternatives:
// Use a lambda
// Use std::mem_fn() to make a function object from a member function
// Define the function to accept a std::function

/***************
 * @lambdas-as-adaption
 ***************/

void draw_all(vector<Shape*>& v)
{
    // for_each() calls its argument using the traditional function call syntax f(x),
    // Shape's draw() uses the conventional OO notation x−>f().
    // A lambda easily mediates between the two notations.
    for_each(v.begin(),v.end(),[](Shape* p) { p−>draw(); });
}


/***************
 * @mem_fn()
 ***************/

// Given a member function, the function adaptor mem_fn(mf) produces 
// a function object that can be called as a nonmember function.
void draw_all(vector<Shape*>& v)
{
     for_each(v.begin(),v.end(),mem_fn(&Shape::draw));
}

/***************
 * @function
 ***************/

// The standard-library function is a type that can hold any object you can invoke using the call operator ().
// An object of type function is a function object
// functions are useful for callbacks, for passing operations as arguments, for passing function objects, etc.
int f1(double);
function<int(double)> fct1 {f1};                // initialize to f1

int f2(string);
// For fct2, I let the type of the function be deduced from the initializer: int(string).
function fct2 {f2};                             // fct2's type is function<int(string)>

function fct3 = [](Shape* p) { p−>draw(); };    // fct3's type is function<void(Shape*)>

// it may introduce some run-time overhead compared to direct calls, and a function, being an object, does not participate in overloading.
// If you need to overload function objects (including lambdas), consider overloaded.
