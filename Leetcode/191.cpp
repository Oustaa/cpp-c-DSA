#include <iostream>

using namespace std;

int hammingWeight(int n) {
  if (n / 2 == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return hammingWeight(n / 2);
  }

  return 1 + hammingWeight(n / 2);
}

int main() {
  cout << hammingWeight(11) << endl;
  cout << hammingWeight(128) << endl;
  cout << hammingWeight(2147483645) << endl;
}
