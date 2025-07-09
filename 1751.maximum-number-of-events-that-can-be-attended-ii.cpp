/*
 * @lc app=leetcode id=1751 lang=cpp
 *
 * [1751] Maximum Number of Events That Can Be Attended II
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 private:
  vector<vector<int>> dp;

 public:
  int maxValue(vector<vector<int>> &events, int k) {
    sort(
        events.begin(), events.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[1] < b[1]; });

    dp.resize(events.size() + 1, vector<int>(k + 1, 0));

    for (int i = 1; i <= events.size(); ++i) {
      auto iter =
          lower_bound(events.begin(), events.begin() + i - 1, events[i - 1][0],
                      [](const vector<int> &a, int b) { return a[1] < b; });
      int prev = iter - events.begin();
      for (int j = 1; j <= k; ++j) {
        dp[i][j] = max(dp[i - 1][j], dp[prev][j - 1] + events[i - 1][2]);
      }
    }

    return dp[events.size()][k];
  }
};
// @lc code=end

int main() {
  {
    Solution sol;
    vector<vector<int>> events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    int k = 2;
    cout << (sol.maxValue(events, k) == 7) << endl;  // Expected output: 7
  }

  {
    Solution sol;
    vector<vector<int>> events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 10}};
    int k = 2;
    cout << (sol.maxValue(events, k) == 10) << endl;
  }

  {
    Solution sol;
    vector<vector<int>> events = {{1, 1, 1}, {2, 2, 2}, {3, 3, 3}, {4, 4, 4}};
    int k = 3;
    cout << (sol.maxValue(events, k) == 9) << endl;
  }

  return 0;
}