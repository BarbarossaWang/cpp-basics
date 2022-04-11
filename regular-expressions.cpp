// @string @regular-expressions @searching @regular-expression-notation @iterators

// To express the pattern, I use a raw string literal starting with R"( and terminated by )".
// This allows backslashes and quotes to be used directly in the string.
// Had I used a conventional string, the pattern definition would have been:
// regex pat {"\\w{2}\\s*\\d{5}(−\\d{4})?"};  // U.S. postal code pattern

// In <regex>, the standard library provides support for regular expressions:
// regex_match(): Match a regular expression against a string (of known size).
// regex_search(): Search for a string that matches a regular expression in an (arbitrarily long) stream of data.
// regex_replace(): Search for strings that match a regular expression in an (arbitrarily long) stream of data and replace them.
// regex_iterator: Iterate over matches and submatches.
// regex_token_iterator: Iterate over non-matches.

/***************
 * @searching
 ***************/
void use()
{
    ifstream in("file.txt"); // input file
    if(!in)
        cerr << "no file\n";

    regex pat {R"(\w{2}\s*\d{5}(-\d{4})?)"}; // U.S. postal code pattern

    int lineno = 0;
    // The newline character, \n, can be part of a pattern, so we can search for multiline patterns.
    // Obviously, we shouldn’t read one line at a time if we want to do that.
    for (string line; getline(cin,line); ) {      // read into line buffer
        ++lineno;
        // The matches variable is of type smatch. The “s” stands for “sub” or “string,” and an smatch is a vector of submatches of type string.
        smatch matches;                         // matched strings go here
        // The regex_search(line,matches,pat) searches the line for anything that matches the regular expression stored in pat and if it finds any matches, it stores them in matches.
        // If no match was found, regex_search(line,matches,pat) returns false.
        if (regex_search(line,matches,pat)) {     // search for pat in line
            // The first element, here matches[0], is the complete match. The result of a regex_search() is a collection of matches, typically represented as an smatch:
            cout << lineno << ": " << matches[0] << '\n'; // the complete match
                if (1<matches.size() && matches[1].matched) // if there is a sub-pattern and if it is matched
                    // matches[1] is the optional four-digit subpattern.
                    cout << "\t: " << matches[1] << '\n';
            }
    }
}

/***************
 * @regular-expression-notation
 ***************/

// Regular Expression Special Characters
// . Any single character (a “wildcard”)
// [ Begin character class
// ] End character class
// { Begin count
// } End count
// ( Begin grouping
// ) End grouping
// \ Next character has a special meaning
// * Zero or more (suffix operation)
// + One or more (suffix operation)
// ? Optional (zero or one) (suffix operation)
// | Alternative (or)
// ^ Start of line; negation
// $ End of line

// A part of a pattern is considered a subpattern 
// (which can be extracted separately from an smatch) if it is enclosed in parentheses.

// A pattern can be optional or repeated (the default is exactly once) by adding a suffix:
// {n} Exactly n times
// {n,} n or more times
// {n,m} At least n and at most m times
// + Zero or more, that is, {0,}
// + One or more, that is {1,}
// Optional (zero or one_, that is {0,1}

// A suffix ? after any of the repetition notations (?, *, +, and { }) makes the pattern matcher “lazy” or “non-greedy.”
// That is, when looking for a pattern, it will look for the shortest match rather than the longest.
// By default, the pattern matcher always looks for the longest match; this is known as the Max Munch rule.
// Consider: ababab
// The pattern (ab)+ matches all of ababab. However, (ab)+? matches only the first ab.

// In a regular expression, a character class name must be bracketed by [: :].
// For example, [:digit:] matches a decimal digit.
// Furthermore, they must be used within a [ ] pair defining a character class.
// Character Classes
// alnum Any alphanumeric character
// alpha Any alphabetic character
// blank Any whitespace character that is not a line separator
// cntrl Any control character
// d Any decimal digit
// digit Any decimal digit
// graph Any graphical character
// lower Any lowercase character
// print Any printable character
// punct Any punctuation character
// s Any whitespace character
// space Any whitespace character
// upper Any uppercase character
// w Any word character (alphanumeric characters plus the underscore)
// xdigit Any hexadecimal digit character

// Several character classes are supported by shorthand notation:
// For full portability, use the character class names rather than these abbreviations.
// \d A decimal digit [[:digit:]]
// \s A space (space, tab, etc.) [[:space:]]
// \w A letter (a-z) or digit (0-9) or underscore (_) [_[:alnum:]]
// \D Not \d [^[:digit:]]
// \S Not \s [^[:space:]]
// \W Not \w [^_[:alnum:]]
// \l A lowercase character [[:lower:]]
// \u An uppercase character [[:upper:]]
// \L Not \l [^[:lower:]]
// \U Not \u [^[:upper:]]

// here is a function that uses the simplest version of regex_match() to test whether a string is an identifier:
bool is_identifier(const string& s)
{
     regex pat {R"([_[:alpha:]]\w*)"}; // underscore or letter followed by zero or more underscores, letters, or digits
     return regex_match(s,pat);
}

// A group (a subpattern) potentially to be represented by a sub_match is delimited by parentheses.
// If you need parentheses that should not define a subpattern, use (?: rather than plain (.
(\s|:|,)*(\d*)   // optional spaces, colons, and/or commas followed by an optional number
// Assuming that we were not interested in the characters before the number (presumably separators), we could write:
// This would save the regular expression engine from having to store the first characters
(?:\s|:|,)*(\d*)  // optional spaces, colons, and/or commas followed by an optional number

// Regular Expression Grouping Examples
// \d*\s\w+ No groups (subpatterns)
// (\d*)\s(\w+) Two groups
// (\d*)(\s(\w+))+ Two groups (groups do not nest)
// (\s*\w*)+ One group; one or more subpatterns; only the last subpattern is saved as a sub_match
// <(.*?)>(.*?)</\1> Three groups; the \1 means “same as group 1”


/***************
 * @Iterators
 ***************/
// A regex_iterator is a bidirectional iterator, so we cannot directly iterate over an istream (which offers only an input iterator).
// Also, we cannot write through a regex_iterator, and
// the default regex_iterator (regex_iterator{}) is the only possible end-of-sequence.

// We can define a regex_iterator for iterating over a sequence of characters finding matches for a pattern.
void test()
{
     string input = "aa as; asd ++e^asdf asdfg";
     // output all whitespace-separated words in a string
     regex pat {R"(\s+(\w+))"};
     for (sregex_iterator p(input.begin(),input.end(),pat); p!=sregex_iterator{}; ++p)
           cout << (*p)[1] << '\n';
}

// This output
// as
// asd
// asdfg
// We missed the first word, aa, because it has no preceding whitespace.


