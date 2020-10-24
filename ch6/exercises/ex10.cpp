#include "../../include/std_lib_facilities.h"



int factorial(int x) {
  int factor = 1;

  for (int i = 1; i <= x; ++i) {
    factor *= i;
  }

  return factor;
}


int permutations(int a, int b) {
  return factorial(a) / factorial(a-b);
}

int main() {
  cout << "We are going to do some discrete math" << endl;
  
  int a, b;
  char symbol; 
  
  cout << "Please enter the size of your sample: ";
  cin >> a;
  cout << "Please enter the desired number of sub-sets: ";
  cin >> b;
  
  if (a <= b) {
    error("The sample size must be greater than the subset size.");
  }

  cout << "Please enter a symbol for either combinations 'c' (combinations) or 'p' (permutations): ";
  cin >> symbol;
  
  int permutation = permutations(a, b);
  
  switch(symbol) {
    case 'p':
      cout << "P(" << a << ", " << b << ") = " << permutation << endl;
      break;
    case 'c':
      cout << "C(" << a << ", " << b << ") = " << permutation / factorial(b) << endl;
      break;
  }

  return 0;
}
