//  @contracts @errors-handling @C++20
//  The aim is to support users who want to rely on testing to get programs right – running with extensive run-time checks – but then deploy code with minimal checks.

double& Vector::operator[](int i)
{
    // use a command-line macro to control a run-time check
    if (RANGE_CHECK && (i<0 || size()<=i)
        throw out_of_range{"Vector::operator[]"};
    return elem[i];
}

void f(const char* p)
{
    // The standard library offers the debug macro, assert(), to assert that a condition must hold at run time.
    // If the condition of an assert() fails in “debug mode,” the program terminates.
    // If we are not in debug mode, the assert() is not checked.
    assert(p!=nullptr); // p must not be the nullptr
    // ...
}
