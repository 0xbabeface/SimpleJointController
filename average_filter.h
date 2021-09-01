#include <list>
using namespace std;  // Don’t write using namespace at global scope in a header file.

class AverageFilter {
public:
  AverageFilter();
  double Filter(double value);

private:
  list<double> data_;
};
