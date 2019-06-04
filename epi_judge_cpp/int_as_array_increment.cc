#include <vector>
#include "test_framework/generic_test.h"
using std::vector;
vector<int> PlusOne(vector<int> A) {
  short carryOut = 0;
  ++A.back();

  for (int i = A.size() - 1; i >= 0; i--) {
    short digit = A[i];

    if (carryOut) {
      digit += carryOut;
      carryOut = 0;
    }

    if (digit > 9) {
      digit %= 10;
      carryOut = 1;
    }

    A[i] = digit;
  }

  if (carryOut) {
    A.insert(A.begin(), carryOut);
  }

  return A;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A"};
  std::cout << "First version\n"; 
  return GenericTestMain(args, "int_as_array_increment.cc",
                         "int_as_array_increment.tsv", &PlusOne,
                         DefaultComparator{}, param_names);
}
