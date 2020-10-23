#include "../../include/std_lib_facilities.h"


int main() {

  vector<string> words;

  vector<string> disliked = {"Broccoli", "Vegetables"};


  while(true) {
    string temp;

    cin >> temp;
    bool seen = false;
    for (string s : disliked) {
      if (temp == s) {
        seen = true;
        cout << "BLEEP" << endl;
      };
    }
    if (!seen) cout << temp << endl;

  }

  return 0;
}
