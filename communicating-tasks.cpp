// @concurrency @commnuicating-tasks @future @promise @packaged_pack @async()

/**************************
 * @future-and-promise
 **************************/

// The important point about future and promise is that they enable a transfer of a value between two tasks without explicit use of a lock;
// The basic idea is simple: when a task wants to pass a value to another, it puts the value into a promise
// Somehow, the implementation makes that value appear in the corresponding future, from which it can be read (typically by the launcher of the task).


// The main purpose of a promise is to provide simple “put” operations (called set_value() and set_exception()) to match future’s get().
// If you have a promise and need to send a result of type X to a future, you can do one of two things: pass a value or pass an exception.
void f(promise<X>& px) // a task: place the result in px
{
     // ...
     try{
          X res;
          // ... compute a value for res ...
          px.set_value(res);
     }
     catch (...) {      // oops: couldn't compute res
        // The current_exception() refers to the caught exception.
          px.set_exception(current_exception());     // pass the exception to the future's thread
     }
}

// To deal with an exception transmitted through a future, the caller of get() must be prepared to catch it somewhere.
void g(future<X>& fx)       // a task: get the result from fx
{
     // ...
     try{
        // If we have a future<X> called fx, we can get() a value of type X from it:
        // If the value isn’t there yet, our thread is blocked until it arrives.
        // If the value couldn’t be computed, get() might throw an exception 
        // (from the system or transmitted from the task from which we were trying to get() the value).
          X v = fx.get();  // if necessary, wait for the value to get computed
          // ... use v ...
     }
     catch (...) {         // oops: someone couldn't compute v
          // ... handle error ...
     }
}

/**************************
 * @packaged_pack
 **************************/

// The packaged_task type is provided to simplify setting up tasks connected with futures and promises to be run on threads.
// A packaged_task provides wrapper code to put the return value or exception from the task into a promise.
// If you ask it by calling get_future, a packaged_task will give you the future corresponding to its promise.
double accum(double* beg, double* end, double init)
     // compute the sum of [beg:end) starting with the initial value init
{
     return accumulate(beg,end,init);
}

double comp2(vector<double>& v)
{
     using Task_type = double(double*,double*,double);            // type of task

     // The packaged_task template takes the type of the task as its template argument 
     // (here Task_type, an alias for double(double*,double*,double)) and 
     // the task as its constructor argument (here, accum).
     packaged_task<Task_type> pt0 {accum};                        // package the task (i.e., accum)
     packaged_task<Task_type> pt1 {accum};

     future<double> f0 {pt0.get_future()};                        // get hold of pt0's future
     future<double> f1 {pt1.get_future()};                        // get hold of pt1's future

     double* first = &v[0];
     // The move() operations are needed because a packaged_task cannot be copied.
     // The reason that a packaged_task cannot be copied is that it is a resource handle: 
     // it owns its promise and is (indirectly) responsible for whatever resources its task may own.
     thread t1 {move(pt0),first,first+v.size()/2,0};              // start a thread for pt0
     thread t2 {move(pt1),first+v.size()/2,first+v.size(),0};     // start a thread for pt1

     // ...

     return f0.get()+f1.get();                                    // get the results
}

/**************************
 * @async()
 **************************/

// To launch tasks to potentially run asynchronously, we can use async():
// async() separates the “call part” of a function call from the “get the result part” and separates both from the actual execution of the task.
// don’t even think of using async() for tasks that share resources needing locking.
// With async() you don’t even know how many threads will be used because that’s up to async() to decide based on what 
// it knows about the system resources available at the time of a call.
double comp4(vector<double>& v)
     // spawn many tasks if v is large enough
{
     if (v.size()<10000)      // is it worth using concurrency?
           return accum(v.begin(),v.end(),0.0);

     auto v0 = &v[0];
     auto sz = v.size();

     auto f0 = async(accum,v0,v0+sz/4,0.0);          // first quarter
     auto f1 = async(accum,v0+sz/4,v0+sz/2,0.0);     // second quarter
     auto f2 = async(accum,v0+sz/2,v0+sz*3/4,0.0);   // third quarter
     auto f3 = async(accum,v0+sz*3/4,v0+sz,0.0);     // fourth quarter

     return f0.get()+f1.get()+f2.get()+f3.get(); // collect and combine the results
}

// Please note that async() is not just a mechanism specialized for parallel computation for increased performance. 
// For example, it can also be used to spawn a task for getting information from a user, leaving the “main program” active with something else
