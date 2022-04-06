// @error-handling
// If an error is detected and it cannot be handled locally in a function, the function must somehow communicate the problem to some caller. 
// Throwing an exception is C++’s most general mechanism for that.

// Exceptions are integrated with constructors and destructors to provide a coherent framework for error handling and resource management. 
// Compilers are optimized to make returning a value much cheaper than throwing the same value as an exception.

// Throwing an exception is not the only way of reporting an error that cannot be handled locally.
// A function can indicate that it cannot perform its alotted task by:
// throwing an exception
// somehow return a value indicating failure
// terminating the program (by invoking a function like terminate(), exit(), or abort()).

// We return an error indicator (an “error code”) when:
// A failure is normal and expected. For example, it is quite normal for a request to open a file to fail (maybe there is no file of that name or maybe the file cannot be opened with the permissions requested).
// An immediate caller can reasonably be expected to handle the failure.

// We throw an exception when:
// An error is so rare that a programmer is likely to forget to check for it. For example, when did you last check the return value of printf()?
// An error cannot be handled by an immediate caller. Instead, the error has to percolate back to an ultimate caller. For example, it is infeasible to have every function in an application reliably handle every allocation failure or network outage.
// New kinds of errors can be added in lower-modules of an application so that higher-level modules are not written to cope with such errors. For example, when a previously single-threaded application is modified to use multiple threads or resources are placed remotely to be accessed over a network.
// No suitable return path for errors codes are available. For example, a constructor does not have a return value for a “caller” to check. In particular, constructors may be invoked for several local variables or in a partially constructed complex object so that clean-up based on error codes would be quite complicated.
// The return path of a function is made more complicated or expensive by a need to pass both a value and an error indicator back, possibly leading to the use of out-parameters, non-local error-status indicators, or other workarounds.
// The error has to be transmitted up a call chain to an “ultimate caller.” Repeatedly checking an error-code would be tedious, expensive, and error-prone.
// The recovery from errors depends on the results of several function calls, leading to the need to maintain local state between calls and complicated control structures.
// The function that found the error was a callback (a function argument), so the immediate caller may not even know what function was called.
// An error implies that some “undo action” is needed.

// We terminate when
// An error is of a kind from which we cannot recover. For example, for many – but not all – systems there is no reasonable way to recover from memory exhaustion.
// The system is one where error-handling is based on restarting a thread, process, or computer whenever a non-trivial error is detected.

// One way to ensure termination is to add noexcept to a function so that a throw from anywhere in the function’s implementation will turn into a terminate().

// When in doubt, prefer exceptions because their use scales better, and don’t require external tools to check that all errors are handled.

// Don’t believe that all error codes or all exceptions are bad; there are clear uses for both.
// Do not believe the myth that exception handling is slow; it is often faster than correct handling of complex or rare error conditions, and of repeated tests of error codes.

// RAII is essential for simple and efficient error-handling using exceptions. 
// Code littered with try-blocks often simply reflects the worst aspects of error-handling strategies conceived for error codes.
