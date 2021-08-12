
#include <vector>

using namespace std;

class CubicBezier {
public:
  CubicBezier(int size);

  vector<double> GetArray(double y0, double yf);

private:
  int size_;
};
