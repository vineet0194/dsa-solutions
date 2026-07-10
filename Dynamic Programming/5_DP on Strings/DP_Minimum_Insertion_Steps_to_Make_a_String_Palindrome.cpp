/*
Problem: 1312. Minimum Insertion Steps to Make a String Palindrome
Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/submissions/2063269160/
Difficulty: Hard
Approach: DP
Time Complexity: O(n^2)
Note:
    
*/

// Recursive Memoization, Space Complexity: O(n^2 + n)

class Solution {
public:
    int solve(int i, int j, string& text1, string& text2, vector<vector<int>>& dp){
        if (i == text1.size() || j == text2.size())
            return 0;
        
        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j])
            return dp[i][j] = 1 + solve(i+1, j+1, text1, text2, dp);

        int incI = solve(i+1, j, text1, text2, dp);
        int incJ = solve(i, j+1, text1, text2, dp);

        return dp[i][j] = max(incI, incJ);
    }
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        if (s2==s) return 0;

        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return s.size() - solve(0, 0, s, s2, dp);
    }
};

// DP Tabulation, Space Complexity: O(n^2)

class Solution {
public:
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());

        if (s2==s) return 0;

        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

        for (int i=0; i<n+1; i++){
            dp[i][n] = 0;
            dp[n][i] = 0;
        }
        
        for (int i=n-1; i>=0; i--){
            for (int j=n-1; j>=0; j--){
                if (s[i] == s2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                    continue;
                }

                int incI = dp[i+1][j];
                int incJ = dp[i][j+1];

                dp[i][j] = max(incI, incJ);
            }
        }

        return n-dp[0][0];
    }
};