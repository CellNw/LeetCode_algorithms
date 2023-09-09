/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 private:
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> all_vec;

    for (int i = 0; i < numRows; i++) {
      vector<int> vec(i + 1, 1);
      for (int j = 1; j < i; j++) {
        vec[j] = all_vec.back()[j - 1] + all_vec.back()[j];
      }
      all_vec.push_back(vec);
    }

    return all_vec;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution sol;
  return 0;
}
