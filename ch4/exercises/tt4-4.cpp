#include "../../include/std_lib_facilities.h"

int main() {
  

  for (int i = 0; i < 26; ++i) {
    cout << char('a'+i) << " " << int('a'+i) << endl;
  }
  for (int i = 0; i < 26; ++i) {
    cout << char('A'+i) << " " << int('A'+i) << endl;
  }

  return 0;
}
