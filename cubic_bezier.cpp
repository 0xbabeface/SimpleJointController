#include "cubic_bezier.h"

CubicBezier::CubicBezier(int size) : size_(size) {}

vector<double> CubicBezier::GetArray(double y0, double yf) {
  vector<double> data_array; // 1.need Reserved space to avoid axpansion,exp:vector<double> data_array{size, 0.0};
  double diff = yf - y0;
  double interval = 1.0 / size_; // 2.size may be zero, check it.
  for (int i = 0; i < size_; ++i) {
    double x = i * interval;
    double bezier = x * x * x + 3.0 * (x * x * (1.0 - x));
    data_array.push_back(y0 + bezier * diff); // 3.according 1, this should be data_array[i] = y0 + bezier * diff
  }
  return data_array;
}