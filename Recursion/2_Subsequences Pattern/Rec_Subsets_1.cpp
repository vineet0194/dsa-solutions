/*
Problem: 78. Subsets
Link: https://leetcode.com/problems/subsets/
Difficulty: Medium
Approach: Recursion + Back Tracking
Time Complexity: O(2^n)
Note:
    
*/

class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& nums, vector<int> curr, int i){
        if (i==nums.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(ans, nums, curr, i+1);
        curr.pop_back();
        solve(ans, nums, curr, i+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(ans, nums, {}, 0);
        return ans;
    }
};