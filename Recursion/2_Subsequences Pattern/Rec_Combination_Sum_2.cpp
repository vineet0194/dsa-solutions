/*
Problem: 40. Combination Sum II
Link: https://leetcode.com/problems/combination-sum-ii/
Difficulty: Medium
Approach: Recursion + Back Tracking
Time Complexity: O(2^n)
Note:
    
*/

class Solution {
public:
    void solve(vector<vector<int>>& ans, vector<int>& A, vector<int>& combi, int target, int index){
        if (target==0){
            ans.push_back(combi);
            return;
        }
        for (int i=index; i<A.size() && A[i]<=target; i++){
            if (i>index && A[i]==A[i-1]) continue;
            combi.push_back(A[i]);
            solve(ans, A, combi, target-A[i], i+1);
            combi.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combi;
        sort(candidates.begin(), candidates.end());
        solve(ans, candidates, combi, target, 0);
        return ans;
    }
};