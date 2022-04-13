// @utilities @pair @tuple @specialized-containers @containers

// the standard-library algorithm equal_range returns a pair of iterators specifying a subsequence meeting a predicate:
template<typename Forward_iterator, typename T, typename Compare>
    pair<Forward_iterator,Forward_iterator>
    equal_range(Forward_iterator first, Forward_iterator last, const T& val, Compare cmp);

// Given a sorted sequence [first:last), equal_range() will return the pair representing the subsequence that matches the predicate cmp.
auto less = [](const Record& r1, const Record& r2) { return r1.name<r2.name;};     // compare names

void f(const vector<Record>& v)        // assume that v is sorted on its "name" field
{
     auto er = equal_range(v.begin(),v.end(),Record{"Reg"},less);

     // The first member of a pair is called first and the second member is called second.
     for (auto p = er.first; p!=er.second; ++p)    // print all equal records
           cout << *p;                             // assume that << is defined for Record
}

// Where the names first and last are too generic, we can use structured binding.
void f2(const vector<Record>& v)     // assume that v is sorted on its "name" field
{
     auto [first,last] = equal_range(v.begin(),v.end(),Record{"Reg"},less);

     for (auto p = first; p!=last; ++p)     // print all equal records
           cout << *p;                      // assume that << is defined for Record
}

// A pair provides operators, such as =, ==, and <, if its elements do. 
// Type deduction makes it easy to create a pair without explicitly mentioning its type. 
void f(vector<string>& v)
{
    // Both p1 and p2 are of type pair<vector<string>::iterator,int>.
    pair p1 {v.begin(),2};             // one way
    auto p2 = make_pair(v.begin(),2);  // another way
    // ...
}

// If you need more than two elements (or less), you can use tuple (from <utility>).
// A tuple is a heterogeneous sequence of elements;
tuple<string,int,double> t1 {"Shark",123,3.14};    // the type is explicitly specified
auto t2 = make_tuple(string{"Herring"},10,1.23);   // the type is deduced to tuple<string,int,double>
// Older code tends to use make_tuple() because template argument type deduction from constructor arguments is C++17.
tuple t3 {"Cod"s,20,9.99};                         // the type is deduced to tuple<string,int,double>

// Access to tuple members is through a get function template:
// The elements of a tuple are numbered (starting with zero) and the indices must be constants.
string s = get<0>(t1);      // get the first element: "Shark"
int x = get<1>(t1);         // get the second element: 123
double d = get<2>(t1);      // get the third element: 3.14

// an element of a tuple with a unique type in that tuple can be “named” by its type:
auto s = get<string>(t1);     // get the string: "Shark"
auto x = get<int>(t1);        // get the int: 123
auto d = get<double>(t1);     // get the double: 3.14

// We can use get<> for writing also:
get<string>(t1) = "Tuna";    // write to the string
get<int>(t1) = 7;            // write to the int
get<double>(t1) = 312;       // write to the double

// Like pairs, tuples can be assigned and compared if their elements can be. 
// Like tuple elements, pair elements can be accessed using get<>().
// Like for pair, structured binding can be used for tuple.
