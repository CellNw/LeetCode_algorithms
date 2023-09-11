/*
 * @lc app=leetcode id=1282 lang=cpp
 *
 * [1282] Group the People Given the Group Size They Belong To
 */

#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    unordered_map<int, vector<int>> uMap;
    vector<vector<int>> answer;

    for (int i = 0; i < groupSizes.size(); i++) {
      uMap[groupSizes[i]].push_back(i);
    }

    for (auto& m : uMap) {
      for (auto iter = m.second.begin(); iter != m.second.end();
           iter += m.first) {
        answer.push_back(vector<int>(iter, iter + m.first));
      }
    }

    return answer;
  }
};
// @lc code=end
