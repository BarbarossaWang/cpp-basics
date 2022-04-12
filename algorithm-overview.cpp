// @algorithms

// In the context of the C++ standard library, an algorithm is a function template operating on sequences of elements.

// The algorithms are defined in namespace std and presented in the <algorithm> header.
// These standard-library algorithms all take sequences as inputs. A half-open sequence from b to e is referred to as [b:e).

// Selected Standard Algorithms
// f=for_each(b,e,f) For each element x in [b:e)do f(x)
// p=find(b,e,x) p is the first p in [b:e) so that *p==x
// p=find_if(b,e,f) p is the first p in [b:e) so that f(*p)
// n=count(b,e,x) n is the number of elements *q in [b:e) so that *q==x
// n=count_if(b,e,f) n is the number of elements *q in [b:e) so that f(*q)
// replace(b,e,v,v2) Replace elements *q in [b:e) so that *q==v with v2
// replace_if(b,e,f,v2) Replace elements *q in [b:e) so that f(*q) with v2
// p=copy(b,e,out) Copy [b:e)to[out:p)
// p=copy_if(b,e,out,f) Copy elements *q from [b:e) so that f(*q) to [out:p)
// p=move(b,e,out) Move [b:e)to[out:p)
// p=unique_copy(b,e,out) Copy [b:e)to[out:p); don’t copy adjacent duplicates
// sort(b,e) Sort elements of [b:e) using < as the sorting criterion
// sort(b,e,f) Sort elements of [b:e) using f as the sorting criterion
// (p1,p2)=equal_range(b,e,v) [p1:p2) is the subsequence of the sorted sequence [b:e) with the value v; basically a binary search for v
// p=merge(b,e,b2,e2,out) Merge two sorted sequences [b:e) and [b2:e2) into [out:p
// p=merge(b,e,b2,e2,out,f) Merge two sorted sequences [b:e) and [b2:e2) into [out:p using f as the comparison)

// Some algorithms, such as replace() and sort(), modify element values, but no algorithm adds or subtracts elements of a container.
// The reason is that a sequence does not identify the container that holds the elements of the sequence.
// To add or delete elements, you need something that knows about the container (e.g., a back_inserter;)
// or directly refers to the container itself (e.g., push_back() or erase();)

// Lambdas are very common as operations passed as arguments.
vector<int> v = {0,1,2,3,4,5};
for_each(v.begin(),v.end(),[](int& x){ x=x*x; });     // v=={0,1,4,9,16,25}

