// @containers @unordered-map

// The standard-library hashed containers are referred to as “unordered” because they don’t require an ordering function:
unordered_map<string,int> phone_book {
    {"David Hume",123456},
    {"Karl Popper",234567},
    {"Bertrand Arthur William Russell",345678}
};

// Like for a map, we can subscript an unordered_map:
int get_number(const string& s)
{
     return phone_book[s];
}

// The standard library provides a default hash function for strings as well as for other built-in and standard-library types.
// If necessary, you can provide your own. 
// Possibly, the most common need for a “custom” hash function comes when we want an unordered container of one of our own types.
// A hash function is often provided as a function object.
// Creating a new hash function by combining existing hash functions using exclusive-or (^) is simple and often very effective.
struct Record {
     string name;
     int product_code;
     // ...
};

struct Rhash {     // a hash function for Record
     size_t operator()(const Record& r) const
     {
          return hash<string>()(r.name) ^ hash<int>()(r.product_code);
     }
};

unordered_set<Record,Rhash> my_set; // set of Records using Rhash for lookup

// We can avoid explicitly passing the hash operation by defining it as a specialization of the standard-library hash:
namespace std { // make a hash function for Record

    template<> struct hash<Record> {
        using argument_type = Record;
        using result_type = std::size_t;

        size_t operator()(const Record& r) const
        {
             return hash<string>()(r.name) ^ hash<int>()(r.product_code);
        }
    };
}

// Note the differences between a map and an unordered_map:
// A map requires an ordering function (the default is <) and yields an ordered sequence.
// A unordered_map requires a hash function and does not maintain an order among its elements.
