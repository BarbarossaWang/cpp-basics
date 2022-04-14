// @concurrency @task @thread
#include <thread>

// We call a computation that can potentially be executed concurrently with other computations a task.
// A thread is the system-level representation of a task in a program.

// A task to be executed concurrently with other tasks is launched by 
// constructing a std::thread (found in <thread>) with the task as its argument.
// A task is a function or a function object:
void f();                 // function

struct F {                // function object
     void operator()();   // F's call operator (§6.3.2)
};

void user()
{
     thread t1 {f};       // f() executes in separate thread
     thread t2 {F()};     // F()() executes in separate thread

     // The join()s ensure that we don’t exit user() until the threads have completed.
     // To “join” a thread means to “wait for the thread to terminate."
     t1.join();           // wait for t1
     t2.join();           // wait for t2
}

// Threads of a program share a single address space. In this, threads differ from processes, which generally do not directly share data.
// Since threads share an address space, they can communicate through shared objects.
// Such communication is typically controlled by locks or other mechanisms to prevent data races (uncontrolled concurrent access to a variable).

// When defining tasks of a concurrent program, our aim is to keep tasks completely separate except where they communicate in simple and obvious ways.
// The simplest way of thinking of a concurrent task is as a function that happens to run concurrently with its caller. 
// For that to work, we just have to pass arguments, get a result back, and make sure that there is no use of shared data in between (no data races).

// f and F() each use the object cout without any form of synchronization.
// The resulting output would be unpredictable and could vary between different executions of the program because 
// the order of execution of the individual operations in the two tasks is not defined.
void f()
{
     cout << "Hello ";
}

struct F {
     void operator()() { cout << "Parallel World!\n"; }
};
