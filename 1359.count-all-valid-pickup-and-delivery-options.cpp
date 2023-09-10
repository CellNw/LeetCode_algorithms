/*
 * @lc app=leetcode id=1359 lang=cpp
 *
 * [1359] Count All Valid Pickup and Delivery Options
 */

#include <iostream>

using namespace std;

// @lc code=start
class Solution {
 public:
  int countOrders(int n) {
    long total = 1;
    for (int i = 2; i <= n; i++) {
      total = total * (2 * i * i - i) % 1000000007;
    }
    return total;
  }
};
// @lc code=end
int main(int argc, char const *argv[]) {
  Solution sol;
  cout << sol.countOrders(2) << endl;
  return 0;
}
