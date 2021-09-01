#include "average_filter.h"

AverageFilter::AverageFilter() {}

double AverageFilter::Filter(double value) {
  /**
   * just retain the length of window, if size >= len of win, pop_front. and then emplace_back
   * */
  data_.push_back(value); 
  double sum = 0.0;
  auto iter = data_.rbegin();

  /**
   * restore the sum to a member to avoid accumulate
   * */ 
  for (int i = 0; i < 10; ++i) { // don't use magic number
    sum += *iter; // iter may be out of range, need check
    ++iter;
  }
  return sum / 10;
}