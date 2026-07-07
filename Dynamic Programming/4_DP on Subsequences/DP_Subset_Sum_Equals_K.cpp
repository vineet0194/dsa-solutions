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


/*

    did not consider a n+1 dp array here, hence,
    end of array is determined at the last index (n-1) instead of n

*/

#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(k+1, -1));

    // base case fill (n-1)
    for (int crsum=0; crsum<k+1; crsum++){
        if (crsum == k){                    // hence, this type of base case
            dp[n-1][crsum] = 1;
            continue;
        }
        dp[n-1][crsum] = (crsum + arr[n-1] == k)? 1 : 0;
    }
    for (int i=0; i<n; i++){        // if (crsum==k) return true;
        dp[i][k] = 1;
    }

    // end of array at n-1 => we already determined base case there
    // => start loops from n-2
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


// DP Tabulation (Space Optimized), Space Complexity: O(k)

/*

    considered n+1 dp array here => end of array is reaching n

*/

#include<bits/stdc++.h>
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<int> next(k+1, -1);
    vector<int> curr(k+1, -1);

    for (int crsum=0; crsum<k+1; crsum++){
        if (crsum == k)
            next[crsum] = 1;
        else
            next[crsum] = 0;
    }
        
    // end of array at n => we already determined base case there
    // => start loops from n-1

    for (int i=n-1; i>=0; i--){
        for (int crsum=k; crsum>=0; crsum--){
            if (crsum == k)
                curr[k] = 1;

            bool take = false, notTake = false;
            
            if (crsum + arr[i] < k)
                take = next[crsum + arr[i]];
            
            else if (crsum + arr[i] == k)
                take = true;
            
            notTake = next[crsum];

            curr[crsum] = take || notTake;
        }
        next = curr;
    }

    return curr[0];
}