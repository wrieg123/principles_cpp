#include "../../include/std_lib_facilities.h"


void print(vector<int> &vect, string &s) {
  for (auto i : vect) {
    cout << s << i << endl;
  }
  return;
}


void fibonacci(int x, int y, vector<int> &v, int n) {
  v.push_back(x);
  v.push_back(y);

  for (int i = 1; i < n; ++i) {
    v.push_back(v[i] + v[i-1]);
  }

  return;
}


int main() {

  vector<int> v;
  fibonacci(1, 1, v, 50);
  
  string s = "Fibs: ";
  print(v, s);

  return 0;
}
