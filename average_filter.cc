#include "average_filter.h"

AverageFilter::AverageFilter() {}

double AverageFilter::Filter(double value) {
  data_.push_back(value);
  double sum = 0.0;
  auto iter = data_.rbegin();
  for (int i = 0; i < 10; ++i) {
    sum += *iter;
    ++iter;
  }
  return sum / 10;
}