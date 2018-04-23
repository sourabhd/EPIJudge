#include "test_framework/generic_test.h"
#include <vector>

using std::min;
using std::vector;
using namespace std;

int ComputeBinomialCoefficient(int n, int k) {
  vector<int> A(k+1, 0);
  A[0] = 1;
  for (int i = 1 ; i <= n ; i++) {
    for (int j = min(i, k) ; j >= 1 ; --j) {
      A[j] = A[j] + A[j - 1];
    }
    A[0] = 1;
  }
  return A[k];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"n", "k"};
  return GenericTestMain(args, "binomial_coefficients.tsv",
                         &ComputeBinomialCoefficient, DefaultComparator{},
                         param_names);
}
