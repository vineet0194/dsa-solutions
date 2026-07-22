/*
Problem: 90. Subsets II
Link: https://leetcode.com/problems/subsets-ii/description/
Difficulty: Medium
Approach: Recursion + Backtracking
Time Complexity: O(2^n)
Note:
    
*/

class Solution {
public:
    int n;
    void solve(int i, vector<int>& curr, vector<int>& nums, vector<vector<int>>& ans){
        if (i==n){
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[i]);
        solve(i+1, curr, nums, ans);
        curr.pop_back();

        int j=i+1;
        while (j<n && nums[i]==nums[j])
            j++;

        solve(j, curr, nums, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        this->n = nums.size();

        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, curr, nums, ans);

        return ans;
    }
};