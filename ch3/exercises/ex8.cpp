#include "../../include/std_lib_facilities.h"


int main() {

  cout << "Please enter a number: ";
  int value;
  cin >> value;
  cout << "The value " << value << " is an ";
  if (value % 2 == 0) cout << "even";
  else cout << "odd";
  cout << " number" << endl;

  return 0;
}
