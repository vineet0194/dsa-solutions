/*
Problem: Ninja’s Training
Link: https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM
Difficulty: Medium
Approach: DP
Time Complexity: O(n)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(2n)

int solve(int i, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    if (i == points.size())
        return 0;

    if (dp[i][last] != -1){
        return dp[i][last];
    }

    for (int j=0; j<3; j++){
        if (j == last)
            continue;
        dp[i][last] = max(dp[i][last], points[i][j] + solve(i+1, j, points, dp));
    }

    return dp[i][last];
}

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solve(0, 3, points, dp);
}

// DP Tabulation, Space Complexity: O(n)

int ninjaTraining(int n, vector<vector<int>> &points){
    vector<vector<int>> dp(n, vector<int>(4, -1));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(max(points[0][0], points[0][1]), points[0][2]);

    for (int i=1; i<n; i++){
        for (int j=0; j<4; j++){
            for (int k=0; k<3; k++){
                if (k==j)
                    continue;
                dp[i][j] = max(dp[i][j], points[i][k] + dp[i-1][k]);
            }

        }
    }

    return dp[n-1][3];
}