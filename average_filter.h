#include <list>
using namespace std;

class AverageFilter {
public:
  AverageFilter();
  double Filter(double value);

private:
  list<double> data_;
};
