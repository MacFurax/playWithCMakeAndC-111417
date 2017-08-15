#include <iostream>
#include <string>
#include <random>
#include <functional>

class Rand_int{
public:
  Rand_int(int low, int high) : re2(rd()), dist(low,high) {
    rnd = std::bind( dist, re );
  }
  //int operator()() {return rnd();}
  int operator()() { return dist(re2); }

private:
  std::random_device rd;
  std::default_random_engine re;
  std::mt19937 re2;
  std::uniform_int_distribution<> dist;
  std::function<int()> rnd;
};

int main()
{
  const int nrolls=10000;  // number of experiments
  const int nstars=100;    // maximum number of stars to distribute

  double mean = 5.0;
  double stddev = 2.0;

  std::default_random_engine generator;
  std::normal_distribution<double> distribution(mean,stddev);

  int p[10]={};

  for (int i=0; i<nrolls; ++i) {
    double number = distribution(generator);
    if ((number>=0.0)&&(number<10.0)) ++p[int(number)];
  }

  std::cout << "normal_distribution (" << mean << "," << stddev << "):" << std::endl;
  std::cout << "min value " << distribution.min() << " max value " << distribution.max() << std::endl;
  for (int i=0; i<10; ++i) {
    std::cout << i << "-" << (i+1) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

 
  std::lognormal_distribution<double> lognormal_distribution(mean,stddev);

  for (int i=0; i<nrolls; ++i) {
    double number = lognormal_distribution(generator);
    if ((number>=0.0)&&(number<10.0)) ++p[int(number)];
  }

  std::cout << "lognormal_distribution (" << mean << "," << stddev << "):" << std::endl;
  std::cout << "min value " << lognormal_distribution.min() << " max value " << lognormal_distribution.max() << std::endl;
  for (int i=0; i<10; ++i) {
    std::cout << i << "-" << (i+1) << ": ";
    std::cout << std::string(p[i]*nstars/nrolls,'*') << std::endl;
  }

  Rand_int ri{1,6};

  for( int i = 0; i < 10; i++ )
    std::cout << "Die roll " << ri() << std::endl;

  return 0;
}