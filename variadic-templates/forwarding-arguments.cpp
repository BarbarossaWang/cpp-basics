// @templates @concepts @variadic-templates @forwarding-arguments

// Passing arguments unchanged through an interface is an important use of variadic templates.

// Consider a notion of a network input channel for which the actual method of moving values is a parameter. 
// Different transport mechanisms have different sets of constructor parameters:
template<typename Transport>
    requires concepts::InputTransport<Transport>
class InputChannel {
public:
    // ...
    InputChannel(TransportArgs&&... transportArgs)
        // The standard-library function forward() is used to move the arguments unchanged from the InputChannel constructor to the Transport constructor.
        : _transport(std::forward<TransportArgs>(transportArgs)...)
    {}
    // ...
    Transport _transport;
};
// the writer of InputChannel can construct an object of type Transport without having to know what arguments are required to construct a particular Transport.
// The implementer of InputChannel needs only to know the common user interface for all Transport objects.
