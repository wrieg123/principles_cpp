#include "../../include/std_lib_facilities.h"

int main() {

  cout << "Welcome to the Sieve of Eratosthenes!" << endl;
  cout << "Please enter a number, n, for which to calculate primes between (2, n): ";

  int n;
  cin >> n;

  vector<int> arr;
  for (int i = 0; i < n; ++i) arr.push_back(1);
   
  for (int i = 2; i < sqrt(n); ++i) {
    if (arr[i] == 1) {
      int j = i*i;
      while (j < n) {
        arr[j] = 0;
        j += i;
      }
    }
  }

  vector<int> primes;
  for (int i = 2; i < arr.size(); ++i) {
    if (arr[i] == 1) primes.push_back(i);
  }
  
  for (int i = 0; i < primes.size(); ++i) {
    if (i!= primes.size() -1) {
      cout << primes[i] << ", ";
    } else {
      cout << primes[i] << endl;
     }
  }

  return 0;
}
