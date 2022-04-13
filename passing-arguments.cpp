// @concurrency @arguments @passing-arguments

void f(vector<double>& v);    // function do something with v

struct F {                    // function object: do something with v
     vector<double>& v;
     F(vector<double>& vv) :v{vv} { }
     void operator()();       // application operator; §6.3.2
};

int main()
{
     vector<double> some_vec {1,2,3,4,5,6,7,8,9};
     // F{vec2} saves a reference to the argument vector in F.
     // F can now use that vector and hopefully no other task accesses vec2 while F is executing. 
     // Passing vec2 by value would eliminate that risk.
     vector<double> vec2 {10,11,12,13,14};

     // The initialization with {f,ref(some_vec)} uses a thread variadic template constructor that can 
     // accept an arbitrary sequence of arguments.
     // The ref() is a type function from <functional> that unfortunately is needed to tell 
     // the variadic template to treat some_vec as a reference, rather than as an object
     // Without that ref(), some_vec would be passed by value.

     // The compiler checks that the first argument can be invoked given the following arguments and 
     // builds the necessary function object to pass to the thread.

     // if F::operator()() and f() perform the same algorithm, 
     // the handling of the two tasks are roughly equivalent: 
     // in both cases, a function object is constructed for the thread to execute.

     thread t1 {f,ref(some_vec)};   // f(some_vec) executes in a separate thread
     thread t2 {F{vec2}};           // F(vec2)() executes in a separate thread

     t1.join();
     t2.join();
}
