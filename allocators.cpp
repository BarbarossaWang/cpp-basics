// @utilities @allocator

// By default, standard-library containers allocate space using new.
// Operators new and delete provide a general free store (also called dynamic memory or heap) that can hold objects of arbitrary size and user-controlled lifetime.
// This implies time and space overheads that can be eliminated in many special cases.

// the standard-library containers offer the opportunity to install allocators with specific semantics where needed.

// An important, long-running system used an event queue using vectors as events that were passed as shared_ptrs.
// That way, the last user of an event implicitly deleted it:
// This version led to massive fragmentation.
struct Event {
     vector<int> data = vector<int>(512);
};

list<shared_ptr<Event>> q;

void producer()
{
     for (int n = 0; n!=LOTS; ++n) {
           lock_guard lk {m};      // m is a mutex (§15.5)
           q.push_back(make_shared<Event>());
           cv.notify_one();
     }
}

// The traditional solution to fragmentation problems is to rewrite the code to use a pool allocator.
// A pool allocator is an allocator that manages objects of 
// a single fixed size and allocates space for many objects at a time, 
// rather than using individual allocations.

// C++17 offers direct support for that. 
// The pool allocator is defined in the pmr (“polymorphic memory resource”) sub-namespace of std
pmr::synchronized_pool_resource pool;             // make a pool

struct Event {
    // The standard containers optionally take allocator arguments. 
    // The default is for the containers to use new and delete.
     vector<int> data = vector<int>{512,&pool};   // let Events use the pool
};

list<shared_ptr<Event>> q {&pool};                // let q use the pool

void producer()
{
     for (int n = 0; n!=LOTS; ++n) {
           scoped_lock lk {m};      // m is a mutex (§15.5)
           q.push_back(allocate_shared<Event,pmr::polymorphic_allocator<Event>>{&pool});
           cv.notify_one();
     }
}

