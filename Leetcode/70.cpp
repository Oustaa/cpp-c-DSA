#include <iostream>
#include <map>

using namespace std;

void calculate(int &result, int totalSteps, int max, map<int, int> &cash) {
  if (totalSteps >= max) {
    result++;
    return;
  }

  if (totalSteps + 2 <= max) {
    calculate(result, totalSteps + 2, max, cash);
  }
  if (totalSteps + 1 <= max) {
    calculate(result, totalSteps + 1, max, cash);
  }
}

int climbStairs(int n) {
  int result = 0;
  map<int, int> cash{};

  calculate(result, 0, n, cash);

  return result;
}

int main(int argc, char **argv) {
  int n = stoi(argv[1]);

  int stairs = climbStairs(n);
  cout << stairs << endl;
  return 0;
}
