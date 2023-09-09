/*
 * @lc app=leetcode id=2593 lang=cpp
 *
 * [2593] Find Score of an Array After Marking All Elements
 */

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 private:
  int imax = numeric_limits<int>::max();

 public:
  long long findScore(vector<int> &nums) {
    long long score = 0;

    for (vector<int>::iterator iter = nums.begin() + 1; iter != nums.end();
         iter++) {
      if (*iter >= *(iter - 1)) {
        *iter = imax;
      }
    }

    for (vector<int>::reverse_iterator iter = nums.rbegin();
         iter != nums.rend() - 1; iter++) {
      if (*iter < *(iter + 1)) {
        score += *iter;
        *(iter + 1) = imax;
      }
    }

    if (*nums.begin() != imax) {
      score += *nums.begin();
    }

    return score;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution sol;

  int a[] = {6, 4, 4, 5};
  vector<int> v(a, a + 4);
  cout << sol.findScore(v) << endl;
  return 0;
}
