#include "../../include/std_lib_facilities.h"

int main() {
  
  string first_name;
  double age;

  cout << "Please enter your name followed by age: " << endl;
  cin >> first_name;
  cin >> age;
  
  cout << "Hello, "  << first_name << "! " << "You are " << age * 12 << " months old" << endl;

  return 0;

}
