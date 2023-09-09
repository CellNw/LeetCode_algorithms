/*
 * @lc app=leetcode id=377 lang=cpp
 *
 * [377] Combination Sum IV
 */

#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 private:
  int find(vector<int>& nums, int target, vector<int>& v) {
    if (target == 0) return 1;
    if (v[target] != -1) return v[target];

    int ways = 0;
    for (auto iter = nums.begin(); iter != nums.end() && *iter <= target;
         iter++) {
      ways += find(nums, target - *iter, v);
    }
    v[target] = ways;
    return ways;
  }

 public:
  int combinationSum4(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<int> v(target + 1, -1);
    return find(nums, target, v);
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  int target = 999;
  int a[] = {10,  20,  30,  40,  50,  60,  70,  80,  90,  100, 110, 120, 130,
             140, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260,
             270, 280, 290, 300, 310, 320, 330, 340, 350, 360, 370, 380, 390,
             400, 410, 420, 430, 440, 450, 460, 470, 480, 490, 500, 510, 520,
             530, 540, 550, 560, 570, 580, 590, 600, 610, 620, 630, 640, 650,
             660, 670, 680, 690, 700, 710, 720, 730, 740, 750, 760, 770, 780,
             790, 800, 810, 820, 830, 840, 850, 860, 870, 880, 890, 900, 910,
             920, 930, 940, 950, 960, 970, 980, 990, 111};

  vector<int> v(a, a + sizeof(a) / sizeof(int));
  Solution sol;
  auto start = chrono::system_clock::now();
  cout << sol.combinationSum4(v, target) << endl;
  cout << chrono::duration_cast<chrono::milliseconds>(
              chrono::system_clock::now() - start)
              .count()
       << " ms" << endl;
  return 0;
}
