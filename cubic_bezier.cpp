#include "cubic_bezier.h"

CubicBezier::CubicBezier(int size) : size_(size) {}

vector<double> CubicBezier::GetArray(double y0, double yf) {
  vector<double> data_array;
  double diff = yf - y0;
  double interval = 1.0 / size_;
  for (int i = 0; i < size_; ++i) {
    double x = i * interval;
    double bezier = x * x * x + 3.0 * (x * x * (1.0 - x));
    data_array.push_back(y0 + bezier * diff);
  }
  return data_array;
}