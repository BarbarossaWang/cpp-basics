// @time @utilities

// In <chrono>, the standard library provides facilities for dealing with time.
using namespace std::chrono;

// The clock returns a time_point (a point in time).
// Subtracting two time_points gives a duration (a period of time).
auto t0 = high_resolution_clock::now();
do_work();
auto t1 = high_resolution_clock::now();
// Various clocks give their results in various units of time (the clock I used measures nanoseconds), 
// so it is usually a good idea to convert a duration into a known unit. 
// That’s what duration_cast does.
cout << duration_cast<milliseconds>(t1−t0).count() << "msec\n";

// To simplify notation and minimize errors, <chrono> offers time-unit suffixes.
// The chrono suffixes are defined in namespace std::chrono_literals.
this_thread::sleep(10ms+33us);   // wait for 10 milliseconds and 33 microseconds

// An elegant and efficient extension to <chrono>, supporting 
// longer time intervals (e.g., years and months), 
// calendars, and 
// time zones, is being added to the standard for C++20.
// It even handles leap seconds.
auto spring_day = apr/7/2018;
cout << weekday(spring_day) << '\n';       // Saturday

