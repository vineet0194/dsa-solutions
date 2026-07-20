/*
Problem: 216. Combination Sum III
Link: https://leetcode.com/problems/combination-sum-iii/description/
Difficulty: Medium
Approach: Recursion + Backtracking
Time Complexity: O(2^9 + ans*k)
Note:
    
*/

class Solution {
public:
    vector<vector<int>> ans;

    void solve(int i, int sum, vector<int>& curr, int k, int n){
        if (curr.size() == k){
            if (sum == n)
                ans.push_back(curr);
            return;
        }

        if (i==10 || sum>n)
            return;

        if (sum + i <= n){
            curr.push_back(i);
            solve(i+1, sum+i, curr, k, n);
            curr.pop_back();
        }
        solve(i+1, sum, curr, k, n);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        solve(1, 0, curr, k, n);

        return ans;
    }
};