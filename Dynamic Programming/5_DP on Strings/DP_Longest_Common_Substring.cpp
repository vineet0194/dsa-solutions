/*
Problem: Longest Common Substring
Link: https://www.geeksforgeeks.org/problems/longest-common-substring1452/1
Difficulty: Medium
Approach: DP
Time Complexity: O(n*m)
Note:
    
*/

// DP Tabulation, Space Complexity: O(n*m)

class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));

        for (int i=0; i<n+1; i++)
            dp[i][m] = 0;

        for (int i=0; i<m+1; i++)
            dp[n][i] = 0;
        
        int ans = 0;
        for (int i=n-1; i>=0; i--){
            for (int j=m-1; j>=0; j--){
                if (s1[i]==s2[j]){
                    int next = 1 + dp[i+1][j+1];
                    dp[i][j] = next;
                    if (ans < next)
                        ans = next;
                }
                else
                    dp[i][j] = 0;
            }
        }

        return ans;
    }
};