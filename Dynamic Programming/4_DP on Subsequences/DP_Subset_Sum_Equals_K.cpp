/*
Problem: Subset Sum Equal To K
Link: https://www.naukri.com/code360/problems/subset-sum-equal-to-k_1550954?leftPanelTabValue=PROBLEM
Difficulty: Medium
Approach: DP
Time Complexity: O(n*k)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n*k + n)

#include<bits/stdc++.h>
using namespace std;

bool solve(int i, int crsum, int k, vector<int>& arr, vector<vector<int>>& dp){
    if (crsum == k)
        return true;

    if (i==arr.size()){
        if (crsum == k)
            return true;
        else    
            return false;
    }

    // dp[i][crsum] = -1 => not computed, else=> computed (0=> false, 1=> true)

    if (dp[i][crsum] != -1)
        return dp[i][crsum];

    bool take = false;
    if (crsum + arr[i] <= k)
        take = solve(i+1, crsum+arr[i], k, arr, dp);
    bool notTake = solve(i+1, crsum, k, arr, dp);

    return dp[i][crsum] = (take || notTake);
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return solve(0, 0, k, arr, dp);
}

// DP Tabulation, Space Complexity: O(n*k)

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    // base case fill (n-1)
    for (int crsum=0; crsum<k+1; crsum++){
        if (crsum == k){
            dp[n-1][crsum] = 1;
            continue;
        }
        dp[n-1][crsum] = (crsum + arr[n-1] == k)? 1 : 0;
    }
    for (int i=0; i<n; i++){        // if (crsum==k) return true;
        dp[i][k] = 1;
    }

    for (int i=n-2; i>=0; i--){
        for (int crsum=k; crsum>=0; crsum--){
            bool take = false, notTake=false;

            if (crsum + arr[i] < k)
                take = dp[i+1][crsum+arr[i]];

            else if (crsum + arr[i] == k)
                take = true;

            notTake = dp[i+1][crsum];

            dp[i][crsum] = take || notTake;
        }
    }

    return dp[0][0];
}