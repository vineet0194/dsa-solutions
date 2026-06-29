/*
Problem: DP Introduction
Link: NA
Difficulty: Easy
Approach: -
Time Complexity: -
Note:
    
*/

#include<bits/stdc++.h>
using namespace std;

int fib(int n){
    if (n<=1)
        return n;
    return fib(n-1)+fib(n-2);
}

int fib(int n, vector<int>& dp){
    if (n<=1)
        return n;
    if (dp[n] != -1)            // some already computed value is present
        return dp[n];
    return dp[n] = fib(n-1, dp) + fib(n-2, dp);     // no pre-computed ans => compute it and store it
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 5;

    // Regular Recursive Function
    cout << fib(n) << endl;
    /*
        for certain cases, you will definetly need to re-compute subproblems you had already
        encountered before but (since there is no memoization) => did not store them

        we have base case fib(1) = 1, fib(0) = 0;
        recursive tree:
            fib(5)
            ├── fib(4)
            │   ├── fib(3)
            │   │   ├── fib(2)
            │   │   │   ├── fib(1)
            │   │   │   └── fib(0)
            │   │   └── fib(1)
            │   └── fib(2)
            │       ├── fib(1)
            │       └── fib(0)
            └── fib(3)
                ├── fib(2)
                │   ├── fib(1)
                │   └── fib(0)
                └── fib(1)

            we see that eventhough we have already calculated fib(2) and fib(3),
            we had to re-compute them again because we did not store it

            for this, TC=O(2^n), SC=O(n) [for n recursive calls]
    */
    
    /* --------------------------------------------------------------------------------------------------- */

    // Recursive Memoization Function
    vector<int> dp(n+1, -1);            // (dp[i] = -1) => no pre-computed value exists for that subproblem
    cout << fib(n, dp) << endl;
    /*
        using a recursive memoization approach, we store those values we have computed, if we see that
        we already have a pre-computed value for a case we arrived on again => we see (dp[i] != -1) for that case,
        hence use that value

        we have base case fib(1) = 1, fib(0) = 0;
        recursive tree:
            fib(5)
            ├── fib(4)
            │   ├── fib(3)
            │   │   ├── fib(2)
            │   │   │   ├── fib(1)
            │   │   │   └── fib(0)
            │   │   └── fib(1)
            │   └── fib(2)  ← dp hit
            └── fib(3)      ← dp hit
        
        here, we see we dont have to find fib(2) and fib(3) again => we had it computed before and MEMOIZED (stored)
        it into our dp table for dp[2] and dp[3]

        for this, TC=O(n), SC=O(2n)=>O(n)   [O(n) for recursive calls, O(n) for dp space]
    */

    /* --------------------------------------------------------------------------------------------------- */

    // Tabulation Function
    vector<int> DP(n+1, -1);
    DP[0] = 0;      // base case definition
    DP[1] = 1;      //        "

    for (int i=2; i<=n; i++){
        DP[i] = DP[i-1]+DP[i-2];
    }
    cout << DP[n] << endl;
    /*
        using a DP Tabulation approach, we store computed values as DP[i] = DP[i-1]+DP[i-2]
        at each step, we compute a newly found subproblem as => sum of last 2 subproblems

        TC=O(n), SC=O(n)    [O(n) for DP space]
    */

    /* --------------------------------------------------------------------------------------------------- */

    // Space Optimization
    int prev1 = 1, prev2 = 0;       // base cases
    for (int i=2; i<=n; i++){
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    cout << prev1 << endl;
    /*
        using this approach, upon finding a new subproblem => we compute it and move on (only storing what is necessary
        for the next subproblem => last 2 sub problems instead of the entire dp array)

        at the start of each step we have prev1 = fib(i-1), prev2 = fib(i-2)

        hence => we find curr => prev1 + prev2 => store it in prev1 BUT BEFORE THAT store prev1 in prev2

        at the end of each step we have prev1 = fib(i), prev2 = fib(i-1),
        when we go to the next subproblem, we need only these 2 to compute it

        intuition:
            Before computing step n
                                        F(n-2)     F(n-1)      F(n)
                                        ●----------●----------○
                                        prev2      prev1      curr
            After computing F(n)
                                        F(n-1)      F(n)       F(n+1)
                                        ●----------●----------○
                                        prev2      prev1     curr(next)

            hence we update as such, prev1 becomes prev2, curr becomes prev1
            when i=n+1, we have prev1 storing fib(n)

        TC=O(n), SC=O(1)
    */

    return 0;
}