#include "../../include/std_lib_facilities.h"

int main() {
  
  double a,b;
  constexpr min_tick = 0.01;
  while(cin >> a && cin >> b) {
    double delta = max(a,b) / min(a,b) -1;
    if (a ==b) {
      cout << "The numbers are equal." << endl;
    } 
    else if (delta <= min_tick) {
      cout << "The numbers are almost equal." << endl; 
    }
    else {
      cout << "the smaller value is: " << min(a, b) << endl;
      cout << "the larger value is: " << max(a,b) << endl;
    }

  }

  return 0;
}
