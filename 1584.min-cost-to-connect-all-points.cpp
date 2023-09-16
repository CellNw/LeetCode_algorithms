/*
 * @lc app=leetcode id=1584 lang=cpp
 *
 * [1584] Min Cost to Connect All Points
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
 private:
  static int cmp(vector<int>& a, vector<int>& b) { return a[1] < b[1]; }

  int updateDist(int point, vector<vector<int>>& edges, vector<int>& minDist,
                 vector<bool>& used) {
    int minIdx = 0;
    for (int i = 0; i < edges.size(); i++) {
      if (used[i]) continue;
      if (edges[point][i] < minDist[i]) minDist[i] = edges[point][i];
      if (minDist[i] < minDist[minIdx]) minIdx = i;
    }
    used[minIdx] = true;
    return minIdx;
  }

 public:
  int minCostConnectPoints(vector<vector<int>>& points) {
    vector<bool> used(points.size(), false);
    vector<vector<int>> edges(
        points.size(), vector<int>(points.size(), numeric_limits<int>::max()));
    vector<int> minDist(points.size(), numeric_limits<int>::max());

    for (int i = 0; i < points.size(); i++) {
      for (int j = 0; j < points.size(); j++) {
        if (i == j) continue;
        edges[i][j] =
            abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
      }
    }

    int idx = 0;
    used[0] = true;
    for (int i = 1; i < points.size(); i++) {
      idx = updateDist(idx, edges, minDist, used);
    }
    return reduce(minDist.begin() + 1, minDist.end());
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  int arr[][2] = {{2, -3}, {-17, -8}, {13, 8}, {-17, -15}};

  vector<vector<int>> points;
  for (const auto& row : arr) {
    vector<int> rowVector(begin(row), end(row));
    points.push_back(rowVector);
  }

  Solution sol;
  cout << sol.minCostConnectPoints(points) << endl;
  return 0;
}
