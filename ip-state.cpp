// @I/O @I/0-state

// An iostream has a state that we can examine to determine whether an operation succeeded.
// In general, the I/O state holds all the information needed to read or write, such as 
// formatting information, 
// error state (e.g., has end-of-input been reached?), and
// what kind of buffering is used.

// In particular, a user can set the state to reflect that an error has occurred and clear the state if an error wasn’t serious.
vector<int> read_ints(istream& is, const string& terminator)
{
    vector<int> res;
    // What is happening here is that the operation is>>i returns a reference to is, and 
    // testing an iostream yields true if the stream is ready for another operation.
    for (int i; is >> i; )
         res.push_back(i);

    if (is.eof())               // fine: end of file
         return res;

    if (is.fail()) {            // we failed to read an int; was it the terminator?
         is.clear();    // reset the state to good()
         is.unget();    // put the non-digit back into the stream
         string s;
         if (cin>>s && s==terminator)
               return res;
         cin.setstate(ios_base::failbit);    // add fail() to cin's state
    }

    return res;
}

auto v = read_ints(cin,"stop");
