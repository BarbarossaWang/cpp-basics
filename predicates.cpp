// @algorithms @predicates

// A predicate should not modify the elements to which it is applied.

// the algorithms have simply “built in” the action to be done for each element of a sequence.
// However, we often want to make that action a parameter to the algorithm.
// For example, the find algorithm provides a convenient way of looking for a specific value.
// A more general variant looks for an element that fulfills a specified requirement, a predicate.

// A map allows us to access its elements as a sequence of (key,value) pairs, 
// so we can search a map<string,int>’s sequence for a pair<const string,int>
void f(map<string,int>& m)
{
     auto p = find_if(m.begin(),m.end(),Greater_than{42});
     // ...
}

// Greater_than is a function object holding the value (42) to be compared against:
struct Greater_than {
     int val;
     Greater_than(int v) : val{v} { }
     bool operator()(const pair<string,int>& r) const { return r.second>val; }
};

// we could use a lambda expression
auto p = find_if(m.begin(), m.end(), [](const pair<string,int>& r) { return r.second>42; });
