#include "../../include/std_lib_facilities.h"


vector<int> reverse_c(vector<int> &original) {

  vector<int> vect;

  for (int i = original.size()-1; i >= 0; i--) {
    vect.push_back(original[i]);
  }
  
  return vect;
}

void reverse_r(vector<int> &original, vector<int> &vect) {
  for (int i = original.size()-1; i >= 0; i--) {
    vect.push_back(original[i]);
  }
  return;
}


void print(vector<int> &v, string s) {
  cout << s;

  for (int i = 0; i < v.size(); ++i) {
    if (i == v.size() -1) { cout << v[i] << endl;}
    else {cout << v[i] << ", ";}
  }   
  return;
}


int main() {
  
  vector<int> original {1,2,3,4,5,6,7,8,9,10};
  vector<int> copy = reverse_c(original);
  print(original, "Original: ");
  print(copy, "Reverse (Copied): ");

  vector<int> dest;
  reverse_r(original, dest);
  print(dest, "Reverse (Reference): ");

  return 0;
}
