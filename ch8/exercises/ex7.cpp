#include "../../include/std_lib_facilities.h"



int main() {

  vector<string> names {"Will", "Jack", "Hayley", "Grace", "Other"};
  vector<int> ages {23, 17, 24, 21, 33};

  vector<string> copy_names {names};

  sort(names.begin(), names.end());
  
  for (const auto n : names) {
      const auto itr{find(copy_names.begin(), copy_names.end(), n)};
      if (itr == copy_names.end()) error("Name not found");
      size_t index = static_cast<size_t>(itr - copy_names.begin());
      cout << n << " is " << ages.at(index) << endl;
  }

  return 0;
}
