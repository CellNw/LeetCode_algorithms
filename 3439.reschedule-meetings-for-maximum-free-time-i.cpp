/*
 * @lc app=leetcode id=3439 lang=cpp
 *
 * [3439] Reschedule Meetings for Maximum Free Time I
 */

#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
 private:
  vector<int> gaps;

 public:
  int maxFreeTime(int eventTime, int k, vector<int>& startTime,
                  vector<int>& endTime) {
    gaps.resize(startTime.size() + 1);
    gaps[0] = startTime[0];
    for (int i = 1; i < startTime.size(); ++i) {
      gaps[i] = startTime[i] - endTime[i - 1];
    }
    gaps[startTime.size()] = eventTime - endTime.back();

    int maxFreeTime = accumulate(gaps.begin(), gaps.begin() + k + 1, 0);
    int sliderSum = maxFreeTime;
    for (int idx = 0; idx < gaps.size() - k - 1; ++idx) {
      sliderSum += gaps[idx + k + 1] - gaps[idx];
      maxFreeTime = max(maxFreeTime, sliderSum);
    }
    return maxFreeTime;
  }
};
// @lc code=end

int main(int argc, char const* argv[]) {
  {
    Solution sol;
    int eventTime = 34;
    int k = 2;
    vector<int> startTime = {0, 17};
    vector<int> endTime = {14, 19};
    cout << (sol.maxFreeTime(eventTime, k, startTime, endTime) == 18) << endl;
  }

  {
    Solution sol;
    int eventTime = 5;
    int k = 1;
    vector<int> startTime = {1, 3};
    vector<int> endTime = {2, 5};
    cout << (sol.maxFreeTime(eventTime, k, startTime, endTime) == 2) << endl;
  }

  {
    Solution sol;
    int eventTime = 10;
    int k = 1;
    vector<int> startTime = {0, 2, 9};
    vector<int> endTime = {1, 4, 10};
    cout << (sol.maxFreeTime(eventTime, k, startTime, endTime) == 6) << endl;
  }
  return 0;
}
