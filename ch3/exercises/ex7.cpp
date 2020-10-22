#include "../../include/std_lib_facilities.h"

int main() {

  vector<string> vals;

  cout << "Please enter some strings: " << endl;

  for (int a = 0; a < 3; a++) {
    string val;
    cin >> val;
    vals.push_back(val); 
  }


  sort(vals.begin(), vals.end());

  for (int j = 0; j < vals.size(); j++)  {
    string i = vals[j]; 
    if (j != vals.size() - 1) cout << i << ", ";
    else cout << i << endl;
  }

  return 0;
}
