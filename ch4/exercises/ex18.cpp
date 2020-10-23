#include "../../include/std_lib_facilities.h"




vector<double> quadratic(double a, double b, double c) {
  vector<double> ans;

  double num_plus = -b + sqrt(b*b - 4*a*c);
  double num_minus = -b - sqrt(b*b - 4*a*c);
  ans.push_back(num_plus / (2*a));
  ans.push_back(num_minus / (2*a));

  return ans;
}


int main() {

  cout << "Welcome to the Quadratic Equation solver. Do you remember the song?" << endl;
  cout << "Please enter your values for a, b, c in order" << endl;

  double a, b, c;
  cin >> a;
  cin >> b;
  cin >> c;
  
  cout << "For equation: " << a << "x^2 + " << b << "x + " << c << " the roots are: " << endl;
  vector<double> ans = quadratic(a, b, c);
  cout << "x1 =  " << ans[0] << endl;
  cout << "x2 =  " << ans[1] << endl;

  return 0;

}
