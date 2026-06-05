/*
Problem: 39. Combination Sum
Link: https://leetcode.com/problems/combination-sum/description/
Difficulty: Medium
Approach: Recursive backtracking 
Time Complexity: O(2^(target/m))
Note:
    2 choices for each candidate, take or not take.
    if currsum + candidate <= target then take, increment sum and move to next elem then follow
    the usual backtracking logic.
    if not then dont, move on to next elem
*/

class Solution {
public:
    void func(vector<vector<int>>& ans, vector<int>& cand, vector<int> currAns, int target, int currSum, int i){
        if (currSum == target){
            ans.push_back(currAns);
            return;
        }
        if (i > cand.size()-1)
            return;

        if (cand[i]+currSum <= target){
            currSum += cand[i];
            currAns.push_back(cand[i]);
            func(ans, cand, currAns, target, currSum, i);
            currSum -= cand[i];
            currAns.pop_back();
            func(ans, cand, currAns, target, currSum, i+1);
        }
        else{
            func(ans,  cand, currAns, target, currSum, i+1);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currAns;
        func(ans, candidates, {}, target, 0, 0);
        return ans;
    }
};