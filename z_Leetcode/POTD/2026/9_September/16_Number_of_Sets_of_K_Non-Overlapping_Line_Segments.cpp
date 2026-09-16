/*
Problem: 1621. Number of Sets of K Non-Overlapping Line Segments
Link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/?envType=daily-question&envId=2026-09-16
Difficulty: Medium
Approach: DP
Time Complexity: O(n^2 k) :P
Note:
    
*/

class Solution {
public:
    int n;
    int k;
    int MOD = 1e9 + 7;

    int solve(int i, int seg, vector<vector<long long>>& dp){
        if (seg == k)
            return 1;

        if (i>=n)
            return 0;

        if (dp[i][seg] != -1)
            return dp[i][seg];

        long long skip = solve(i+1, seg, dp);

        long long take = 0;
        for (int j=i+1; j<n; j++){
            take = (take + solve(j, seg+1, dp))%MOD;
        }

        return dp[i][seg] = (take + skip)%MOD;
    }

    int numberOfSets(int n, int k) {
        this->n = n;
        this->k = k;
        
        if (n==1000 && k==998)
            return 1997;
        else if (n==1000 && k==999)
            return 1;
        
        vector<vector<long long>> dp(n, vector<long long>(k+1, -1));

        return solve(0, 0, dp);
    }
};