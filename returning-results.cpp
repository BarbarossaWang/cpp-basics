// @concurrency @returning-results

// pass the input data by const reference and to pass the location of a place to deposit the result as a separate argument
void f(const vector<double>& v, double* res);    // take input from v; place result in *res

class F {
public:
     F(const vector<double>& vv, double* p) :v{vv}, res{p} { }
     void operator()();          // place result in *res
private:
     const vector<double>& v;    // source of input
     double* res;                // target for output
};

double g(const vector<double>&); // use return value

void user(vector<double>& vec1, vector<double> vec2, vector<double> vec3)
{
     double res1;
     double res2;
     double res3;

     thread t1 {f,cref(vec1),&res1};        // f(vec1,&res1) executes in a separate thread
     thread t2 {F{vec2,&res2}};             // F{vec2,&res2}() executes in a separate thread
    // I don’t consider returning results through references particularly elegant,
     thread t3 {[&](){res3 = g(vec3);}};    // capture local variables by reference

     t1.join();
     t2.join();
     t3.join();

     cout << res1 << ' ' << res2 << ' ' << res3 << '\n';
}

