// @structured-binding @struct

// This mechanism for giving local names to members of a class object is called structured binding.
// There will not be any difference in the object code quality compared to explicitly using a composite object; 
// the use of structured binding is all about how best to express an idea.

// A function can return only a single value, but that value can be a class object with many members.
struct Entry {
     string name;
     int value;
};

Entry read_entry(istream& is)     // naive read function 
{
     string s;
     int i;
     is >> s >> i;
     // {s,i} is used to construct the Entry return value.
     return {s,i};
}

// we can “unpack” an Entry’s members into local variables
// The auto [n,v] declares two local variables n and v with their types deduced from read_entry()’s return type.
auto [n,v] = read_entry(is);
cout << "{ " << n << "," << v << " }\n";

// There must be the same number of names defined for the binding as there are nonstatic data members of the class,
// and each name introduced in the binding names the corresponding member.
map<string, int> m;
// ... fill m ...
for (const auto [key,value] : m)
      cout << "{" << key "," << value << "}\n";

void incr(map<string,int>& m)     // increment the value of each element of m
{
     for (auto& [key,value] : m)
           ++value;
}

// It is also possible to handle classes where access is through member functions.
// A complex has two data members, but its interface consists of access functions, such as real() and imag().
// Mapping a complex<double> to two local variables, such as re and im is feasible and efficient
complex<double> z = {1,2};
auto [re,im] = z+2; // re=3; im=2
