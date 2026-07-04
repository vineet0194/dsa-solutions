/*
Problem: Minimum Operations to Transform Binary String
Link: https://leetcode.com/contest/biweekly-contest-186/problems/minimum-operations-to-transform-binary-string/description/
Difficulty: Medium
Approach: DP
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        const int INF = 1e9;

        vector<vector<int>> dp(n + 1, vector<int>(2, INF));
        dp[n][0]=dp[n][1]=0;

        for (int i=n-1; i>=0; i--){
            int target = s2[i] - '0';

            for (int cur = 0; cur <= 1; cur++){
                if (cur == target || (cur == 0 && target == 1)){
                    int cost = (cur == 0 && target == 1);
                    if (i == n - 1)
                        dp[i][cur] = min(dp[i][cur], cost);
                    else
                        dp[i][cur] = min(dp[i][cur],
                         cost + dp[i + 1][s1[i + 1] - '0']);
                }

                if (i < n - 1){
                    int cost = 1;
                    if (cur == 0) cost++;
                    if (s1[i + 1] == '0') cost++;
                    if (target == 1) cost++;

                    dp[i][cur] = min(dp[i][cur],
                                     cost + dp[i + 1][0]);
                }
            }
        }

        int ans = dp[0][s1[0] - '0'];
        return (ans >= INF ? -1 : ans);
    }
};