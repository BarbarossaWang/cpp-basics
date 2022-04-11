// @I/O @file-system

// The properties of file systems and the ways of manipulating them vary greatly.
// the file system library in <filesystem> offers a uniform interface to most facilities of most file systems.
// Using <filesystem>, we can portably
// express file system paths and navigate through a file system
// examine file types and the permissions associated with them

// The filesystem library can handle unicode.
path f = "dir/hypothetical.cpp";    // naming a file
// Note that a program manipulating a file system is usually running on a computer together with other programs.
// Thus, the contents of a file system can change between two commands.
assert(exists(f));        // f must exist
if (is_regular_file(f))   // is f an ordinary file?
     cout << f << " is a file; its size is " << file_size(f) << '\n';

// A path is quite a complicated class, capable of handling the native character sets and conventions of many operating systems.
// it can handle file names from command lines as presented by main(); for example:
int main(int argc, char* argv[])
{
     if (argc < 2) {
           cerr << "arguments expected\n";
           return 1;
     }
     // A path is not checked for validity until it is used. 
     // Even then, its validity depends on the conventions of the system on which the program runs.
     path p {argv[1]};   // create a path from the command line
     cout << p << " " << exists(p) << '\n';    // note: a path can be printed like a string
     // ...
}

// a path can be used to open a file
void use(path p)
{
     ofstream f {p};
     if (!f) error("bad file name: ", p);
     f << "Hello, file!";
}

// <filesystem> offers types for traversing directories and inquiring about the properties of the files found:
// path A directory path
// filesystem_error A file system exception
// directory_entry A directory entry
// directory_iterator For iterating over a directory
// recursive_directory_iterator For iterating over a directory and its subdirectories
void print_directory(path p)
try
{
     if (is_directory(p)) {
           cout << p << ":\n";
           for (const directory_entry& x : directory_iterator{p})
                 cout << "  " << x.path() << '\n';
     }
}
catch (const filesystem_error& ex) {
     cerr << ex.what() << '\n';
}

// A string can be implicitly converted to a path so we can exercise print_directory like this:
void use()
{
     print_directory(".");     // current directory
     print_directory("..");    // parent directory
     print_directory("/");     // Unix root directory
     print_directory("c:");    // Windows volume C
     for (string s; cin>>s; )
           print_directory(s);
     // Had I wanted to list subdirectories also, I would have said recursive_directory_iterator{p}.
     // Had I wanted to print entries in lexicographical order, I would have copied the paths into a vector and sorted that before printing.
}

// Class path offers many common and useful operations:
// p and p2 are paths
// value_type Character type used by the native encoding of the filesystem: char on POSIX, wchar_t on Windows
// string_type std::basic_string<value_type>
// const_iterator A const BidirectionalIterator with a value_type of path
// iterator  Alias for const_iterator

// p=p2 Assign p2 to p
// p/=p2 p and p2 concatenated using the file-name separator (by default /)
// p+=p2 p and p2 concatenated (no separator)
// p.native() The native format of p
// p.string() p in the native format of p as a string
// p.generic_string() p in the generic format as a string
// p.filename() The filename part of p
// p.stem() The stem part of p
// p.extension() The file extension part of p
// p.begin() The beginning of p’s element sequence
// p.end() The end of p’s element sequence
// p==p2, p!=p2 Equality and inequality for p and p2
// p<p2, p<=p2, p>p2, p>=p2 Lexicographical comparisons
// is>>p, os<<p Stream I/O to/from p
// u8path(s) A path from a UTF-8 encoded source s

// We use a path as a string (e.g., f.extension) and we can extract strings of various types from a path (e.g., f.extension().string()).

// Note that naming conventions, natural languages, and string encodings are rich in complexity. 
// The filesystem-library abstractions offer portability and great simplification.
// p, p1, and p2 are paths; e is an error_code; b is a bool indicating success or failure
// exists(p) Does p refer to an existing file system object?
// copy(p1,p2) Copy files or directories from p1 to p2; report errors as exceptions
// copy(p1,p2,e) Copy files or directories; report errors as error codes
// b=copy_file(p1,p2) Copy file contents from p1 to p2; report errors as exceptions
// b=create_directory(p) Create new directory named p; all intermediate directories on p must exist
// b=create_directories(p) Create new directory named p; create all intermediate directories on p
// p=current_path() p is the current working directory
// current_path(p) Make p the current working directory
// s=file_size(p) s is the number of bytes in p
// b=remove(p) Remove p if it is a file or an empty directory

// Many operations have overloads that take extra arguments, such as operating systems permissions.

// The <filesystem> library knows about a few common kinds of files and classifies the rest as “other”
// f Is a path or a file_status
// is_block_file(f) Is f a block device?
// is_character_file(f) Is f a character device?
// is_directory(f) Is f a directory?
// is_empty(f) Is f an empty file or directory?
// is_fifo(f) Is f a named pipe?
// is_other(f) Is f some other kind of file?
// is_regular_file(f) Is f a regular (ordinary) file?
// is_socket(f) Is f a named IPC socket?
// is_symlink(f) Is f a symbolic link?
// status_known(f) Is f’s file status known?
