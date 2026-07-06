/*
Problem: 1288. Remove Covered Intervals
Link: https://leetcode.com/problems/remove-covered-intervals/description/
Difficulty: Medium
Approach: Sorting + Interval Mapping
Time Complexity: O(nlogn)
Note:
    https://leetcode.com/problems/remove-covered-intervals/solutions/8378678/one-sort-one-pass-one-green-tick-onlogn-mpsgq/
*/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });

        int count=0, maxEnd=0;
        int n = intervals.size();

        int maxi = intervals[0][1];

        for (auto& interval : intervals){
            if (interval[1] > maxEnd){
                count++;
                maxEnd = interval[1];
            }
        }

        return count;
    }
};