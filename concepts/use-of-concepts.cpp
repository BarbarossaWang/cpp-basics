// @concepts

template<Sequence Seq, Number Num>
    // The Value_type of a sequence is the type of the elements in the sequence.
    // Arithmetic<X,Y> is a concept specifying that we can do arithmetic with numbers of types X and Y.
    // Arithmetic<Value_type<Seq>,Num> is called a requirements-clause.
    requires Arithmetic<Value_type<Seq>,Num>
    // template<Sequence Seq> notation is simply a shorthand for an explicit use of requires Sequence<Seq>.
    // Verbosity: requires Sequence<Seq> && Number<Num> && Arithmetic<Value_type<Seq>,Num>
Num sum(Seq s, Num s);
 
// Use the equivalence between the two notations to write:
template<Sequence Seq, Arithmetic<Value_type<Seq>> Num>
Num sum(Seq s, Num n);
