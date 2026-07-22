/*
Problem: Subsequence with Sum K
Link: https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/1
Difficulty: Medium
Approach: Recursion + Backtracking
Time Complexity: O(2^n)
Note:
    
*/

class Solution {
  public:
    int n;
    bool ans;
    void solve(int i, int& sum, vector<int>& arr, int k){
        if (sum == k){
            ans = true;
            return;
        }
        
        if (i == n || ans == true)
            return;
        
        if (sum + arr[i] <= k){
            sum += arr[i];
            solve(i+1, sum, arr, k);
            sum -= arr[i];
        }

        solve(i+1, sum, arr, k);
    }
    bool checkSubsequenceSum(vector<int>& arr, int k) {
        this->n = arr.size();
        this->ans = false;
        
        int sum = 0;
        
        solve(0, sum, arr, k);
        
        return ans;
    }
};