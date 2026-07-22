/*
Problem: Matrix Chain Multiplication
Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
Difficulty: Hard
Approach: DP
Time Complexity: O(n^3)     for each pair (i, j) [total n^2 pairs] => you are iterating over at max n elems
                            therefor n^2 * n => n^3
Note:
    
*/

// Recursive Memoization, O(n^2 + n)

class Solution {
  public:
    int n;
    int solve(int i, int j, vector<vector<int>>& dp, vector<int>& A){
        if (i==j)
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int steps = INT_MAX;
        for (int k=i; k<j; k++)
            steps = min(steps, (A[i-1] * A[k] * A[j]) +  solve(i, k, dp, A) + solve(k+1, j, dp, A));
        
        return dp[i][j] = steps;
    }
    int matrixMultiplication(vector<int> &arr) {
        this->n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return solve(1, n-1, dp, arr);
    }
};  

// DP Tabulation, Space Complexity: O(n^2)

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        for (int i=0; i<n; i++)
            dp[i][i] = 0;
        
        for (int i=n-1; i>=1; i--){
            for (int j=i+1; j<n; j++){
                int steps = INT_MAX;
                
                for (int k=i; k<j; k++){
                    steps = min(steps,
                                dp[i][k] + dp[k+1][j] +
                                (arr[i-1] * arr[k] * arr[j])
                    );
                }
                
                dp[i][j] = steps;
            }
        }
        
        return dp[1][n-1];
    }
};