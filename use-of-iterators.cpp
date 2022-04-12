// @algorithm @iterators

// Iterators are used to separate algorithms and containers.

// the standard algorithm find looks for a value in a sequence and returns an iterator to the element found:
bool has_c(const string& s, char c)    // does s contain the character c?
{
     auto p = find(s.begin(),s.end(),c);
     // Like many standard-library search algorithms, find returns end() to indicate “not found.”
     if (p!=s.end())
           return true;
     else
           return false;
     // A shorter vesion
     // return find(s.begin(),s.end(),c)!=s.end();
}

// Iterators and standard algorithms work equivalently on every standard container for which their use makes sense.
// Consequently, we could generalize find_all():
// The typename is needed to inform the compiler that C’s iterator is supposed to be a type and not a value of some type
// We can hide this implementation detail by introducing a type alias for Iterator
template<typename T>
using Iterator = typename T::iterator;         // T's iterator

template<typename C, typename V>
vector<Iterator<C>> find_all(C& c, V v)        // find all occurrences of v in c
{
     vector<Iterator<C>> res;
     for (auto p = c.begin(); p!=c.end(); ++p)
           if (*p==v)
                 res.push_back(p);
     return res;
}

void test()
{
     string m {"Mary had a little lamb"};

     for (auto p : find_all(m,'a'))           // p is a string::iterator
           if (*p!='a')
                 cerr << "string bug!\n";

     list<double> ld {1.1, 2.2, 3.3, 1.1};
     for (auto p : find_all(ld,1.1))          // p is a list<double>::iterator
           if (*p!=1.1)
                 cerr << "list bug!\n";

     vector<string> vs { "red", "blue", "green", "green", "orange", "green" };
     for (auto p : find_all(vs,"red"))        // p is a vector<string>::iterator
           if (*p!="red")
                 cerr << "vector bug!\n";

     for (auto p : find_all(vs,"green"))
           *p = "vert";
}

