// C++ offers namespaces as a mechanism for expressing 
// that some declarations belong together and 
// that their names shouldn’t clash with other names.

// By putting my code into the namespace My_code, 
// I make sure that my names do not conflict with the standard-library names in namespace std.
namespaces My_code {
    class complex {
        // ...
    }

    complex sqrt(complex);
    // ...

    int main();
}

// The simplest way to access a name in another namespace is to 
// qualify it with the namespace name (e.g., std::cout and My_code::main).
int My_code::main()
{
    complex z {1,2};
    auto z2 = sqrt(z);
    std::cout << '{' << z2.real() << ',' << z2.imag() << "}\n";
    // ...
}

// The “real main()” is defined in the global namespace, that is,
// not local to a defined namespace, class, or function.
int main()
{
    return My_code::main();
}
