/*
 * @lc app=leetcode id=332 lang=cpp
 *
 * [332] Reconstruct Itinerary
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 private:
  int maxDepth;
  unordered_map<string, vector<pair<string, int>>> uMap;

  static int cmp(pair<string, int>& a, pair<string, int>& b) {
    return a.first < b.first;
  }

  bool res(int depth, vector<pair<string, int>>& from, vector<string>& ans) {
    if (depth == maxDepth) return true;
    for (auto iter = from.begin(); iter != from.end(); iter++) {
      if (iter->second != 0) {
        iter->second--;
        ans[depth] = iter->first;
        if (res(depth + 1, uMap[iter->first], ans)) return true;
        iter->second++;
      }
    }
    return false;
  }

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    maxDepth = tickets.size() + 1;
    vector<string> ans(maxDepth, "JFK");
    for (const auto& ticket : tickets) {
      auto iter = uMap[ticket[0]].begin();
      for (; iter != uMap[ticket[0]].end() && iter->first != ticket[1]; iter++)
        ;

      if (iter == uMap[ticket[0]].end()) {
        uMap[ticket[0]].push_back(pair<string, int>(ticket[1], 1));
      } else {
        iter->second++;
      }
    }

    for (auto& p : uMap) {
      sort(p.second.begin(), p.second.end(), cmp);
    }

    res(1, uMap["JFK"], ans);

    return ans;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  string arr[][2] = {{"JFK", "SFO"},
                     {"JFK", "ATL"},
                     {"SFO", "ATL"},
                     {"ATL", "JFK"},
                     {"ATL", "SFO"}};

  vector<std::vector<std::string>> tickets;
  for (const auto& row : arr) {
    std::vector<std::string> rowVector(begin(row), end(row));
    tickets.push_back(rowVector);
  }

  Solution sol;
  auto ans = sol.findItinerary(tickets);
  for (auto& s : ans) {
    cout << s << " ";
  }
  cout << endl;
  return 0;
}
