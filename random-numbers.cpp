// @numeric @random-numbers
#include <iostream>
#include <random>
using namespace std;

// provided by the standard library in <random>.
// A random number generator consists of two parts:
// An engine that produces a sequence of random or pseudo-random values
// A distribution that maps those values into a mathematical distribution in a range

// Examples of distributions are uniform_int_distribution (where all integers produced are equally likely), 
// normal_distribution (“the bell curve”), and 
// exponential_distribution (exponential growth); 
// each for some specified range.
// using my_engine = default_random_engine;              // type of engine
// using my_distribution = uniform_int_distribution<>;   // type of distribution
// 
// my_engine re {};                                      // the default engine
// my_distribution one_to_six {1,6};                     // distribution that maps to the ints 1..6
// auto die = [](){ return one_to_six(re); }             // make a generator
// 
// int x = die();                                        // roll the die: x becomes a value in [1:6]

// how could we get that? We have to get something that, like die(), 
// combines an engine with a distribution inside a class Rand_int:
class Rand_int {
public:
     Rand_int(int low, int high) :dist{low,high} { }
     int operator()() { return dist(re); }     // draw an int
     void seed(int s) { re.seed(s); }          // choose new random engine seed
private:
     default_random_engine re;
     uniform_int_distribution<> dist;
};

int main()
{
     constexpr int max = 9;
     Rand_int rnd {0,max};                         // make a uniform random number generator

     vector<int> histogram(max+1);                 // make a vector of appropriate size
     for (int i=0; i!=200; ++i)
           ++histogram[rnd()];                     // fill histogram with the frequencies of numbers [0:max]

     for (int i = 0; i!=histogram.size(); ++i) {   // write out a bar graph
           cout << i << '\t';
           for (int j=0; j!=histogram[i]; ++j) cout << '*';
           cout << endl;
     }
}
