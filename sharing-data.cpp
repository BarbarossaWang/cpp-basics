// @concurrency @sharing-data
// The mutual exclusion and locking facilities are found in <mutex>.
#include <mutex>

// Communicating through shared data is pretty low level.
// In that regard, use of shared data is inferior to the notion of call and return.

// how to ensure that at most one task at a time has access to a given set of objects.
// The fundamental element of the solution is a mutex, a “mutual exclusion object.” 
// A thread acquires a mutex using a lock() operation:
mutex m; // controlling mutex
int sh;  // shared data

void f()
{
    // The type of lck is deduced to be scoped_lock<mutex>.
    // The scoped_lock’s constructor acquires the mutex (through a call m.lock()).
    // If another thread has already acquired the mutex, the thread waits (“blocks”) until the other thread completes its access.
    // Once a thread has completed its access to the shared data, the scoped_lock releases the mutex (with a call m.unlock()).
    // When a mutex is released, threads waiting for it resume executing (“are woken up”).
     scoped_lock lck {m};        // acquire mutex
     sh += 7;                    // manipulate shared data
}    // release mutex implicitly

// Note the use of RAII.
// Use of resource handles, such as scoped_lock and unique_lock,
// is simpler and far safer than explicitly locking and unlocking mutexes.

// The correspondence between the shared data and a mutex is conventional:
// It doesn’t take a genius to guess that for a Record called rec, 
// you are supposed to acquire rec.rm before accessing the rest of rec,
class Record {
public:
     mutex rm;
     // ...
};

// It is not uncommon to need to simultaneously access several resources to perform some action.
// This can lead to deadlock.
// For example, if thread1 acquires mutex1 and then tries to acquire mutex2 while 
// thread2 acquires mutex2 and then tries to acquire mutex1, 
// then neither task will ever proceed further.

// The scoped_lock helps by enabling us to acquire several locks simultaneously:
// This scoped_lock will proceed only after acquiring all its mutexes arguments and will never block (“go to sleep”) while holding a mutex.
// The destructor for scoped_lock ensures that the mutexes are released when a thread leaves the scope.
void f()
{
     scoped_lock lck {mutex1,mutex2,mutex3};   // acquire all three locks
     // ... manipulate shared data ...
}// implicitly release all mutexes


// The basic mutex allows one thread at a time to access data.
// One of the most common ways of sharing data is among many readers and a single writer.
// This “reader-writer lock” idiom is supported be share_mutex.
// A reader will acquire the mutex “shared” so that other readers can still gain access, whereas a writer will demand exclusive access.
shared_mutex mx;          // a mutex that can be shared

void reader()
{
     shared_lock lck {mx};       // willing to share access with other readers
     // ... read ...
}

void writer()
{
     unique_lock lck {mx};       // needs exclusive (unique) access
     // ... write ...
}

