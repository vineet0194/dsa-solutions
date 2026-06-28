/*
Problem: Filter Occupied Intervals©leetcode
Link: https://leetcode.com/contest/weekly-contest-508/problems/filter-occupied-intervals/description/
Difficulty: Medium
Approach: Sorting, Interval Merging+Trimming
Time Complexity: O(nlogn)
Note:
    
*/

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {

        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;

        for (auto &interval : occupiedIntervals) {
            if (merged.empty() || interval[0] > merged.back()[1] + 1) {
                merged.push_back(interval);
            } else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }

        vector<vector<int>> ans;

        for (auto &interval : merged) {
            int l = interval[0];
            int r = interval[1];

            if (r < freeStart || l > freeEnd) {
                ans.push_back({l, r});
            }
            else if (freeStart <= l && r <= freeEnd) {
                continue;
            }
            else if (l < freeStart && r <= freeEnd) {
                ans.push_back({l, freeStart - 1});
            }
            else if (freeStart <= l && r > freeEnd) {
                ans.push_back({freeEnd + 1, r});
            }
            else {
                ans.push_back({l, freeStart - 1});
                ans.push_back({freeEnd + 1, r});
            }
        }

        return ans;
    }
};©leetcode