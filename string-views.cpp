// @string @string-views

// The standard library offers string_view; a string_view is basically a (pointer,length) pair denoting a sequence of characters:
// A string_view gives access to a contiguous sequence of characters.
// The characters can be stored in many possible ways, including in a string and in a C-style string.

// This cat() has three advantages over the compose() that takes const string& arguments:
// It can be used for character sequences managed in many different ways.
// No temporary string arguments are created for C-style string arguments.
// We can easily pass substrings.
string cat(string_view sv1, string_view sv2)
{
    string res(sv1.length()+sv2.length());
    char* p = &res[0];
    for (char c : sv1)                 // one way to copy
        *p++ = c;
    copy(sv2.begin(),sv2.end(),p);     // another way
    return res;
}

string king = "Harold";
auto s1 = cat(king,"William");                // string and const char*
auto s2 = cat(king,king);                     // string and string
// Note the use of the sv (“string view”) suffix.
// using namespace std::literals::string_view_literals;
// When we pass "Edward" we need to construct a string_view from a const char* and that requires counting the characters.
auto s3 = cat("Edward","Stephen"sv);          // const char * and string_view
auto s4 = cat("Canute"sv,king);
auto s5 = cat({&king[0],2},"Henry"sv);        // HaHenry
auto s6 = cat({&king[0],2},{&king[2],4});     // Harold

// When returning a string_view, remember that it is very much like a pointer; it needs to point to something:
string_view bad()
{
     string s = "Once upon a time";
     // We are returning a pointer to characters of a string that will be destroyed before we can use them.
     return {&s[5],4};        // bad: returning a pointer to a local
}

// string_view is that it is a read-only view of its characters.
// For example, you cannot use a string_view to pass characters to a function that modifies its argument to lowercase. 
// For that, you might consider using a gsl::span or gsl::string_span.

// The behavior of out-of-range access to a string_view is unspecified. 
// If you want guaranteed range checking, use at(), which throws out_of_range for attempted out-of-range access, 
// use a gsl::string_span, or 
// “just be careful.
