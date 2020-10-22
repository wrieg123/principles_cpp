#include "../../include/std_lib_facilities.h"

int main() {
  

  cout << "Please enter two integer values: ";
  int a, b;
  cin >> a;
  cin >> b;
  bool statement = a/b * b + a%b == a ;
  cout << "a/b * b + a\%b == a?" << statement << endl;

  return 0;
}
