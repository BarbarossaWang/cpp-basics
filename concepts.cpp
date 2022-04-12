// @algorithms @concepts @range @predicate @sentinel

// A Range is a concept specifying what it takes to be a sequence of elements. It can be defined by
// A {begin,end} pair of iterators
// A {begin,n} pair, where begin is an iterator and n is the number of elements
// A {begin,pred} pair, where begin is an iterator and pred is a predicate; if pred(p) is true for the iterator p, we have reached the end of the sequence. 
// This allows us to have infinite sequences and sequences that are generated “on the fly.”

// This Range concept is what allows us to say sort(v) rather than sort(v.begin(),v.end())
// The relation for Sortable is defaulted to less.

template<BoundedRangeR>
    requires Sortable<R>
void sort(R& r)
{
    return sort(begin(r),end(r));
}

// When we can’t wait for Ranges, we can define our own simple range algorithms.
// we can easily provide the shorthand to say just sort(v) instead of sort(v.begin(),v.end()):
// I put the container versions of sort() (and other algorithms) into their own namespace Estd (“extended std”) to avoid interfering with other programmers’ uses of namespace std.
namespace Estd {
    using namespace std;

    template<typename C>
    void sort(C& c)
    {
         sort(c.begin(),c.end());
    }

    template<typename C, typename Pred>
    void sort(C& c, Pred p)
    {
         sort(c.begin(),c.end(),p);
    }

    // ...
}

// In addition to Range, the Ranges TS offers many useful concepts.
// Core language concepts
// Same<T,U> T is the same type as U
// DerivedFrom<T,U> T is derived from U
// ConvertibleTo<T,U> A T can be converted to a U
// CommonReference<T,U> T and U share a common reference type
// Common<T,U> T and U share a common type
// Integral<T> T is an integral type
// SignedIntegral<T> T is a signed integral type
// UnsignedIntegral<T> T is an unsigned integral type
// Assignable<T,U> A U can be assigned to a T
// SwappableWith<T,U> A T can be swapped with a U
// Swappable<T> SwappableWith<T,T>

// Common is important for specifying algorithms that should work with a variety of related types while still being mathematically sound.
// Common<T,U> is a type C that we can use for comparing a T with a U by first converting both to Cs.

// For example, we would like to compare a std::string with a C-style string (a char*) and
// an int with a double, but not a std::string with an int.
// To ensure that we specialize common_type_t, used in the definition of Common, suitably
using common_type_t<std::string,char*> = std::string;
using common_type_t<double,int> = double;

// Comparison concepts
// Boolean<T> A T can be used as a Boolean
// WeaklyEqualityComparableWith<T,U> A T and a U can be compared for equality using == and !=
// WeaklyEqualityComparable<T> WeaklyEqualityComparableWith<T,T>
// EqualityComparableWith<T,U> A T and a U can be compared for equivalence using ==
// EqualityComparable<T> EqualityComparableWith<T,T>
// StrictTotallyOrderedWith<T,U> A T and a U can be compared using <, <=, >, and >= yielding a total order
// StrictTotallyOrdered<T> StrictTotallyOrderedWith<T,T>

// Object concepts
// Destructible<T> A T can be destroyed and have its address taken with unary &
// Constructible<T,Args> A T can be constructed from an argument list of type Args
// DefaultConstructible<T> A T can be default constructed
// MoveConstructible<T> A T can be move constructed
// CopyConstructible<T> A T can be copy constructed and move constructed
// Movable<T> MoveConstructable<T>, Assignable<T&,T>, and Swapable<T>
// Copyable<T> CopyConstructable<T>, Moveable<T>, and Assignable<T, const T&>
// Semiregular<T> Copyable<T> and DefaultConstructable<T>
// Regular<T> SemiRegular<T> and EqualityComparable<T>

// Callable concepts
// Invocable<F,Args> An F can be invoked with an argument list of type Args
// InvocableRegular<F,Args> Invocable<F,Args> and is equality preserving
// Predicate<F,Args> An F can be invoked with an argument list of type Args returning a bool
// Relation<F,T,U> Predicate<F,T,U>
// StrictWeakOrder<F,T,U> A Relation<F,T,U> that provides strict weak ordering

// A function f() is equality preserving if x==y implies that f(x)==f(y).

// Strict weak ordering is what the standard library usually assumes for comparisons, such as <;

// Relation and StrictWeakOrder differ only in semantics.

// Iterator concepts
// Iterator<I> An I can be incremented (++) and dereferenced (*)
// Sentinel<S,I> An S is a sentinel for an Iterator type;
// that is, S is a predicate on I’s value type SizedSentinel<S,I>
// A sentinel S where the − operator can be applied to I InputIterator<I>
// An I is an input iterator; * can be used for reading only OutputIterator<I>
// An I is an output iterator; * can be used for writing only ForwardIterator<I>
// An I is a forward iterator, supporting multi-pass BidirectionalIterator<I>
// An I is a ForwardIterator supporting −− RandomAccessIterator<I>
// An I is a BidirectionalIterator supporting +, −, +=, −=, and [] Permutable<I>
// An I is a ForwardIterator<I> where I allows us to move and swap elements Mergeable<I1,I2,R,O>
// Can merge sorted sequences defined by I1 and I2 into O using Relation<R> Sortable<I>
// Can sort sequences defined by I using less Sortable<I,R>
// Can sort sequences defined by I using Relation<R>

// The basic idea of a sentinel is that we can iterate over a range starting at an iterator until the predicate becomes true for an element.
// That way, an iterator p and a sentinel s define a range [p:s(*p)).
// For example, we could define a predicate for a sentinel for traversing a C-style string using a pointer as the iterator:
[](const char* p) {return *p==0; }

// Range concepts
// Range<R> An R is a range with a begin iterator and a sentinel
// SizedRange<R> An R is a range that knows its size in constant time
// View<R> An R is a range with constant time copy, move, and assignment
// BoundedRange<R> An R is a range with identical iterator and sentinel types
// InputRange<R> An R is a range whose iterator type satisfies InputIterator
// OutputRange<R> An R is a range whose iterator type satisfies OutputIterator
// ForwardRange<R> An R is a range whose iterator type satisfies ForwardIterator
// BidirectionalRange<R> An R is a range whose iterator type satisfies BidirectionalIterator
// RandomAccessRange<R> An R is a range whose iterator type satisfies RandomAccessIterator
