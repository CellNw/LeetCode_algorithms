/*
 * @lc app=leetcode id=1647 lang=cpp
 *
 * [1647] Minimum Deletions to Make Character Frequencies Unique
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int minDeletions(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<int> v(26, 0);
    for (auto &&c : s) v[c - 'a']++;

    sort(v.begin(), v.end());

    int sum = 0;
    auto iter = v.rbegin() + 1;
    for (; iter != v.rend() && *(iter - 1) != 0; iter++) {
      if (*(iter - 1) <= *iter) {
        sum += *iter - *(iter - 1) + 1;
        *iter = *(iter - 1) - 1;
      }
    }
    for (; iter != v.rend(); iter++) sum += *iter;
    return sum;
  }
};
// @lc code=end

int main(int argc, char const *argv[]) {
  Solution sol;
  cout << sol.minDeletions("bbcebab") << endl;
  return 0;
}
