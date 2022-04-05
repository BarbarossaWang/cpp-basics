// @modules @modularity
import Vector; // get Vector's interface
// It's OK to import the standard library mathematical functions also,
// The new way (use import) and the old way (use #include) can mix.
#include <cmath> // get the standard-library math function interface including sqrt()

double sqrt_sum(Vector& v)
{
     double sum = 0;
     for (int i=0; i!=v.size(); ++i)
           sum+=std::sqrt(v[i]);        // sum of square roots
     return sum;
}

