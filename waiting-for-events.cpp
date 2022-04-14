// @concurrency @waiting-for-events
#include <chrono>
#include <condition_variable>

using namespace std::chrono;

auto t0 = high_resolution_clock::now();
// Note that I didn’t even have to launch a thread; by default, this_thread refers to the one and only thread.
this_thread::sleep_for(milliseconds{20});
auto t1 = high_resolution_clock::now();
// I used duration_cast to adjust the clock’s units to the nanoseconds I wanted.
cout << duration_cast<nanoseconds>(t1−t0).count() << " nanoseconds passed\n";

// The basic support for communicating using external events is provided by condition_variables found in <condition_variable>.
// A condition_variable is a mechanism allowing one thread to wait for another.
// In particular, it allows a thread to wait for some condition (often called an event) to occur as the result of work done by other threads.

// Consider the classical example of two threads communicating by passing messages through a queue.
// For simplicity, I declare the queue and the mechanism for avoiding race conditions on that queue global to the producer and consumer:
class Message {    // object to be communicated
     // ...
};

queue<Message> mqueue;         // the queue of messages
condition_variable mcond;      // the variable communicating events
mutex mmutex;                  // for synchronizing access to mcond

// The consumer() reads and processes Messages:
void consumer()
{
     while(true) {
        // I explicitly protect the operations on the queue and on the condition_variable with a unique_lock on the mutex.
        // I used a unique_lock rather than a scoped_lock for two reasons:
        // We need to pass the lock to the condition_variable’s wait(). A scoped_lock cannot be copied, but a unique_lock can be.
        // We want to unlock the mutex protecting the condition variable before processing the message. A unique_lock offers operations, such as lock() and unlock(), for low-level control of synchronization.
        // unique_lock can only handle a single mutex.
        unique_lock lck {mmutex};          // acquire mmutex
        // Waiting on condition_variable releases its lock argument until 
        // the wait is over (so that the queue is non-empty) and then reacquires it.
        // The explicit check of the condition, here !mqueue.empty(), protects against waking up just to find that 
        // some other task has “gotten there first” so that the condition no longer holds.
        mcond.wait(lck,[] { return !mqueue.empty(); });    // release lck and wait;
                                                           // re-acquire lck upon wakeup
                                                           // don't wake up unless mqueue is non-empty
        auto m = mqueue.front();           // get the message
        mqueue.pop();
        lck.unlock();                      // release lck
        // ... process m ...
     }
}

// The corresponding producer looks like this:
void producer()
{
     while(true) {
          Message m;
          // ... fill the message ...
          scoped_lock lck {mmutex};      // protect operations
          mqueue.push(m);
          mcond.notify_one();            // notify
     }                                   // release lock (at end of scope)
}

