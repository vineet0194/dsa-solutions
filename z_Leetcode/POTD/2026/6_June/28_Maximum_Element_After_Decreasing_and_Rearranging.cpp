/*
Problem: 1846. Maximum Element After Decreasing and Rearranging
Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/?envType=daily-question&envId=2026-06-28
Difficulty: Medium
Approach: Sorting + Greedy
Time Complexity: O(nlogn)
Note:
    
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        if (arr[0] != 1)
            arr[0] = 1;

        int max=1;
        for (int i=1; i<arr.size(); i++){
            if (arr[i] - arr[i-1] > 1)
                arr[i] = arr[i-1]+1;
            if (arr[i] > max)
                max = arr[i];
        }

        return max;
    }
};