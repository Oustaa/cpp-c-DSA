#include <iostream>
#include <string>

// !!! Not Donw yet

using namespace std;

string addBinary(string a, string b) {
  cout << "===================================\n";
  cout << "finding the sum for, " << a << ", and " << b << "\n";
  cout << "===================================\n";
  string sum = "";
  int rest = 0;
  int al = a.length() - 1;
  int bl = b.length() - 1;

  while (al >= 0 || bl >= 0) {
    int abit = (al >= 0) ? a[al] - '0' : 0;
    int bbit = (bl >= 0) ? b[bl] - '0' : 0;

    int sum_result = abit + bbit;

    // if (sum_result >= 2) {
    //   if (rest == 1)
    //     sum = "1" + sum;
    //   else
    //     sum = "0" + sum;
    //   rest = 1;
    // } else if (sum_result == 1) {
    //   sum = "1" + sum;
    //   rest = 0;
    // } else {
    //   sum = "0" + sum;
    //   rest = 0;
    // }
    if (sum_result == 2) {
      if (rest == 0)
        m = "0" + sum;
      if (rest == 1)
        sum = "1" + sum;
      rest = 1;

    } else if (sum_result == 1) {
      rest = 0;
      sum = "1" + sum;
    } else {
      rest = 0;
      sum = "0" + sum;
    }

    al--;
    bl--;
  }

  if (rest == 1) {
    sum = "1" + sum;
  }

  return sum;
}

int main() {
  // cout << addBinary("110", "1011") << endl;
  // cout << addBinary("11", "1") << endl;
  cout << addBinary("1011", "111") << endl;
}
