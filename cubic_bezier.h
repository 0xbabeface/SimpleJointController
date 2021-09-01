
#include <vector>

using namespace std; // Don’t write using namespace at global scope in a header file.

class CubicBezier {
public:
  CubicBezier(int size);

  vector<double> GetArray(double y0, double yf);

private:
  int size_;
};
