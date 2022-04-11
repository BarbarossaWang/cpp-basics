// @I/O @string-streams

// In <sstream>, the standard library provides streams to and from a string:
// istringstreams for reading from a string
// ostringstreams for writing to a string
// stringstreams for reading from and writing to a string.

void test()
{
    // One common use of an ostringstream is to format before giving the resulting string to a GUI.
    // Similarly, a string received from a GUI can be read using formatted input operations by putting it into an istringstream.
    ostringstream oss;

    oss << "{temperature," << scientific << 123.4567890 << "}";
    // The result from an istringstream can be read using str().
    cout << oss.str() << '\n';
}

// A stringstream can be used for both reading and writing.
// we can define an operation that can convert any type with a string representation into another that can also be represented as a string:
template<typename Target =string, typename Source =string>
Target to(Source arg)      // convert Source to Target
{
  stringstream interpreter;
  Target result;

  if (!(interpreter << arg)                 // write arg into stream
      || !(interpreter >> result)           // read result from stream
      || !(interpreter >> std::ws).eof())   // stuff left in stream?
      throw runtime_error{"to<>() failed"};

  return result;
}

// A function template argument needs to be explicitly mentioned only if it cannot be deduced or if there is no default
auto x1 = to<string,double>(1.2);   // very explicit (and verbose)
auto x2 = to<string>(1.2);          // Source is deduced to double
auto x3 = to<>(1.2);                // Target is defaulted to string; Source is deduced to double
// If all function template arguments are defaulted, the <> can be left out.
auto x4 = to(1.2);                  // the <> is redundant; // Target is defaulted to string; Source is deduced to double
