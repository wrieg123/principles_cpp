#include "../../include/std_lib_facilities.h"


double median(vector<int> vector) {
  sort(vector.begin(), vector.end());
  const int size = vector.size();

  if (size % 2 == 0) {
    return ((double)vector[size/2] + vector[size/2-1]) / 2;
  }
  else {
    return (double)vector[size/2];
  }

}

int main() {
  
  vector<int> odd_vector{1,2,3,4,5,6,7};
  vector<int> even_vector{1,2,3,4};
  
  cout << median(odd_vector) << endl;
  cout << median(even_vector) << endl;

  return 0;
}
