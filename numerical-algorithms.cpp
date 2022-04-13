// @numerics @mathematic

// The parallel algorithms (e.g., reduce()) differ from the sequentional ones (e.g., accumulate()) by 
// allowing operations on elements in unspecified order.

// In <numeric>, we find a small set of generalized numerical algorithms, such as accumulate().
// These algorithms work for every standard-library sequence and can have operations supplied as arguments
// Numerical Algorithms
// x=accumulate(b,e,i) x is the sum of i and the elements of [b:e)
// x=accumulate(b,e,i,f) accumulate using f instead of +
// x=inner_product(b,e,b2,i) x is the inner product of [b:e) and [b2:b2+(e−b)), that is, the sum of i and (*p1)*(*p2) for each p1 in [b:e) and the corresponding p2 in [b2:b2+(e−b))
// x=inner_product(b,e,b2,i,f,f2) inner_product using f and f2 instead of + and *
// p=partial_sum(b,e,out) Element i of [out:p) is the sum of elements [b:b+i]
// p=partial_sum(b,e,out,f) partial_sum using f instead of +
// p=adjacent_difference(b,e,out) Element i of [out:p)is *(b+i)−*(b+i−1) for i>0; if e−b>0, then *out is *b
// p=adjacent_difference(b,e,out,f) adjacent_difference using f instead of −
// iota(b,e,v) For each element in [b:e) assign ++v; thus the sequence becomes v+1, v+2, ...
// x=gcd(n,m) x is the greatest common denominator of integers n and m
// x=lcm(n,m) x is the least common multiple of integers n and m

// For each algorithm, the general version is supplemented by a version applying the most common operator for that algorithm.
list<double> lst {1, 2, 3, 4, 5, 9999.99999};
auto s = accumulate(lst.begin(),lst.end(),0.0);     // calculate the sum: 10014.9999

// parallel version
// I left out the versions of these algorithms that take functor arguments, rather than just using + and =.
// Except for reduce(), I also left out the versions with default policy (sequential) and default value.
// Parallel Numerical Algorithms
// x=reduce(b,e,v) x=accumulate(b,e,v), except out of order
// x=reduce(b,e) x=reduce(b,e,V{}), where V is b’s value type
// x=reduce(pol,b,e,v) x=reduce(b,e,v) with execution policy pol
// x=reduce(pol,b,e) x=reduce(pol,b,e,V{}), where V is b’s value type
// p=exclusive_scan(pol,b,e,out) p=partial_sum(b,e,out) according to pol, excludes the ith input element from the ith sum
// p=inclusive_scan(pol,b,e,out) p=partial_sum(b,e,out) according to pol includes the ith input element in the ith sum
// p=transform_reduce(pol,b,e,f,v) f(x) for each x in [b:e), then reduce
// p=transform_exclusive_scan(pol,b,e,out,f,v) f(x) for each x in [b:e), then exclusive_scan
// p=transform_inclusive_scan(pol,b,e,out,f,v) f(x) for each x in [b:e), then inclusive_scan

// Just as for the parallel algorithms in <algorithm>, we can specify an execution policy:
vector<double> v {1, 2, 3, 4, 5, 9999.99999};
auto s = reduce(v.begin(),v.end());      // calculate the sum using a double as the accumulator

vector<double> large;
// ... fill large with lots of values ...
auto s2 = reduce(par_unseq,large.begin(),large.end()); // calculate the sum using available parallelism

