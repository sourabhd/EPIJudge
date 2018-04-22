#include <vector>
#include "test_framework/generic_test.h"

using std::vector;

int NumCombinationsForFinalScore(int final_score,
                                 const vector<int>& individual_play_scores) {
  vector<int> A(final_score + 1, 0);
  A[0] = 1;
  for (const int &score: individual_play_scores) {
    for (int j = score ; j <= final_score ; j++) {
      A[j] += A[j - score];
    }
  }
  return A[final_score];
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"final_score", "individual_play_scores"};
  return GenericTestMain(args, "number_of_score_combinations.tsv",
                         &NumCombinationsForFinalScore, DefaultComparator{},
                         param_names);
}
