#include "Vector.h" // get Vector's interface
#include <cmath>    // get the standard-library math interface include sqrt()

double sqrt_sum(Vector& v)
{
    double sum = 0;
    for (int i=0; i!=v.size(); ++i)
        sum+=std::sqrt(v[i]); // sum of square roots
    return sum;
}
