/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  int candy(vector<int>& ratings) {
    vector<int> ans(ratings.size(), 1);
    for (auto ratingsIter = ratings.begin() + 1, ansIter = ans.begin() + 1;
         ratingsIter != ratings.end(); ratingsIter++, ansIter++) {
      if (*ratingsIter > *(ratingsIter - 1)) {
        *ansIter = *(ansIter - 1) + 1;
      }
    }
    for (auto ratingsIter = ratings.rbegin() + 1, ansIter = ans.rbegin() + 1;
         ratingsIter != ratings.rend(); ratingsIter++, ansIter++) {
      if (*ratingsIter > *(ratingsIter - 1) && *ansIter <= *(ansIter - 1)) {
        *ansIter = *(ansIter - 1) + 1;
      }
    }

    return reduce(ans.begin(), ans.end());
  }
};
// @lc code=end
int main(int argc, char const* argv[]) {
  Solution sol;
  int a[] = {1, 3, 4, 5, 2};
  vector<int> v(a, a + 5);
  cout << sol.candy(v) << endl;
  return 0;
}
