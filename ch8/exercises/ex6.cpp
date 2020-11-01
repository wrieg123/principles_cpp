#include "../../include/std_lib_facilities.h"


vector<string> reverse_c(vector<string> &original) {

  vector<string> vect;

  for (int i = original.size()-1; i >= 0; i--) {
    vect.push_back(original[i]);
  }
  
  return vect;
}

void reverse_r(vector<string> &original, vector<string> &vect) {
  for (int i = original.size()-1; i >= 0; i--) {
    vect.push_back(original[i]);
  }
  return;
}


void print(vector<string> &v, string s) {
  cout << s;

  for (int i = 0; i < v.size(); ++i) {
    if (i == v.size() -1) { cout << v[i] << endl;}
    else {cout << v[i] << ", ";}
  }   
  return;
}


int main() {
  
  vector<string> original {"Name1", "Name2", "Name3", "Name4", "Name5"};
  vector<string> copy = reverse_c(original);
  print(original, "Original: ");
  print(copy, "Reverse (Copied): ");

  vector<string> dest;
  reverse_r(original, dest);
  print(dest, "Reverse (Reference): ");

  return 0;
}
