#include "../../include/std_lib_facilities.h"


int main() {

  cout << "Enter two integer values, followed by enter each time -> " << endl;
  double val1, val2;

  cin >> val1;
  cin >> val2;

  cout << "Min: " << min(val1, val2) << endl;
  cout << "Max: " << max(val1, val2) << endl;
  cout << "Sum: " << val1 + val2 << endl;
  cout << "Difference: " << val1 - val2 << endl;
  cout << "Product: " << val1 * val2 << endl;
  cout << "Ratio: " << val1 / val2 << endl;

  return 0;
}
