# Standard-Library Components

The facilities provided by the standard library can be classified like this:
- Run-time language support (e.g., for allocation and run-time type information).
- The C standard library (with very minor modifications to minimize violations of the type system).
- Strings (with support for international character sets, localization, and read-only views of substrings); see §9.2.
- Support for regular expression matching; see §9.4.
- I/O streams is an extensible framework for input and output to which users can add their own types, streams, buffering strategies, locales, and character sets (Chapter 10). There is also a library for manipulating file systems in a portable manner (§10.10).
- A framework of containers (such as vector and map) and algorithms (such as find(), sort(), and merge()); see Chapter 11 and Chapter 12. This framework, conventionally called the STL [Stepanov,1994], is extensible so users can add their own containers and algorithms.
- Support for numerical computation (such as standard mathematical functions, complex numbers, vectors with arithmetic operations, and random number generators); see §4.2.1 and Chapter 14.
- Support for concurrent programming, including threads and locks; see Chapter 15. The concurrency support is foundational so that users can add support for new models of concurrency as libraries.
- Parallel versions of most STL algorithms and some numerical algorithms (e.g., sort() and reduce()); see §12.9 and §14.3.1.
- Utilities to support template metaprogramming (e.g., type traits; §13.9), STL-style generic programming (e.g., pair; §13.4.3), general programming (e.g., variant and optional; §13.5.1, §13.5.2), and clock (§13.7).
- Support for efficient and safe management of general resources, plus an interface to optional garbage collectors (§5.3).
- “Smart pointers” for resource management (e.g., unique_ptr and shared_ptr; §13.2.1).
- Special-purpose containers, such as array (§13.4.1), bitset (§13.4.2), and tuple (§13.4.3).
- Suffixes for popular units, such as ms for milliseconds and i for imaginary (§5.4.4).
