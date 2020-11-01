#include "../../include/std_lib_facilities.h"


struct summary_stats {
  int mean;
  int median;
  int min;
  int max;
};

void summary_statistics(vector<int> &v, summary_stats &stats) {
  stats.max = v[v.size() -1];  
  stats.min = v[0];
  if ((int)v.size() % 2 == 0) {
    stats.median = (v[v.size() / 2 - 1] + v[v.size() / 2 + 1]) / 2;
  } else {
    stats.median = v[v.size() / 2 -1];
  }

  int sum = 0;
  for (int i : v) sum += i;
  stats.mean = sum / v.size();
}


int main() { 
  
  vector<int> v {1,3,6,6,3,24,234,1234};
  sort(v.begin(), v.end());
  
  summary_stats stats;
  summary_statistics(v, stats);


  cout << "Mean: " << stats.mean << endl;
  cout << "Median: " << stats.median << endl;
  cout << "Min: " << stats.min << endl;
  cout << "Max: " << stats.max << endl;

  return 0;
}

